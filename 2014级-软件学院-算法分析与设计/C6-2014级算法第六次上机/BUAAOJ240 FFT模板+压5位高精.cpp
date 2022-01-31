#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t lll;
namespace FFT_Solver
{
    struct complex
    {
        double a, b; // a : real number b : imaginary number
        double len() const { return a * a + b * b; }
        complex operator+(const complex &o) const { return {a + o.a, b + o.b}; }
        complex operator-(const complex &o) const { return {a - o.a, b - o.b}; }
        complex operator-() const { return {-a, -b}; }
        complex operator*(const double &o) const { return {a * o, b * o}; }
        complex operator*(const complex &o) const { return {a * o.a - b * o.b, b * o.a + a * o.b}; }
        complex operator/(const double &o) const { return {a / o, b / o}; }
        complex operator!() const { return {a, -b}; } // conjugate
        complex operator/(const complex &o) const { return ((*this) * (!o)) / o.len(); }
    };
    const int N = (1 << 12) | 3;
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
        initializer() { init(12); }
    }fft_init;
 
    void fft(complex a[], int lgn, int flag)
    {
        int n = 1 << lgn;
        for (int i = 0; i < n; ++i)
        {
            int rv = brev[i] >> (L - lgn);
            if (rv < i)
            {
                // std::swap(a[rv], a[i]);
                complex tmp = a[rv];
                a[rv] = a[i], a[i] = tmp;
            }
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
    void mul(int a[], int n, int b[], int m, int res[], int mod, int *res_len)
    {
        // multiple case
        assert((*res_len) >= n + m + 1);
        memset(res, 0, sizeof(res[0]) * (*res_len));
 
        // brute force
        if (n < 100 / (m + 1) || n < 3 || m < 3)
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= m; ++j)
                {
                    // res[i + j] += a[i] * b[j];
                    ll x = 1ll * res[i + j] + (1ll * a[i] * b[j]);
                    res[i + j] = 0;
                    int offset = 0;
                    while (x >= mod)
                        res[i + j + offset] += (x % mod), x /= mod, ++offset;
                    res[i + j + offset] += x;                   
                }   
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
            // multiple_case
            memset(com_a + (n + 1), 0, sizeof(com_a[0]) * (k - n - 1));
            memset(com_b + (m + 1), 0, sizeof(com_b[0]) * (k - m - 1));
 
            fft_two_seq(com_a, com_b, lgk, 1);
            for (int i = 0; i < k; ++i)
                com_a[i] = com_a[i] * com_b[i];
            fft(com_a, lgk, -1);
            for (int i = 0; i <= n + m; ++i)
            {
                ll x = 1ll * res[i] + (ll)(com_a[i].a + 0.5);
                res[i] = 0;
                int offset = 0;
                while (x >= mod)
                    res[i + offset] += (x % mod), x /= mod, ++offset;
                res[i + offset] += x;
                // res[i] = (ll)(com_a[i].a + 0.5);
            }
        }
        // adjust by mod
        (*res_len) = n + m + 1;
        while (res[(*res_len)])
            ++(*res_len);
        while (res[(*res_len) - 1] >= mod)
            res[(*res_len)] = res[(*res_len) - 1] / mod, res[(*res_len) - 1] %= mod, ++(*res_len);
        while ((*res_len) && (!res[(*res_len) - 1]))
            --(*res_len);
    }
}
 
 
// base radix : 10
struct BigNumber
{
    const int digit[6] = {1, 8, 64, 512, 4096, 32768}, MODD = 5;
    static const int MOD = 32768, base_radix = 8;
 
    int len;
    bool f;
    int *a;
    BigNumber() { a = NULL; }

    BigNumber(const char *s)
    {
        int slen = strlen(s);
        a = new int[slen / MODD + 2];
        len = 0, f = true;
        int start = 0;
        if (s[0] == '+')
            start = 1;
        else if (s[0] == '-')
            start = 1, f = false;
        int sum = 0, k = 0;
        for (int i = slen - 1; i >= start; i--)
        {
            sum += (s[i] ^ '0') * digit[k++];
            if (k == MODD)
                a[len++] = sum, sum = 0, k = 0;
        }
        if (sum > 0)
            a[len++] = sum;
        if (len == 0)
            len = 1, a[0] = 0, f = true;
    }

    BigNumber(const BigNumber &p)
    {
        len = p.len, f = p.f, a = new int[len];
        memcpy(a, p.a, len * sizeof(int));
    }

    void operator=(const BigNumber &p)
    {
        if (a != NULL)
            delete a;
        len = p.len, f = p.f;
        a = new int[len];
        memcpy(a, p.a, len * sizeof(int));
    }
 
    BigNumber operator*(const BigNumber &p) const
    {
        if ((this->len == 1 && this->a[0] == 0) || (p.len == 1 && p.a[0] == 0))
            return BigNumber((lll)0);
        BigNumber ret;
        ret.f = !(f ^ p.f);
        ret.len = len + p.len + 5;
        ret.a = new int[ret.len];
        FFT_Solver::mul(a, len - 1, p.a, p.len - 1, ret.a, MOD, &ret.len);
        return ret;
    }

    void output() const
    {
        char *ch = new char[20500];
        int print_len = 0, is_neg = 0;
        if (!f && (len > 1 || a[0] != 0))
            ch[print_len++] = '-', is_neg = 1;
        int x = a[len - 1];
        while (x)
            ch[print_len++] = (x % base_radix) ^ '0', x /= base_radix;
        for (int i = is_neg; i < print_len + is_neg - 1 - i; i++)
            // std::swap(ch[i], ch[print_len + is_neg - 1 - i]);
            ch[i] ^= ch[print_len + is_neg - 1 - i], ch[print_len + is_neg - 1 - i] ^= ch[i], ch[i] ^= ch[print_len + is_neg - 1 - i];
        for (int i = len - 2; i >= 0; i--)
        {
            x = a[i];
            int k = MODD - 1;
            while (x)
                ch[print_len + k] = (x % base_radix) ^ '0', x /= base_radix, k--;
            while (k >= 0)
                ch[print_len + k] = '0', k--;
            print_len += MODD;
        }
        if (print_len == 0)
            ch[print_len++] = '0';
        ch[print_len] = '\0';
        // printf("%s", ch);
        puts(ch);
        delete ch;
    }    
    ~BigNumber() { delete a; }
};
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
char A[10010], B[10010];
BigNumber a, b;
int main()
{
    while (~scanf("%s%s", A, B))
        a = BigNumber(A), b = BigNumber(B), (a * b).output();
}