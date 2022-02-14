#include <stdio.h>
#include <string.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
char s[305];
// dp[i][i] = 1
int dp[305][305];
int n, k;
int main()
{
    fgets(s + 1, 305, stdin);
    n = strlen(s + 1);
    while (s[n] == '\r' || s[n] == EOF || s[n] == '\n')
        s[n--] = '\0';
    k = n;
    for (int len = 1; len <= n; ++len)
        for (int l = 1, r = l + len - 1; r <= n; ++l, ++r)
        {
            if (l == r)
                dp[l][r] = 1;
            else
            {
                // initial status : 1 paint
                dp[l][r] = dp[l + 1][r] + 1;
                if (len <= k)
                {
                    for (int cur = l + 1; cur <= r; ++cur)
                        if (s[l] == s[cur])
                            dp[l][r] = min(dp[l][r], dp[l + 1][cur] + dp[cur + 1][r]);
                }
                else
                    for (int cur = l + 1; cur <= r; ++cur)
                        dp[l][r] = min(dp[l][r], dp[l][cur] + dp[cur + 1][r]);
            }
        }
    wr(dp[1][n]);
}