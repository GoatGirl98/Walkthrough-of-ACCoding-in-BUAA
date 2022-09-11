#include <stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define maxn 100000
const int mod = 1000000007;
int fac[maxn + 10], ifac[maxn + 10];
char eof_flag;
char rd(int *s)
{
    if (eof_flag)
        return 0;
    int k = 0, f = 1;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
    {
        if (c == EOF)
        {
            eof_flag = 1;
            return 0;
        }
        c = getchar();
    }
    f = (c == '-') ? -1 : 1;
    k = (c == '-') ? 0 : (c ^ 48);
    c = getchar();
    while (c >= '0' && c <= '9')
        k = (k << 1) + (k << 3) + (c ^ 48), c = getchar();
    if (c == EOF)
        eof_flag = 1;
    (*s) = f > 0 ? k : -k;
    return 1;
}
void wr(int x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
int C(int n, int m)
{
    if (m > n || m < 0)
        return 0;
    else
        return 1ll * fac[n] * (1ll * ifac[m] * ifac[n - m] % mod) % mod;
}
int inv(int a, int p)
{
    int _a = a, _b = p, u = 1, v = 0;
    while (_b)
    {
        int t = _a / _b;
        _a -= t * _b;
        if (_a ^ _b)
            _a ^= _b, _b ^= _a, _a ^= _b;
        u -= t * v;
        if (u ^ v)
            u ^= v, v ^= u, u ^= v;
    }
    u = 1ll * (u + p) % p;
    return u;
}
int solve(int a, int b, int k)
{
    if ((k - b) & 1)
        return 0;
    else
        return (1ll * C(k - 1, (k - b) >> 1) - 1ll * C(k - 1, (k + b) >> 1) - 1ll * C(k - 1, a - 1 + ((k + b) >> 1)) + 3ll * mod) % mod;
}
int a, b, k;
int main()
{
    fac[0] = 1;
    for(int i = 1; i <= maxn; ++i)
        fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = inv(fac[maxn], mod);
    for(int i = maxn - 1; i >= 0; --i)
        ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;

    while(rd(&a) && rd(&b) && rd(&k))
        wr(solve(a, b, k)), putchar('\n');
}
