#include <stdio.h>
typedef struct task
{
    int l, r;
} task;
task a[1010];
char vis[1010];
int n, m, ans;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].l, &a[i].r);
    for (int i = 1; i <= m; ++i)
    {
        int min_time = m + 1, task = 0;
        for (int t = 1; t <= n; ++t)
            if (i >= a[t].l && i <= a[t].r && !vis[t] && a[t].r < min_time)
                min_time = a[t].r, task = t;
        if (task)
            vis[task] = 1, ++ans;
    }
    printf("%d", ans);
}