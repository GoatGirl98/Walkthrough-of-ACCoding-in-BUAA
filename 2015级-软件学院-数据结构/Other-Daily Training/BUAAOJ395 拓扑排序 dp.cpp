#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
int rd()
{
    int k = 0, f = 1;
    char s = getchar();
    while (s < '0' || s > '9')
        f = (s == '-') ? 0 : f, s = getchar();
    while (s >= '0' && s <= '9')
        k = (k << 1) + (k << 3) + (s ^ '0'), s = getchar();
    return f ? k : -k;
}
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}
const int N = 10010;
const int mod = 10000;
int add(int a, int b) { return (a + b >= mod) ? (a + b - mod) : (a + b); }
int mul(int a, int b) { return a * b % mod; }
namespace topo
{
    std::vector<std::pair<int, int>> e[N];
    std::queue<int> q;
    int f[N], g[N];
    int in_deg[N], n;
    int ord[N], cnt;
    void clr()
    {
        for (int i = 0; i < N; ++i)
            e[i].clear();
        memset(in_deg, 0, sizeof(in_deg)), cnt = 0;
    }
    void init_sz(int _n) { n = _n; }
    void add_edge(int u, int v, int w) { e[u].push_back({v, w}), ++in_deg[v]; }
    void solve(int s)
    {
        for (int i = 1; i <= n; ++i)
            if ((i ^ s) && !in_deg[i])
                ord[++cnt] = i, q.push(i);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (const std::pair<int, int>& x : e[u])
            {
                --in_deg[x.first];
                if (!in_deg[x.first])
                    ord[++cnt] = x.first, q.push(x.first);
            }
        }
        q.push(s), f[s] = 1, g[s] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (const std::pair<int, int>& x : e[u])
            {
                --in_deg[x.first];
                f[x.first] = add(f[x.first], f[u]), g[x.first] = add(add(g[x.first], g[u]), mul(f[u], x.second)); // dp u -> dp v
                if (!in_deg[x.first])
                    ord[++cnt] = x.first, q.push(x.first);
            }
        }
    }
}
int main()
{
    int n = rd(), m = rd(), s = rd(), t = rd(), T = rd();
    T = (T == mod) ? 0 : T;
    topo::init_sz(n);
    while (m--)
    {
        int u = rd(), v = rd(), w = rd();
        w = (w == mod) ? 0 : w;
        topo::add_edge(u, v, w);
    }
    topo::solve(s);
    wr(add(topo::g[t], mul(T, add(topo::f[t], mod - 1))));
}
