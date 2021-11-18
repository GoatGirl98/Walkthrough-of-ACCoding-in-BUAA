#include <stdio.h>
#include <string.h>
#include <stack>
#include <algorithm>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;

const int maxn = 1010, maxm = 5010;
int rd()
{
    int k = 0;
    char c = getchar();

    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }

    return k;
}
void wr(int x)
{
    if (x > 9)
        wr(x / 10);

    putchar(x % 10 + '0');
}
int n, m, head[maxn], len, we[maxn], va[maxn], sumw[maxn], sumv[maxn];
int nhead[maxn], nlen, ind[maxn], sp[maxn];
int times, dfn[maxn], low[maxn], scc[maxn], cnt;
int len2, seq[maxn], sz[maxn], f[8010010];
stack<int> st;

inline int id(int row, int w)
{
    return (row - 1) * (m + 1) + w;
}

struct edge
{
    int to, next;
} edges[maxn], nedges[maxn];

void add_edge(int u, int v)
{
    edges[++len].to = v;
    edges[len].next = head[u];
    head[u] = len;
}

void nadd_edge(int u, int v)
{
    nedges[++nlen].to = v;
    nedges[nlen].next = nhead[u];
    ++ind[v];
    nhead[u] = nlen;
}

void dfs(int u)
{
    dfn[u] = low[u] = ++times;
    st.push(u);

    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;

        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!scc[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u])
    {
        ++cnt;

        while (1)
        {
            int x = st.top();
            st.pop();
            scc[x] = cnt;
            sumw[cnt] += we[x];
            sumv[cnt] += va[x];

            if (x == u)
            {
                break;
            }
        }
    }
}

void dfs2(int u)
{
    seq[++len2] = u;
    sz[u] = 1;

    for (int i = nhead[u]; i; i = nedges[i].next)
    {
        int v = nedges[i].to;
        sp[v] = sp[u] + sumw[u];
        dfs2(v);
        sz[u] += sz[v];
    }
}
/*
int n, m, head[maxn], len, we[maxn], va[maxn], sumw[maxn], sumv[maxn];
int nhead[maxn], nlen, ind[maxn], sp[maxn];
int times, dfn[maxn], low[maxn], scc[maxn], cnt;
int len2, seq[maxn], sz[maxn], f[5000010];
stack<int> st;
*/
void init()
{
    len = nlen = cnt = times = len2 = 0;
    memset(head, 0, (n + 1) * sizeof(int));
    memset(we, 0, (n + 1) * sizeof(int));
    memset(va, 0, (n + 1) * sizeof(int));
    memset(sumw, 0, (n + 1) * sizeof(int));
    memset(sumv, 0, (n + 1) * sizeof(int));
    memset(nhead, 0, (n + 1) * sizeof(int));
    memset(ind, 0, (n + 1) * sizeof(int));
    memset(sp, 0, (n + 1) * sizeof(int));
    memset(dfn, 0, (n + 1) * sizeof(int));
    memset(low, 0, (n + 1) * sizeof(int));
    memset(scc, 0, (n + 1) * sizeof(int));
    memset(seq, 0, (n + 1) * sizeof(int));
    memset(sz, 0, (n + 1) * sizeof(int));
    memset(f, 0, (n + 1) * (m + 1) * sizeof(int));
    while(st.size())
        st.pop();
}

int main()
{
    // freopen("in.in", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        
        for (int i = 1; i <= n; ++i)
            we[i] = rd();

        for (int i = 1; i <= n; ++i)
            va[i] = rd();

        for (int i = 1; i <= n; ++i)
        {
            int fa = rd();

            if (fa)
                add_edge(fa, i);
        }

        //tarjan
        for (int i = 1; i <= n; ++i)
            if (!dfn[i])
                dfs(i);

        for (int u = 1; u <= n; ++u)
        {
            for (int i = head[u]; i; i = edges[i].next)
            {
                int v = edges[i].to;
                int x = scc[u], y = scc[v];

                if (x != y)
                {
                    nadd_edge(x, y);
                }
            }
        }

        for (int i = 1; i <= cnt; ++i)
        {
            if (!ind[i])
            {
                nadd_edge(cnt + 1, i);
            }
        }

        dfs2(cnt + 1);

        for (int i = 1; i <= len2; ++i)
        {
            for (int j = sp[seq[i]]; j <= m - sumw[seq[i]]; ++j)
            {
                f[id(i + 1, j + sumw[seq[i]])] = max(f[id(i + 1, j + sumw[seq[i]])], f[id(i, j)] + sumv[seq[i]]);
            }

            for (int j = sp[seq[i]]; j <= m; ++j)
            {
                f[id(i + sz[seq[i]], j)] = max(f[id(i + sz[seq[i]], j)], f[id(i, j)]);
            }
        }

        wr(f[id(len2 + 1, m)]), putchar('\n');
    }
    return 0;
}
