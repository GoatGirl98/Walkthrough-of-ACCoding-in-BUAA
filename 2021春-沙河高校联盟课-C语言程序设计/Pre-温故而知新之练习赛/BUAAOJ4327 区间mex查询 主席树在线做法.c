#include <stdio.h>
#define N 200005
#define M 10000005
#define min(a, b) (((a) < (b)) ? (a) : (b))
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
const int INF = 1145141919;
int rt[M], ls[M], rs[M], mn[M], cnt = 0;
void update(int *x, int l, int r, int p, int v)
{
    ls[++cnt] = ls[*x], rs[cnt] = rs[*x], mn[cnt] = mn[*x];
    (*x) = cnt;
    if (l == r)
        mn[(*x)] = v;
    else
    {
        int mid = (l + r) >> 1;
        if (p <= mid)
            update(&ls[(*x)], l, mid, p, v);
        else
            update(&rs[(*x)], mid + 1, r, p, v);
        mn[(*x)] = min(mn[ls[(*x)]], mn[rs[(*x)]]);
    }
}
int query(int x, int l, int r, int v)
{
    if (l == r)
        return l;
    else
    {
        int mid = (l + r) >> 1;
        if (mn[ls[x]] < v)
            return query(ls[x], l, mid, v);
        else
            return query(rs[x], mid + 1, r, v);
    }
}
int n, q;
int a[N];
int main()
{
    n = rd(), q = 1;
    for (int i = 1; i <= n; i++)
        a[i] = rd(), rt[i] = rt[i - 1], update(&rt[i], 0, INF, a[i], i);
    while (q--)
    {
        int l = 1, r = n;
        wr(query(rt[r], 0, INF, l)), putchar('\n');
    }
    return 0;
}
