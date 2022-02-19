#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
using namespace std;
// scanf num(int), return num - revNum(num)
int rd(bool tuple = 1)
{
    int k = 0, f = 0;
    int frac = 1;
    char c = getchar();
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        f += (c ^ 48) * frac, frac = (frac << 1) + (frac << 3);
        c = getchar();
    }
    return tuple ? (k - f) : k;
}
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
        complex operator*(const double &o) const { return {a * o, b * o}; }
        complex operator/(const double &o) const { return {a / o, b / o}; }
        complex operator!() const { return {a, -b}; } // conjugate
        complex operator/(const complex &o) const { return ((*this) * (!o)) / o.len(); }
    };
    const int N = (1 << 13) | 3;
    const bool multiple_case = 1;
    const double PI = acos(-1.0);
    bool initialized;
    int L, brev[N]; // Butterfly operation
    complex w[N], v[N];
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
        initializer() { init(13); }
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
}
using namespace FFT_Solver;
// A : single one B : coincide 2 C : coincide 3
complex a[N], b[N], c[N], ans[N];
int n, x;
int lim, k, lgk;
int main()
{
    n = rd(0);
    while (n--)
    {
        x = rd() + 1000;
        lim = max(lim, (x << 1) + x);
        a[x].a += 1.0, b[x << 1].a += 1.0, c[(x << 1) + x].a += 1.0;
    }
    k = 1, lgk = 0;
    while (k <= lim)
        ++lgk, k <<= 1;
    fft(a, lgk, 1), fft(b, lgk, 1), fft(c, lgk, 1);
    for (int i = 0; i < k; ++i)
        ans[i] = (a[i] * a[i] * a[i] - a[i] * b[i] * 3 + c[i] * 2) / 6.0;
    fft(ans, lgk, -1);
    printf("%d", (int)(ans[3000].a + 0.5));
}