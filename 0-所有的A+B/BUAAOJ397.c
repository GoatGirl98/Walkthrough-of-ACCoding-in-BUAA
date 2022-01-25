#include <stdio.h>
typedef long long ll;
ll t, a, b;
int main()
{
    scanf("%lld", &t);
    while (t--)
        scanf("%lld%lld", &a, &b), printf("%lld\n", a + b);
}