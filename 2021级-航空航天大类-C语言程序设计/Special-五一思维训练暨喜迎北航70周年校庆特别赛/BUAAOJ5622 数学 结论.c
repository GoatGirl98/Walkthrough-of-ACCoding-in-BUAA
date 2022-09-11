#include <stdio.h>
typedef long long ll;
ll n, a, b;
int main()
{
    while (~scanf("%lld%lld%lld", &n, &a, &b))
        printf("%lld\n", (n - 1) * a / b + 1);
}