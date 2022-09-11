#include <stdio.h>
#include <string.h>
#define maxn 100015
typedef long long ll;
typedef __int128 lll;
ll divisor[maxn], remainder[maxn];
ll divisor_lcm;
int n;
ll gcd(ll a, ll b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int r = 0;
    while (!((a & 1) || (b & 1)))
        a >>= 1, b >>= 1, r++;
    ll ret = 0;
    while (1)
    {
        while (!(a & 1))
            a >>= 1;
        while (!(b & 1))
            b >>= 1;
        if (a > b)
            a = a - b;
        else
            b = b - a;
        if (0 == a)
        {
            ret = b << r;
            break;
        }
        if (0 == b)
        {
            ret = a << r;
            break;
        }
    }
    return ret;
}
ll lcm(ll a, ll b)
{
    return (lll)a * (lll)b / gcd(a, b);
}
ll AmulBmodP(ll a, ll b, ll p)
{
    return (lll)a * (lll)b % (lll)p;
}
ll exgcd(ll a, ll b, ll *x, ll *y)
{
    if (!b)
    {
        (*x) = 1, (*y) = 0;
        return a;
    }
    ll q = exgcd(b, a % b, y, x);
    (*y) -= a / b * (*x);
    return q;
}
ll EXCRT()
{
    ll x, y, k, M = divisor[1], ans = remainder[1];
    for (int i = 2; i <= n; i++)
    {
        ll c = (remainder[i] - ans % divisor[i] + divisor[i]) % divisor[i];
        ll t = exgcd(M, divisor[i], &x, &y), bg = divisor[i] / t;
        if (c % t)
            return -1;
        x = AmulBmodP(x, c / t, bg);
        ans += x * M;
        M *= bg;
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}
int main()
{
    n = 3;
    divisor_lcm = 1;
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", divisor + i, remainder + i), divisor_lcm = lcm(divisor_lcm, divisor[i]);
    ll ans = EXCRT();
    printf("%lld\n", ans + (ans == 1 ? divisor_lcm : 0));
}
