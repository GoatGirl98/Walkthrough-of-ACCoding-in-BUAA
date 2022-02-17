#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
namespace FastIO
{
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline char nc() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++; }
    int rd()
    {
        int ret = 0;
        char ch = nc();
 
        while (ch < '0' || ch > '9')
            ch = nc();
 
        while (ch >= '0' && ch <= '9')
        {
            ret = (ret << 1) + (ret << 3) + (ch ^ 48);
            ch = nc();
        }
 
        return ret;
    }
    char Buf[1 << 21], out[20];
    int P, out_size;
    void flush() { fwrite(Buf, 1, out_size, stdout), out_size = 0; }
    void wt(ll x)
    {
        if (out_size >= 1 << 20)
            flush();
 
        if (x < 0)
            Buf[out_size++] = 45, x = -x;
 
        do
            out[++P] = (x % 10) ^ 48;
        while (x /= 10);
 
        do
            Buf[out_size++] = out[P];
        while (--P);
        Buf[out_size++] = '\n';
    }
    struct IOFlush
    {
        ~IOFlush() { flush(); }
    } tail;
}
using namespace FastIO;
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
    void mul(int a[], int n, int b[], int m, ll res[])
    {
        if (multiple_case)
            memset(res, 0, sizeof(ll) * (n + m + 1));
        // brute force
        if (n < 100 / (m + 1) || n < 3 || m < 3)
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= m; ++j)
                    res[i + j] += 1ll * a[i] * b[j];
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
                res[i] = (ll)(com_a[i].a + 0.5);
        }
    }
}
const int maxn = 100010;
int T, n, m;
int a[maxn], num[maxn], x;
ll sum[maxn << 1], res_len;
int main()
{
    T = rd();
    while (T--)
    {
        n = rd(), m = rd();
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; ++i)
            a[i] = rd(), ++num[a[i]];
        // FFT 用于计算 2 数加和为x的取值数(区分顺序+允许取相同两个)
        FFT_Solver::mul(num, 100000, num, 100000, sum);
        // 减去取相同两个的
        for (int i = 0; i < n; ++i)
            sum[a[i] << 1]--;
        // 由于选择无序，所以要除以2
        for (int i = 0; i <= 200000; ++i)
            sum[i] >>= 1;
        for (int i = 1; i <= 200000; ++i)
            sum[i] += sum[i - 1];
        while (m--)
            x = rd(), wt(sum[x - 1]);
    }
}