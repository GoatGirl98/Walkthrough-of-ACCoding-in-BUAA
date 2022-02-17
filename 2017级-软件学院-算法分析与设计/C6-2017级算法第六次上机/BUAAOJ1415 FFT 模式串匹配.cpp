#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct fastIO
{
    static const int BUFF_SZ = 1 << 18;
    char inbuf[BUFF_SZ], outbuf[BUFF_SZ];
    fastIO()
    {
        setvbuf(stdin, inbuf, _IOFBF, BUFF_SZ);
        setvbuf(stdout, outbuf, _IOFBF, BUFF_SZ);
    }
} IO;
// FFT Solver : use for multiple case
namespace FFT_Solver
{
    struct complex
    {
        double a, b; // a : real number b : imaginary number
        double len() const { return a * a + b * b; }
        complex operator+(const complex &o) const { return {a + o.a, b + o.b}; }
        complex operator-(const complex &o) const { return {a - o.a, b - o.b}; }
        complex operator-() const { return {-a, -b}; }
        complex operator*(const complex &o) const { return {a * o.a - b * o.b, b * o.a + a * o.b}; }
        complex operator/(const double &o) const { return {a / o, b / o}; }
        complex operator!() const { return {a, -b}; } // conjugate
        complex operator/(const complex &o) const { return ((*this) * (!o)) / o.len(); }
    };
    const int N = (1 << 18) | 3;
    const bool multiple_case = 1;
    const double PI = acos(-1.0);
    bool initialized;
    int L, brev[N]; // Butterfly operation
    complex w[N], v[N];
    complex com_a[N], com_b[N];
    void init(int _L)
    {
        L = _L, initialized = 1;
        for (int i = 0; i < (1 << L); ++i)
            brev[i] = (brev[i >> 1] >> 1) | ((i & 1) << (L - 1));
        for (int i = 0; i < (1 << L); ++i)
        {
            w[i] = {cos(i * PI * 2 / (1 << L)), sin(i * PI * 2 / (1 << L))};
            v[i] = {cos(i * PI * 2 / (1 << L)), -sin(i * PI * 2 / (1 << L))};
        }
    }

    struct initializer
    {
        // length is adjustable
        initializer() { init(18); }
    }fft_init;

    void fft(complex a[], int lgn, int flag)
    {
        int n = 1 << lgn;
        for (int i = 0; i < n; ++i)
        {
            int rv = brev[i] >> (L - lgn);
            if (rv < i)
                swap(a[rv], a[i]);
        }

        int fa = L;
        complex *q = (flag == 1) ? w : v;

        for (int t = 1; t < n; t <<= 1)
        {
            --fa;

            for (int i = 0; i < n; i += t << 1)
            {
                complex *p = a + i;

                for (int j = 0; j < t; ++j)
                {
                    complex x = p[j + t] * q[j << fa];
                    p[j + t] = p[j] - x, p[j] = p[j] + x;
                }
            }
        }

        if (flag == -1)
            for (int i = 0; i < n; ++i)
                a[i] = {a[i].a / n, a[i].b / n};
    }

    void fft_two_seq(complex a[], complex b[], int lgn, int flag)
    {
        int n = 1 << lgn;

        for (int i = 0; i < n; ++i)
            a[i].b = b[i].a;

        fft(a, lgn, flag);

        b[0] = !a[0];

        for (int i = 1; i < n; ++i)
            b[i] = !a[n - i];

        for (int i = 0; i < n; ++i)
        {
            complex x = a[i], y = b[i];
            a[i] = {(x.a + y.a) / 2.0, (x.b + y.b) / 2.0};
            b[i] = (x - y) / (complex){0, 2};
        }
    }

    // a[0...n] * b[0...m] (assume that res is all zero)
    void mul(int a[], int n, int b[], int m, int res[])
    {
        if (multiple_case)
            memset(res, 0, sizeof(int) * (n + m + 1));
        // brute force
        if (n < 100 / (m + 1) || n < 3 || m < 3)
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= m; ++j)
                    res[i + j] += a[i] * b[j];
        // FFT
        else
        {
            assert(initialized);
            int lgk = 0, k = 1, len = n + m;
            while ((1 << lgk) <= len)
                ++lgk, k <<= 1;
            for (int i = 0; i <= n; ++i)
                com_a[i].a = a[i], com_a[i].b = 0.0;
            for (int i = 0; i <= m; ++i)
                com_b[i].a = b[i], com_b[i].b = 0.0;
            if (multiple_case)
            {
                memset(com_a + (n + 1), 0, sizeof(complex) * (k - n - 1));
                memset(com_b + (m + 1), 0, sizeof(complex) * (k - m - 1));
            }
            fft_two_seq(com_a, com_b, lgk, 1);
            for (int i = 0; i < k; ++i)
                com_a[i] = com_a[i] * com_b[i];
            fft(com_a, lgk, -1);
            for (int i = 0; i <= n + m; ++i)
                res[i] = (int)(com_a[i].a + 0.5);
        }
    }
}
const int maxn = 100010;
int n, m, ans;
char A[maxn], B[maxn];
int a[maxn], b[maxn], res[maxn << 1];
int real_res[maxn << 1];
void solve(char target_A, char target_B)
{
    for (int i = 0; i < n; ++i)
        a[i] = (A[i] == target_A);
    for (int i = 0; i < m; ++i)
        b[m - 1 - i] = (B[i] == target_B);
    FFT_Solver::mul(a, n - 1, b, m - 1, res);
    for (int i = m - 1; i < n + m - 1; ++i)
        real_res[i - (m - 1)] += res[i];
}
int main()
{
    scanf("%d%d%s%s", &n, &m, A, B);
    solve('S', 'R'), solve('P', 'S'), solve('R', 'P');
    for (int i = 0; i < n; ++i)
        ans = max(ans, real_res[i]);
    printf("%d", ans);
}