#include <stdio.h>
int n, m, bit[100001], maxn, s;
int lowbit(int x)
{
    return x & (-x);
}
void del(int pos, int x)
{
    for (int i = pos; i <= maxn; i += lowbit(i))
        bit[i] += x;
}
int find(int i)
{
    int ans = 0, now = 0;
    for (int j = 30; j >= 0; j--)
    {
        ans += (1 << j);
        if (ans > maxn || bit[ans] + now >= i)
        {
            ans -= (1 << j);
        }
        else
        {
            now += bit[ans];
        }
    }
    return ans + 1;
}
int main()
{

    int now;
    scanf("%d%d%d", &n, &now, &m);
    maxn = n;
    for (int i = 1; i <= n; i++)
        bit[i] = lowbit(i);

    while (n)
    {
        now = (now - 1 + m - 1) % n + 1;
        s = find(now);
        del(s, -1);
        printf("%d\n", s);
        n--;
    }
    return 0;
}
