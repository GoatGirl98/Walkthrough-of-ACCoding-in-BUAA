#include <stdio.h>
int main()
{
    long long n, k;
    while (scanf("%lld%lld", &n, &k) != EOF)
    {
        long long i, x = 0, y;
        for (i = 2; i <= k && i <= n; ++i)
            x = (x + k) % i;
        for (; i <= n; ++i)
        {
            y = (i - x - 1) / k;
            if (i + y > n)
                y = n - i;
            i += y;
            x = (x + (y + 1) % i * k) % i;
        }
        printf("%lld\n", x + 1);
    }
    return 0;
}