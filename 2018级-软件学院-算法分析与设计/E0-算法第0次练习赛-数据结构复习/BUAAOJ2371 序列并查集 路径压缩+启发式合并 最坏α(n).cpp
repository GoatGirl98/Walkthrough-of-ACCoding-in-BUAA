#include <stdio.h>
#include <algorithm>
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
const int N = 200010;
// worst O(\alpha(n))
int n, m, cnt, l, r;
namespace seg_dsu
{
    int f[N], sz[N], nxt[N];
    inline void init(int n) { for (int i = 1; i <= n + 1; ++i) f[i] = i, sz[i] = 1, nxt[i] = i; }
    inline int getf(int x) { return (f[x] == x) ? x : (f[x] = getf(f[x])); }
    inline void merge(int x, int y)
    {
        x = getf(x), y = getf(y);
        if (x == y) return;
        if (sz[x] > sz[y]) std::swap(x, y);
        f[x] = y, sz[y] += sz[x], nxt[x] = nxt[y] = std::max(nxt[y], nxt[x]);
    }
    inline void erase(int x) { merge(x, x + 1); }
    inline int nxt_lower(int x) { return nxt[getf(x)]; }
    inline int nxt_upper(int x) { return nxt[getf(x + 1)]; }
    inline bool is_erased(int l, int r) { return nxt[getf(l)] > r; }
    inline void cover(int l, int r) { for (l = nxt_lower(l); l <= r; l = nxt_upper(l)) erase(l), --cnt; }
}
int main()
{
    n = cnt = rd(), seg_dsu::init(n);
    m = rd();
    while (m--) l = rd(), r = rd(), seg_dsu::cover(l, r), wr(cnt), putchar('\n');
}