#include <stdio.h>
typedef long long ll;
ll plus(ll a, ll b)
{
    while (b)
    {
        ll sum = 0, carry = 0;
        sum = a ^ b, carry = (a & b) << 1;
        a = sum, b = carry;
    }
    return a;
}
ll a, b;
int main()
{
    scanf("%lld%lld", &a, &b);
    printf("%lld", plus(a, b));
}