#include <stdio.h>
#include <string.h>
#include <algorithm>
typedef unsigned short u16;
typedef unsigned u32;
#define getchar getchar_unlocked
#define putchar putchar_unlocked
inline int rd()
{
    int k = 0;
    char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s >= '0' && s <= '9') k = (k << 1) + (k << 3) + (s ^ '0'), s = getchar();
    return k;
}
inline void wr(int x)
{
    if (x > 9) wr(x / 10);
    putchar((x % 10) ^ '0');
}
const int N = 200100;
int n, m, cnt, l, r;
// worst O(1) 0-index
namespace seg_dsu
{
    const u32 b = 5, B = (1 << b), m = B - 1, M = ~0;
    u16 f[N >> b], sz[N >> b], nxt[N >> b];
    u32 val[N >> b];
    inline void init(int n)
    {
        for (u16 i = 0; i <= (n >> b); ++i) f[i] = i, sz[i] = 1, nxt[i] = i;
        memset(val, 0xff, ((n >> b) + 1) << 2);
    }
    inline u16 getf(u16 x) { return (f[x] == x) ? x : (f[x] = getf(f[x])); }
    inline void merge(u16 x, u16 y)
    {
        x = getf(x), y = getf(y);
        if (x == y) return;
        if (sz[x] > sz[y]) std::swap(x, y);
        f[x] = y, sz[y] += sz[x], nxt[x] = nxt[y] = std::max(nxt[y], nxt[x]);
    }
    inline void join(int x) { val[x >> b] &= (M ^ (1 << (x & m))); }
    inline int micro(int x) { return x >> b; }
    inline int micro_find(int x)
    {
        int pos = x >> b, bit = x & m;
        u32 v = val[pos] & (M ^ ((1 << bit) - 1));
        return v ? (pos << b | __builtin_ctz(v)) : ((u32)nxt[getf(pos + 1)]) << b;
    }
    inline int find(int x)
    {
        if (micro(x) ^ micro(micro_find(x))) x = micro_find(micro_find(x));
        while (micro(x) ^ micro(micro_find(x)))
            merge(micro(x), micro(micro_find(x))), x = ((u32)nxt[getf(micro(micro_find(x)))]) << b;
        return micro_find(x);
    }
    inline int nxt_lower(int x) { return find(x); }
    inline int nxt_upper(int x) { return find(x + 1); }
    inline bool is_erased(int l, int r) { return find(l) > r; }
    inline void cover(int l, int r) { for (l = nxt_lower(l); l <= r; l = nxt_upper(l)) join(l), --cnt; }
}
int main()
{
    n = cnt = rd(), seg_dsu::init(n), m = rd();
    while (m--) l = rd() - 1, r = rd() - 1, seg_dsu::cover(l, r), wr(cnt), putchar('\n');
}