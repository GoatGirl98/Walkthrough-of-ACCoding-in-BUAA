#include <stdio.h>

int main()
{
    long long a, b;
    unsigned long long c, d;
    scanf("%lld %lld", &a, &b);
    if (a == -9223372036854775808 && b < -9223372036854775807)
    {
        printf("-18446744073709551616");
    }
    else if ((a > 0 && b < 0) || (a < 0 && b > 0))
    {
        printf("%lld", a + b);
    }
    else if (a > 0 && b > 0)
    {
        c = a;
        d = b;
        printf("%llu", c + d);
    }
    else if (a < 0 && b < 0)
    {
        c = -a;
        d = -b;
        printf("-%llu", c + d);
    }
}