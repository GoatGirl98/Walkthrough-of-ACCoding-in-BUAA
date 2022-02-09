#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
typedef long long ll;
typedef __int128_t lll;
// NTT Solver : use for multiple case : n | (p - 1)
// primitive root : 3
// 998244353  (2^23 * 7 * 17 + 1)
// 1004535809 (2^21 * 479 + 1)
// 1007681537 (2^20 * 31^2 + 1)
// 1045430273 (2^20 * 997 + 1)
namespace Arbitrary_NTT_Solver
{
    // int arbitrary_mod;
    inline int add(int a, int b, int p) { return (a + b >= p) ? (a + b - p) : (a + b); }
    inline int sub(int a, int b, int p) { return (a < b) ? (a - b + p) : (a - b); }
    inline int qpow(int a, int b, int p)
    {
        int ret = 1;
        while (b)
        {
            if (b & 1)
                ret = (1ll * ret * a) % p;
            b >>= 1;
            a = (1ll * a * a) % p;
        }
        return ret;
    }
    const int N = (1 << 11) | 3;
    // modulo 3
    const int M[3] = {1004535809, 1007681537, 1045430273}, proot = 3;
    const lll all_mod = (lll)1004535809 * (lll)1007681537 * (lll)1045430273;
    const lll MP[3] = {all_mod + (lll)1053460784322969601ll * (lll)(-480795620), all_mod + (lll)1050172145041145857ll * (lll)(-401215089), all_mod + (lll)1012252187984658433ll * (lll)(-128816555)};
    struct MOD3
    {
        int reminder[3];
        // assume val is lesser than mod
        void init(ll val)
        {
            for (int i = 0; i < 3; ++i)
                reminder[i] = (val < M[i]) ? val : (val % M[i]);
        }
        MOD3 inv() const
        {
            MOD3 ret;
            for (int i = 0; i < 3; ++i)
                ret.reminder[i] = qpow(reminder[i], M[i] - 2, M[i]);
            return ret;
        }
        MOD3 operator+(const MOD3 &o) const
        {
            MOD3 ret;
            for (int i = 0; i < 3; ++i)
                ret.reminder[i] = add(reminder[i], o.reminder[i], M[i]);
            return ret;
        }
        MOD3 operator-(const MOD3 &o) const
        {
            MOD3 ret;
            for (int i = 0; i < 3; ++i)
                ret.reminder[i] = sub(reminder[i], o.reminder[i], M[i]);
            return ret;
        }
        MOD3 operator*(const MOD3 &o) const
        {
            MOD3 ret;
            for (int i = 0; i < 3; ++i)
                ret.reminder[i] = (1ll * reminder[i] * o.reminder[i]) % M[i];
            return ret;
        }
        lll val() const
        {
            lll ret = 0;
            for (int i = 0; i < 3; ++i)
                ret = (ret + MP[i] * reminder[i]) % all_mod;
            return ret;
        }
    };

    bool initialized;
    int L, brev[N]; // Butterfly operation
    MOD3 w[N], v[N], mod_a[N], mod_b[N];
    void init(int _L)
    {
        L = _L;
        initialized = 1;
        for (int i = 0; i < 3; ++i)
            assert(!((M[i] - 1) & ((1 << L) - 1)));
        for (int i = 0; i < (1 << L); ++i)
            brev[i] = (brev[i >> 1] >> 1) | ((i & 1) << (L - 1));
        w[0].init(1), v[0].init(1);
        for (int i = 0; i < 3; ++i)
            w[1].reminder[i] = qpow(proot, (M[i] - 1) >> L, M[i]);
        v[1] = w[1].inv();
        for (int i = 2; i < (1 << L); ++i)
            w[i] = w[i - 1] * w[1], v[i] = v[i - 1] * v[1];
    }
    struct initializer
    {
        // length is adjustable
        initializer() { init(11); }
    } arbitrary_ntt_init;
    void arbitrary_ntt(MOD3 a[], int lgn, int flag)
    {
        int n = 1 << lgn;
        for (int i = 0; i < n; ++i)
        {
            int rv = brev[i] >> (L - lgn);
            if (rv < i)
            {
                MOD3 tmp = a[rv];
                a[rv] = a[i], a[i] = tmp;
            }
        }
        int fa = L;
        MOD3 *q = (flag == 1) ? w : v;
        for (int t = 1; t < n; t <<= 1)
        {
            --fa;
            for (int i = 0; i < n; i += (t << 1))
            {
                MOD3 *p = a + i;
                for (int j = 0; j < t; ++j)
                {
                    MOD3 x = p[j + t] * q[j << fa];
                    p[j + t] = p[j] - x, p[j] = p[j] + x;
                }
            }
        }

        if (flag == -1)
        {
            MOD3 inv_n;
            inv_n.init(n), inv_n = inv_n.inv();
            for (int i = 0; i < n; ++i)
                a[i] = a[i] * inv_n;
        }
    }
    void mul(ll a[], int n, ll b[], int m, ll res[], ll mod, int *res_len)
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
                    lll x = (lll)res[i + j] + (lll)a[i] * (lll)b[j];
                    res[i + j] = 0;
                    int offset = 0;
                    while (x >= mod)
                        res[i + j + offset] += (x % mod), x /= mod, ++offset;
                    res[i + j + offset] += x;
                }
        // Arbitrary NTT
        else
        {
            assert(initialized);
            int lgk = 0, k = 1, len = n + m;
            while ((1 << lgk) <= len)
                ++lgk, k <<= 1;
            for (int i = 0; i <= n; ++i)
                mod_a[i].init(a[i]);
            for (int i = 0; i <= m; ++i)
                mod_b[i].init(b[i]);
            // multiple_case
            memset(mod_a + (n + 1), 0, sizeof(MOD3) * (k - n - 1));
            memset(mod_b + (m + 1), 0, sizeof(MOD3) * (k - m - 1));

            arbitrary_ntt(mod_a, lgk, 1), arbitrary_ntt(mod_b, lgk, 1);
            for (int i = 0; i < k; ++i)
                mod_a[i] = mod_a[i] * mod_b[i];
            arbitrary_ntt(mod_a, lgk, -1);
            for (int i = 0; i <= n + m; ++i)
            {
                lll x = (lll)res[i] + mod_a[i].val();
                res[i] = 0;
                int offset = 0;
                while (x >= mod)
                    res[i + offset] += (x % mod), x /= mod, ++offset;
                res[i + offset] += x;
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
// base radix : 8
struct BigNumber
{
    const ll digit[13] = {1ll, 8ll, 64ll, 512ll, 4096ll, 32768ll, 262144ll, 2097152ll, 16777216ll, 134217728ll, 1073741824ll, 8589934592ll, 68719476736ll}, MODD = 12;
    static const ll MOD = 68719476736ll, base_radix = 8;

    int len;
    bool f;
    ll *a;
    BigNumber() { a = NULL; }

    BigNumber(const char *s)
    {
        int slen = strlen(s);
        a = new ll[slen / MODD + 2];
        len = 0, f = true;
        int start = 0;
        if (s[0] == '+')
            start = 1;
        else if (s[0] == '-')
            start = 1, f = false;
        ll sum = 0, k = 0;
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
        len = p.len, f = p.f, a = new ll[len];
        memcpy(a, p.a, len * sizeof(ll));
    }

    void operator=(const BigNumber &p)
    {
        if (a != NULL)
            delete a;
        len = p.len, f = p.f;
        a = new ll[len];
        memcpy(a, p.a, len * sizeof(ll));
    }

    BigNumber operator*(const BigNumber &p) const
    {
        if ((this->len == 1 && this->a[0] == 0) || (p.len == 1 && p.a[0] == 0))
            return BigNumber("0");
        BigNumber ret;
        ret.f = !(f ^ p.f);
        ret.len = len + p.len + 5;
        ret.a = new ll[ret.len];
        Arbitrary_NTT_Solver::mul(a, len - 1, p.a, p.len - 1, ret.a, MOD, &ret.len);
        return ret;
    }

    void output() const
    {
        char *ch = new char[20500];
        int print_len = 0, is_neg = 0;
        if (!f && (len > 1 || a[0] != 0))
            ch[print_len++] = '-', is_neg = 1;
        ll x = a[len - 1];
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