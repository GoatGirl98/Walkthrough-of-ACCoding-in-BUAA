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
    return f > 0 ? k : -k;
}
int n, m;
int mp[10000010];
int main()
{
    n = rd(), m = rd();
    while (m--)
    {
        int l = rd(), r = rd();
        ++mp[l], --mp[r + 1];
    }
    int pre = 0, cur = 0, res = 0, cnt = 0;
    while (cur <= (n + 1))
    {
        while (cur <= (n + 1) && !mp[cur])
            ++cur;
        if (cnt >= 1)
            res += cur - pre;
        pre = cur;
        cnt += mp[cur];
        ++cur;
    }
    printf("%d", n - res);
}