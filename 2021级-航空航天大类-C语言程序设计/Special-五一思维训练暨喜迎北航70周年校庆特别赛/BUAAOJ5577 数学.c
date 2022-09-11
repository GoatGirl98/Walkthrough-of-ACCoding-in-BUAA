#include <stdio.h>
typedef long long ll;
ll a, b;
int main()
{
    scanf("%lld%lld", &a, &b);
    printf("%lld", a * b - a - b);
}