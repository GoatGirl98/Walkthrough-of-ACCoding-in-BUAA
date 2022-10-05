#include <stdio.h>

unsigned long long ans[101][101];

int main()
{
    int n, m, a, i;
    for (n = 1; n <= 100; ++n)
    {
        for (m = 0; m <= n; ++m)
        {
            if (m == 0 || m == n)
            {
                ans[n][m] = 1;
            }
            else
            {
                ans[n][m] = ans[n - 1][m] + ans[n - 1][m - 1];
            }
        }
    }

    scanf("%d", &a);

    for (i = 0; i < a; ++i)
    {
        scanf("%d %d", &n, &m);
        if (m > n)
        {
            printf("You're kidding me!");
        }
        else
        {
            printf("%llu", ans[n][m]);
        }

        printf("\n");
    }
}