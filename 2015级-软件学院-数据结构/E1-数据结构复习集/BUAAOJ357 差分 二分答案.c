#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define int long long
#define maxn 1000010
int lo, mi, hi;
int n, m;
int r[maxn], d[maxn], s[maxn], t[maxn];
int sum[maxn];
// 无法满足要求则返回true
bool judge(int x)
{ 
    memset(sum, 0, sizeof(sum));

    for (int i = 1; i <= x; ++i)
    {
        sum[s[i]] += d[i];
        sum[t[i] + 1] -= d[i];
    }

    if (sum[1] > r[1])
        return true;

    for (int i = 2; i <= n; ++i)
    {
        sum[i] += sum[i - 1];

        if (sum[i] > r[i])
            return true;
    }

    return false;
}
signed main()
{
    scanf("%lld%lld", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &r[i]);

    for (int i = 1; i <= m; ++i)
        scanf("%lld%lld%lld", &d[i], &s[i], &t[i]);

    lo = 1, hi = m + 1;

    while (lo < hi)
    {
        mi = (lo + hi) >> 1;
        if (judge(mi))
            hi = mi;
        else
            lo = mi + 1;
    }

    if (hi < m)
        printf("-1\n%lld\n", hi);
    else
        puts("0");
}