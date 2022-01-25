#include <stdio.h>
#include <string.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define maxn 200010
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
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
// tarjan

struct edge
{
    int to, nxt;
} edges[maxn];
int head[maxn], cnt;

int dfn[maxn], low[maxn], dfs_time;
int s[maxn], stack_sz;
int in_stack[maxn];
int belong[maxn], scc;

int ans;

void init()
{
    ans = maxn;
    memset(head, 0, sizeof(head));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    stack_sz = 0, cnt = 0, dfs_time = 1;
}

void add(int u, int v)
{
    edges[++cnt].to = v, edges[cnt].nxt = head[u];
    head[u] = cnt;
}

void tarjan(int u)
{
    low[u] = dfn[u] = dfs_time++;
    in_stack[u] = 1, s[stack_sz++] = u;
    for (int i = head[u]; i; i = edges[i].nxt)
    {
        int v = edges[i].to;
        if (!dfn[v])
            tarjan(v);
        if (in_stack[v])
            low[u] = min(low[v], low[u]);
    }
    if (low[u] == dfn[u])
    {
        ++scc;
        int scc_sz = 0;
        while (1)
        {
            int v = s[--stack_sz];
            in_stack[v] = 0;
            belong[v] = scc;
            ++scc_sz;
            if (v == u)
                break;
        }
        if (scc_sz >= 2)
            ans = min(ans, scc_sz);
    }
}

int main()
{
    init();
    int n = rd();
    for (int i = 1; i <= n; ++i)
        add(i, rd());
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);
    wr(ans);
}