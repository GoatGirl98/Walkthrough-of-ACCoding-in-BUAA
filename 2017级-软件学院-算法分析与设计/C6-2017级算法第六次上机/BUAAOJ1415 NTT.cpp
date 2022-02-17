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
// NTT Solver : use for multiple case : n | (p - 1)
// primitive root : 3 
// 998244353  (2^23 * 7 * 17 + 1)
// 1004535809 (2^21 * 479 + 1)
// 1007681537 (2^20 * 31^2 + 1)
// 1045430273 (2^20 * 997 + 1)
namespace NTT_Solver
{
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
    const int N = (1 << 18) | 3;
    const int mod = 998244353, proot = 3, inv_proot = qpow(proot, mod - 2, mod);
    bool initialized;
    int L, brev[N]; // Butterfly operation
    int w[N], v[N];
    void init(int _L)
    {
        L = _L;
        initialized = 1;
        assert(!((mod - 1) % (1 << L)));
        for (int i = 0; i < (1 << L); ++i)
            brev[i] = (brev[i >> 1] >> 1) | ((i & 1) << (L - 1));
        // for (int i = 0; i < (1 << L); ++i)
        w[0] = v[0] = 1;
        w[1] = qpow(proot, (mod - 1) / (1 << L), mod);
        v[1] = qpow(inv_proot, (mod - 1) / (1 << L), mod);
        for (int i = 2; i < (1 << L); ++i)
        {
            w[i] = (1ll * w[i - 1] * w[1]) % mod;
            v[i] = (1ll * v[i - 1] * v[1]) % mod;
        }
    }
    struct initializer
    {
        // length is adjustable
        initializer() { init(18); }
    } ntt_init;
    void ntt(int a[], int lgn, int flag)
    {
        int n = 1 << lgn;
        for (int i = 0; i < n; ++i)
        {
            int rv = brev[i] >> (L - lgn);
            if (rv < i)
                swap(a[rv], a[i]);
        }
        int fa = L;
        int *q = (flag == 1) ? w : v;
        for (int t = 1; t < n; t <<= 1)
        {
            --fa;
            for (int i = 0; i < n; i += (t << 1))
            {
                int *p = a + i;
                for (int j = 0; j < t; ++j)
                {
                    int x = (1ll * p[j + t] * q[j << fa]) % mod;
                    p[j + t] = sub(p[j], x, mod), p[j] = add(p[j], x, mod);
                }
            }
        }

        if (flag == -1)
        {
            int inv_n = qpow(n, mod - 2, mod);
            for (int i = 0; i < n; ++i)
                a[i] = (1ll * a[i] * inv_n) % mod;
        }
    }
    // a[0...n] * b[0...m] (assume that res is all zero)
    // a is res in specific NTT
    void mul(int a[], int n, int b[], int m)
    {
        // multiple case

        // brute force
        if (n < 100 / (m + 1) || n < 3 || m < 3)
        {
            int *res = new int[n + m + 1];
            memset(res, 0, sizeof(a[0]) * (n + m + 1));
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= m; ++j)
                    res[i + j] = add(res[i + j], (1ll * a[i] * b[j]) % mod, mod);
            memcpy(a, res, sizeof(res[0]) * (n + m + 1));
            delete res;
        }
        // NTT
        else
        {
            assert(initialized);
            int lgk = 0, k = 1, len = n + m;
            while ((1 << lgk) <= len)
                ++lgk, k <<= 1;
            // multiple_case
            memset(a + (n + 1), 0, sizeof(a[0]) * (k - n - 1));
            memset(b + (m + 1), 0, sizeof(b[0]) * (k - m - 1));

            ntt(a, lgk, 1), ntt(b, lgk, 1);
            for (int i = 0; i < k; ++i)
                a[i] = (1ll * a[i] * b[i]) % mod;
            ntt(a, lgk, -1);
        }
    }
}
const int maxn = (1 << 18) + 10;
int n, m, ans;
char A[maxn], B[maxn];
int a[maxn], b[maxn];
int real_res[maxn];
void solve(char target_A, char target_B)
{
    for (int i = 0; i < n; ++i)
        a[i] = (A[i] == target_A);
    for (int i = 0; i < m; ++i)
        b[m - 1 - i] = (B[i] == target_B);
    NTT_Solver::mul(a, n - 1, b, m - 1);
    for (int i = m - 1; i < n + m - 1; ++i)
        real_res[i - (m - 1)] += a[i];
}
int main()
{
    scanf("%d%d%s%s", &n, &m, A, B);
    solve('S', 'R'), solve('P', 'S'), solve('R', 'P');
    for (int i = 0; i < n; ++i)
        ans = max(ans, real_res[i]);
    printf("%d", ans);
}

