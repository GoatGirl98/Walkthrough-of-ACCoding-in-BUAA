#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
typedef long long ll;
typedef __int128_t lll;
struct fastIO
{
    static const int BUFF_SZ = 1 << 18;
    char inbuf[BUFF_SZ], outbuf[BUFF_SZ];
    fastIO()
    {
        setvbuf(stdin, inbuf, _IOFBF, BUFF_SZ);
        setvbuf(stdout, outbuf, _IOFBF, BUFF_SZ);
    }
}; // IO;
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
    const int N = (1 << 17) | 3;
    // modulo 3
    const int M[3] = {1004535809, 1007681537, 1045430273}, proot = 3;
    const lll all_mod = (lll)1004535809 * (lll)1007681537 * (lll)1045430273;
    const lll MP[3] = {all_mod + (lll)1053460784322969601ll * (lll)(-480795620), all_mod + (lll)1050172145041145857ll * (lll)(-401215089), all_mod + (lll)1012252187984658433ll * (lll)(-128816555)};
    struct MOD3
    {
        int reminder[3];
        // assume val is lesser than mod
        void init(int val) { reminder[0] = reminder[1] = reminder[2] = val; }
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
        initializer() { init(17); }
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
int char_to_num[256], num_to_char[256];
struct sheet_initializer
{
    sheet_initializer()
    {
        for (int i = 0; i < 10; i++)
            char_to_num['0' + i] = i;

        for (int i = 10; i < 36; i++)
            num_to_char[i - 10 + 1] = 'A' + i - 10;

    }
} char_init;
// Arbitrary radix from 2 to 62
struct BigNumber
{
    static const int MODD = 5;
    int digit[6], MOD, base_radix; // arbitrary
    int *a;
    int len;
    bool f;
    void init(int _base)
    {
        assert(_base >= 2 && _base <= 62);
        base_radix = _base;
        digit[0] = 1;
        for (int i = 1; i <= MODD; ++i)
            digit[i] = digit[i - 1] * base_radix;
        MOD = digit[MODD];
    }
    BigNumber() { a = new int[1], a[0] = 0, f = 1, len = 1, init(10); }
    BigNumber(int x, int _base)
    {
        init(_base);
        if (x == 0)
            len = 1, a = new int[1], a[0] = 0, f = 1;
        else
        {
            len = 0, f = 1;
            if (x < 0)
                f = 0, x = -x;
            a = new int[(int)(log(x) / log(MOD)) + 2];
            int sum = 0, k = 0;
            while (x)
            {
                sum += (x % base_radix) * digit[k++];
                if (k == MODD)
                    a[len++] = sum, sum = 0, k = 0;
                x /= base_radix;
            }
            if (sum > 0)
                a[len++] = sum;
        }
    }
    BigNumber(const char *s, int _base)
    {
        init(_base);
        int slen = strlen(s);
        a = new int[slen / MODD + 2];
        len = 0, f = true;
        int start = 0;
        if (s[0] == '+')
            start = 1;
        else if (s[0] == '-')
            start = 1, f = false;
        while (s[start] == '0')
            ++start;
        int sum = 0, k = 0;
        for (int i = slen - 1; i >= start; i--)
        {
            int real_num = char_to_num[(int)s[i]];
            assert(real_num < _base);
            sum += real_num * digit[k++];
            if (k == MODD)
                a[len++] = sum, sum = 0, k = 0;
        }
        if (sum > 0)
            a[len++] = sum;
        if (len == 0)
            len = 1, a[0] = 0, f = true;
    }
    
    BigNumber(const BigNumber &o)
    {
        init(o.base_radix);
        len = o.len, f = o.f, a = new int[len];
        memcpy(a, o.a, len * sizeof(o.a[0]));
    }
    void operator=(const BigNumber &p)
    {
        if (a != NULL)
            delete a;
        len = p.len, f = p.f;
        a = new int[len];
        memcpy(a, p.a, len * sizeof(int));
        init(p.base_radix);
    }
    ~BigNumber() { delete a; }
    // only for trans, so ignore diffrent positive and negative
    BigNumber operator+(const BigNumber &o) const
    {
        assert(!(f ^ o.f)), assert(!(MOD ^ o.MOD));
        BigNumber ret;
        ret.init(base_radix);
        ret.len = (len > o.len) ? (len + 1) : (o.len + 1);
        ret.a = new int[ret.len], ret.a[0] = 0;
        for (int i = 0; i < ret.len - 1; ++i)
        {
            ll x = 0;
            x += (i < len) ? a[i] : 0, x += (i < o.len) ? o.a[i] : 0, x += ret.a[i];
            ret.a[i] = x % MOD, ret.a[i + 1] = x / MOD;
        }
        while (ret.len > 1 && (!ret.a[ret.len - 1]))
            --ret.len;
        return ret;
    }
    BigNumber operator*(const BigNumber &o) const
    {
        assert(!(MOD ^ o.MOD));
        if ((this->len == 1 && this->a[0] == 0) || (o.len == 1 && o.a[0] == 0))
            return BigNumber(0, base_radix);
        BigNumber ret;
        ret.init(base_radix);
        ret.f = !(f ^ o.f);
        ret.len = len + o.len + 5;
        ret.a = new int[ret.len];
        Arbitrary_NTT_Solver::mul(a, len - 1, o.a, o.len - 1, ret.a, MOD, &ret.len);
        return ret;
    }

    BigNumber trans(int out_radix) const;

    void output() const
    {
        char *ch = new char[500500];
        int print_len = 0, is_neg = 0;
        if (!f && (len > 1 || a[0] != 0))
            ch[print_len++] = '-', is_neg = 1;
        int x = a[len - 1];
        while (x)
            ch[print_len++] = x % base_radix, x /= base_radix;
        for (int i = is_neg; i < print_len + is_neg - 1 - i; i++)
            ch[i] ^= ch[print_len + is_neg - 1 - i], ch[print_len + is_neg - 1 - i] ^= ch[i], ch[i] ^= ch[print_len + is_neg - 1 - i];
        for (int i = len - 2; i >= 0; i--)
        {
            x = a[i];
            int k = MODD - 1;
            while (x)
                ch[print_len + k] = x % base_radix, x /= base_radix, k--;
            while (k >= 0)
                ch[print_len + k] = 0, k--;
            print_len += MODD;
        }
        if (print_len == 0)
            ch[print_len++] = 0;
        ch[print_len] = '\0';
        for (int i = print_len - 1; ~i; --i)
            if (i && ch[i] <= 0)
                ch[i] += 26, --ch[i - 1];
        int st = 0;
        if (!ch[st])
            ++st;
        for (int i = st; i < print_len; ++i)
            ch[i] = num_to_char[ch[i]];
        puts(ch + st);
        delete ch;
    }
};
BigNumber f_gap[20], stack_bignum[20];
int stack_num[20];
BigNumber BigNumber::trans(int out_radix) const
{
    int n = len;
    int K = 1, k = 0;
    while (K < n)
        K <<= 1, ++k;
    // BigNumber* f_gap = new BigNumber[k + 1];
    // BigNumber f_gap[k + 1];
    f_gap[0] = BigNumber(MOD, out_radix);
    for (int i = 1; i <= k; ++i)
        f_gap[i] = f_gap[i - 1] * f_gap[i - 1];
    // BigNumber* stack_bignum = new BigNumber[k + 1];

    // int stack_num[k + 1];
    int top = 0;
    for (int i = 0; i < n; ++i)
    {
        int cur_num = a[i];
        BigNumber b = BigNumber(cur_num, out_radix);
        int level = 1;
        while (top && stack_num[top] == level)
            b = (b * f_gap[level - 1]) + stack_bignum[top--], ++level;
        stack_bignum[++top] = b, stack_num[top] = level;
    }
    BigNumber ret = stack_bignum[top];
    for (int i = top - 1; i; --i)
        ret = (ret * f_gap[stack_num[i] - 1]) + stack_bignum[i];

    ret.f = f;
    return ret;
}
int in_radix, out_radix;
char s[100010];
BigNumber a, b, c, d;
int t;
int main()
{

    while(~scanf("%s", s))
        a = BigNumber(s, 10), b = a.trans(26), b.output();
}