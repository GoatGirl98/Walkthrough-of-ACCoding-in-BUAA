#include <stdio.h>
#include <algorithm>
#include <array>
#include <numeric>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
typedef long long ll;
using namespace std;
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
void wr(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
// Template From Nyaan : https://n...content-available-to-author-only...b.io/library/data-structure/van-emde-boas-tree.hpp
namespace vEB_tree_impl
{
    using u64 = uint64_t;
    static constexpr unsigned int lgW = 6;
    static constexpr unsigned int W = 1u << lgW;
    static constexpr int inf = 1 << 30;
    inline int ctz(u64 n) { return n ? __builtin_ctzll(n) : -1; }
    inline int clz(u64 n) { return n ? 63 - __builtin_clzll(n) : -1; }

    template <int LOG, class D = void>
    struct vEB_tree_node
    {
        using Chd = vEB_tree_node<(LOG >> 1)>;

        Chd map;
        int mn, mx;
        static constexpr int shift = (LOG >> 1) * lgW;
        array<Chd, 1 << shift> chd;

        inline int mask(u64 key) const { return key & ((1 << shift) - 1); }

        constexpr vEB_tree_node() : mn(inf), mx(-1) {}

        void insert(int key)
        {
            mn = std::min(mn, key), mx = std::max(mx, key);
            int pos = key >> shift;
            if (chd[pos].empty())
                map.insert(pos);
            chd[pos].insert(mask(key));
        }

        void erase(int key)
        {
            int pos = key >> shift;
            if (chd[pos].empty())
                return;
            chd[pos].erase(mask(key));
            if (chd[pos].empty())
                map.erase(pos);
            if (mn == key)
            {
                if (mx == key)
                {
                    mn = inf, mx = -1;
                }
                else
                {
                    int p = map.min();
                    mn = (p << shift) + chd[p].min();
                }
            }
            else if (mx == key)
            {
                int p = map.max();
                mx = (p << shift) + chd[p].max();
            }
        }

        bool contain(int key) const
        {
            int pos = key >> shift;
            return chd[pos].contain(mask(key));
        }

        inline bool empty() const { return mx == -1; }
        inline int min() const { return mn == inf ? -1 : mn; }
        inline int max() const { return mx; }

        int find_next(int key) const
        {
            if (key <= min())
                return min();
            if (max() < key)
                return -1;
            int pos = key >> shift;
            if (map.contain(pos) && mask(key) <= chd[pos].max())
            {
                return (pos << shift) + chd[pos].find_next(mask(key));
            }
            int nxt = map.find_next(pos + 1);
            if (nxt == -1)
                return -1;
            return (nxt << shift) + chd[nxt].min();
        }

        int find_prev(int key) const
        {
            if (max() < key)
                return max();
            if (key <= min())
                return -1;
            int pos = key >> shift;
            if (map.contain(pos) && chd[pos].min() < mask(key))
            {
                return (pos << shift) + chd[pos].find_prev(mask(key));
            }
            int nxt = map.find_prev(pos);
            if (nxt == -1)
                return -1;
            return (nxt << shift) + chd[nxt].max();
        }

        int suc(int key) const { return find_next(key + 1); }        // > key
        int suc_or_equ(int key) const { return find_next(key); }     // >= key
        int pre(int key) const { return find_prev(key); }            // < key
        int pre_or_equ(int key) const { return find_prev(key + 1); } // <= key
    };

    template <int LOG>
    struct vEB_tree_node<LOG, typename std::enable_if<LOG == 1>::type>
    {
        u64 map;
        vEB_tree_node() : map(0) {}
        inline void insert(int key) { map |= 1ULL << key; }
        inline void erase(int key) { map &= ~(1ULL << key); }
        inline bool contain(int key) const { return (map >> key) & 1; }
        inline bool empty() const { return map == 0; }
        inline int min() const { return ctz(map); }
        inline int max() const { return clz(map); }
        int find_next(int key) const { return ctz(map & ~((1ULL << key) - 1)); }
        int find_prev(int key) const { return clz(map & ((1ULL << key) - 1)); }
    };

} // namespace vEB_tree_impl

using van_Emde_Boas_tree = vEB_tree_impl::vEB_tree_node<4>;

van_Emde_Boas_tree vEB;

ll ans;
int dep[300010];

int main()
{
    int n = rd();
    vEB.insert(0), vEB.insert(n + 1);
    dep[0] = dep[n + 1] = -1;
    while (n--)
    {
        int x = rd();
        dep[x] = 1 + max(dep[vEB.pre(x)], dep[vEB.suc(x)]);
        ans += dep[x];
        vEB.insert(x);
        wr(ans), putchar('\n');
    }
}
