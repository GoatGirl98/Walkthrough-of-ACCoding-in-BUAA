#include <stdio.h>

int rd()
{
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    if (f > 0)
        return k;
    else
        return -k;
}

void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}

int mp[55];
int ori[55];
int n, k, tmp, ans;

struct node
{
    int l, r;
};

struct node node[11];

void dfs(int step)
{
    if (step == 1)
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            ori[i] = mp[i]; /* 其实也可以不储存，因为有回溯，不会打乱 */
        }
    }
    if (step == k + 1)
    {
        ans++;
        return;
    }
    int num = k - step + 1;
    if (ori[node[num].l] < ori[node[num].r])
    {
        dfs(step + 1);
        tmp = ori[node[num].l];
        ori[node[num].l] = ori[node[num].r];
        ori[node[num].r] = tmp;
        dfs(step + 1);
        tmp = ori[node[num].l];
        ori[node[num].l] = ori[node[num].r];
        ori[node[num].r] = tmp;
    }
    return;
}

void func1()
{
    int i;
    for (i = 1; i <= n - 1; i++) /* 从i进行交换 */
    {
        int j;
        for (j = 1; j <= n; j++)
        {
            mp[j] = j;
        }
        for (j = 1; j <= n - i; j++)
        {
            tmp = mp[i + j - 1];
            mp[i + j - 1] = mp[i + j];
            mp[i + j] = tmp;
            dfs(1);
        }
    }
}

void func2()
{
    int i;
    for (i = 2; i <= n - 1; i++)
    {
        int j;
        for (j = 1; j <= n; j++)
        {
            mp[j] = j;
        }
        tmp = mp[i + 1];
        mp[i + 1] = mp[i];
        mp[i] = tmp;
        for (j = 1; j <= i - 1; j++)
        {
            tmp = mp[i - j + 1];
            mp[i - j + 1] = mp[i - j];
            mp[i - j] = tmp;
            dfs(1);
        }
    }
}

int main()
{
    int t = rd();
    int i;
    for (i = 1; i <= t; i++)
    {
        ans = 0;
        n = rd(), k = rd();
        int j;
        for (j = 1; j <= k; j++)
        {
            node[j].l = rd(), node[j].r = rd();
        }
        func1();
        func2();
        for (j = 1; j <= n; j++)
        {
            mp[j] = j;
        }
        dfs(1);
        wr(ans), putchar('\n');
    }
    return 0;
}
