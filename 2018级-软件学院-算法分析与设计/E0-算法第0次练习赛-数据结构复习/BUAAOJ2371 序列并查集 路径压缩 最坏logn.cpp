#include <stdio.h>
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
// worst O(\log n) average O(\alpha(n))
int n, m, cnt, l, r;
namespace seg_dsu
{
    int f[N];
    inline void init(int n) { for (int i = 1; i <= n + 1; ++i) f[i] = i; }
    inline int getf(int x) { return (f[x] == x) ? x : (f[x] = getf(f[x])); }
    inline void erase(int x) { f[x] = getf(x + 1); }
    inline int nxt_lower(int x) { return getf(x); }
    inline int nxt_upper(int x) { return getf(x + 1); }
    inline bool is_erased(int l, int r) { return getf(l) > r; }
    inline void cover(int l, int r) { for (l = nxt_lower(l); l <= r; l = nxt_upper(l)) erase(l), --cnt; }
}
int main()
{
    n = cnt = rd(), seg_dsu::init(n);
    m = rd();
    while (m--) l = rd(), r = rd(), seg_dsu::cover(l, r), wr(cnt), putchar('\n');
}