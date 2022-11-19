#include <stdio.h>
#include <ctype.h>
#include <string.h>
const int INF = 0x3f3f3f3f;
int dp[105][105];
int n, m, u, v;
int rd()
{
    int k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
}
int main()
{
    n = rd(), m = rd();
    memset(dp, 0x3f, sizeof(dp));
    while (m--)
        u = rd(), v = rd(), dp[u][v] = 1;
    floyd();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (dp[i][j] < INF)
                wr(i), putchar(' '), wr(j), putchar('\n');
}