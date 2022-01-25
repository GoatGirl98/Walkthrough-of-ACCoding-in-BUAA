#include <stdio.h>
long long a, b;
unsigned long long c;
int main()
{

    while (scanf("%lld %lld", &a, &b) != EOF)
    {

        if (a == -9223372036854775808ll && b == -9223372036854775808ll)
            printf("-18446744073709551616\n");
        else if (a >= 0 && b >= 0)
            c = a + b, printf("%llu\n", c);
        else if (a < 0 && b < 0)
            c = -(a + b), printf("-%llu\n", c);
        else if (a >= 0 && b < 0)
        {
            if (a >= -b)
                b = -b, c = a - b, printf("%llu\n", c);
            else
                b = -b, c = b - a, printf("-%llu\n", c);
        }
        else
        {
            if (b >= -a)
                a = -a, c = b - a, printf("%llu\n", c);
            else
                a = -a, c = a - b, printf("-%llu\n", c);
        }
    }
    return 0;
}