#include <stdio.h>
#include <string.h>
#define maxn 10005
int a[maxn], b[maxn], dp[maxn], pre[maxn], ans[maxn];
char eof_flag;
char rd(int *s)
{
    if (eof_flag)
        return 0;
    int k = 0, f = 1;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
    {
        if (c == EOF)
        {
            eof_flag = 1;
            return 0;
        }
        c = getchar();
    }
    f = (c == '-') ? -1 : 1;
    k = (c == '-') ? 0 : (c ^ 48);
    c = getchar();
    while (c >= '0' && c <= '9')
        k = (k << 1) + (k << 3) + (c ^ 48), c = getchar();
    if (c == EOF)
        eof_flag = 1;
    (*s) = f > 0 ? k : -k;
    return 1;
}
void wr(int x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
int n, m;
int main()
{
    while (rd(&n) && rd(&m))
    {
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++)
            rd(a + i);
        for (int i = 1; i <= m; i++)
            rd(b + i);

        for (int i = 1; i <= n; i++)
        {
            int MAX = 0;
            for (int j = 1; j <= m; j++)
            {
                if (a[i] == b[j] && dp[j] < dp[MAX] + 1)
                {
                    dp[j] = dp[MAX] + 1;
                    pre[j] = MAX;
                }
                else if (a[i] > b[j] && dp[j] > dp[MAX])
                    MAX = j;
            }
        }

        int maxx = 0, cnt = 0;

        for (int i = 1; i <= m; i++)
            if (dp[i] > dp[maxx])
                maxx = i;
        wr(dp[maxx]), putchar('\n');
        /*
        for (int i = maxx; i; i = pre[i])
            ans[cnt++] = b[i];
        for (int i = cnt - 1; ~i; --i, putchar(' '))
            wr(ans[i]);
        putchar('\n');
        */
    }
    return 0;
}
