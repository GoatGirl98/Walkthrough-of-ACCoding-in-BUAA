#include <stdio.h>
#include <stdbool.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define maxn 200010
void wr(int x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
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
int n, m, ans;
int l, r;
int f[maxn];
bool vis[maxn];
void initf()
{
    for (int i = 1; i <= n; ++i)
        f[i] = i;
}
int getf(int x)
{
    if (f[x] == x)
        return x;
    else
        return f[x] = getf(f[x]);
}
bool check(int x, int y)
{
    int a = getf(x);
    int b = getf(y);
    if (a ^ b)
        return false;
    else
        return true;
}
void merge(int x, int y)
{
    int a = getf(x);
    int b = getf(y);
    if (a == b)
        return;
    else
        f[a] = b;
}
int main()
{
    n = rd(), m = rd(), ans = n;
    initf();
    while (m--)
    {
        l = rd(), r = rd();
        if (l > r)
            l ^= r, r ^= l, l ^= r;
        int cur = l;
        while (cur <= r)
        {
            if (vis[cur])
                cur = getf(cur);
            else
                vis[cur] = 1, --ans;
            merge(cur, r), ++cur;
        }
        wr(ans), putchar('\n');
    }
}