#include <stdio.h>
typedef long long ll;
ll last_zero_count(ll n)
{
    ll result = 0;
    while (n)
    {
        n /= 5;
        result += 1ll * n;
    }
    return result;
}
ll n;
int main()
{
    scanf("%lld", &n);
    printf("%lld", last_zero_count(n));
}