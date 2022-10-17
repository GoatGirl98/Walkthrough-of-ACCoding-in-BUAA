#include <stdio.h>
typedef unsigned long long ull;
#define maxn 114514
#define mod 23333
struct hash
{
    ull num;
    ull cnt, nxt;
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
int n; 
ull a[100010];
int query(ull x) { return find(x, 1); }
int main()
{
    ull ans = 0; 
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%llu", &a[i]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 64; ++j)
            if ((1ull << j) > a[i])
                ans += query((1ull << j) - a[i]);
        add(a[i]);
    }
    printf("%llu", ans);
}
