#include <stdio.h>
#define N 500
typedef long long ll;
ll f[N + 5], g[N + 5], dp[N + 5];
int n, t;
int i, j;
int rd()
{
    int k = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return k;
}
void wr(int x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    for (i = 1; i <= N; ++i)
        f[i] = 1ll * i * (3 * i - 1) / 2;
    for (i = 1; i <= N; ++i)
        g[i] = 1ll * i * (3 * i + 1) / 2;
    dp[0] = 1;
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; f[j] <= i; j++)
            if (j & 1)
            {
                dp[i] += dp[i - f[j]];
                if (g[j] <= i)
                    dp[i] += dp[i - g[j]];
            }
            else
            {
                dp[i] -= dp[i - f[j]];
                if (g[j] <= i)
                    dp[i] -= dp[i - g[j]];
            }
        //dp[i] %= P;
        //if (dp[i] < 0)
        //dp[i] += P;
    }
    t = 1;
    while (t--)
        wr(dp[rd()]), putchar('\n');
}