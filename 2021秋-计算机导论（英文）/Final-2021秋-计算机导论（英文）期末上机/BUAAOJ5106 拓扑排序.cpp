#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
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
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
int T;
int n, m;
int in_degree[1010];
vector<int> g[1010], topo;
queue<int> q;
void init()
{
    topo.clear();
    while (q.size())
        q.pop();
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    memset(in_degree, 0, (n + 1) * sizeof(in_degree[0]));
}
bool toposort()
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (!in_degree[i])
            q.push(i), ++cnt;
    if (cnt != 1)
        return false;
    while (!q.empty())
    {
        cnt = 0;
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            in_degree[v]--;
            if (!in_degree[v])
                q.push(v), ++cnt;
        }
        if (cnt > 1)
            return 0;
    }
    return topo.size() == n;
}
int main()
{
    T = rd();
    while (T--)
    {
        n = rd(), m = rd();
        init();
        while (m--)
        {
            int u = rd(), v = rd();
            g[u].push_back(v);
            in_degree[v]++;
        }
        bool ret = toposort();
        if (ret)
            for (int i = 0; i < n; ++i)
                wr(topo[i]), putchar(i == n - 1 ? '\n' : ' ');
        else
            puts("Error");
    }
}