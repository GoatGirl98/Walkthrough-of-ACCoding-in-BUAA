#include <stdio.h>
typedef unsigned long long ull;
#define maxn 1200010
#define mod 23333
struct hash
{
    ull num;
    int cnt, nxt;
} list[maxn];
int head[mod], cnt;
int hashcode(ull x) { return x % mod; }
int find(ull x, int flag)
{
    for (int i = head[hashcode(x)]; i; i = list[i].nxt)
        if (list[i].num == x)
            return flag ? list[i].cnt : i;
    return 0;
}
void newnode(ull x)
{
    int code = hashcode(x);
    list[++cnt].num = x, list[cnt].cnt = 1;
    list[cnt].nxt = head[code], head[code] = cnt;
}
void add(ull x)
{
    int idx = find(x, 0);
    if (!idx)
        newnode(x);
    else
        ++list[idx].cnt;
}
int n; ull x;
int query(ull x) { return find(x, 1); }
int main()
{
    int ans = 0; scanf("%d", &n);
    while (n--)
    {
        scanf("%llu", &x);
        ans += query(x);
        for (int i = 1; i < 64; ++i)
            if (x < (1ull << i))
                add((1ull << i) - x);
    }
    printf("%d", ans);
}