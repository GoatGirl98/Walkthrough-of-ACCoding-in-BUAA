#include <stdio.h>
typedef long long ll;
ll ll_sqrt(ll x)
{
    if (x <= 1)
        return x;
    ll ret = x, rett = (ret + (x / ret)) >> 1;
    while (rett < ret)
    {
        ret = rett;
        rett = (ret + (x / ret)) >> 1;
    }
    return ret;
}
ll n;
ll solve(ll n)
{
    ll sum_1 = 0, sum_2 = ll_sqrt(n);
    for (ll i = 1; i <= sum_2; ++i)
        sum_1 += n / i;
    return (sum_1 << 1) - (sum_2 * sum_2);
}
int main()
{
    scanf("%lld", &n);
    printf("%lld", solve(n));
}