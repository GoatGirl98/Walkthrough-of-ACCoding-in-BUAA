#include <stdio.h>
typedef long long ll;
ll n;
ll solve(ll n)
{
    ll ret = 0;
    ll i = 1, j = 1;
    for (i = 1; i <= n; i = j + 1)
        j = n / (n / i), ret += (j - i + 1) * (n / i);
    return ret;
}
int main()
{
    while (scanf("%lld", &n) != EOF)
        printf("%lld\n", solve(n));
}