#include <stdio.h>
#include <string.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
typedef long long ll;
ll rd()
{
    ll k = 0, f = 1;
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
// area 1 : queue
#define maxq 100010
int q[maxq], _head, _tail, _size;

void init_queue(int sz)
{
    _head = _tail = 0;
    _size = sz + 1;
}

char is_empty()
{
    return _head == _tail;
}

char is_full()
{
    int t = _tail + 1;
    if (t >= _size)
        t -= _size;
    return t == _head;
}

char push(int value)
{
    if (is_full())
        return 0;
    q[_tail++] = value;
    if (_tail == _size)
        _tail = 0;
    return 1;
}

char pop()
{
    if (is_empty())
        return 0;
    _head++;
    if (_head == _size)
        _head = 0;
    return 1;
}

int front()
{
    if (is_empty())
        return -1;
    return q[_head];
}

int back()
{
    if (is_empty())
        return -1;
    int t = _tail - 1;
    if (t < 0)
        t += _size;
    return q[t];
}

// area 2 : Maxflow ISAP
#define maxn 100010
#define maxm 200010
#define INF 1145141919810ll
int n, m, s, t;
ll maxflow;
struct edge
{
    int next, to;
    ll w;
} edges[maxm << 1];
int head[maxn], cnt;
void add_edge(int u, int v, ll w)
{
    edges[cnt].next = head[u];
    edges[cnt].to = v;
    edges[cnt].w = w;
    head[u] = cnt++;
}
int dep[maxn], gap[maxn], cur[maxn];

void bfs()
{
    for (int i = 0; i < maxn; ++i)
        dep[i] = -1, gap[i] = 0;

    push(t);
    dep[t] = 0, gap[0] = 1;
    while (!is_empty())
    {
        int u = front();
        pop();
        for (int i = head[u]; i >= 0; i = edges[i].next)
        {
            int v = edges[i].to;
            if (dep[v] != -1)
                continue;
            push(v);
            dep[v] = dep[u] + 1, gap[dep[v]]++;
        }
    }
}

ll dfs(int u, ll flow)
{
    if (u == t)
    {
        maxflow += flow;
        return flow;
    }
    ll occured = 0;
    for (int i = cur[u]; i >= 0; cur[u] = i = edges[i].next)
    {
        int v = edges[i].to;
        if (edges[i].w && dep[v] + 1 == dep[u])
        {
            ll d = dfs(v, min(flow - occured, edges[i].w));
            if (d > 0)
            {
                edges[i].w -= d;
                edges[i ^ 1].w += d;
                occured += d;
            }
            if (occured == flow)
                return occured;
        }
    }
    --gap[dep[u]];
    if (!gap[dep[u]])
        dep[s] = n + 1;
    dep[u]++;
    gap[dep[u]]++;
    return occured;
}

void ISAP(int s, int t)
{
    init_queue(n);
    bfs();
    while (dep[s] < n)
    {
        memcpy(cur, head, sizeof(head));
        dfs(s, INF);
    }
}

int N, M, daily_lim;

int main()
{
    memset(head, -1, sizeof(head));
    N = rd(), M = rd(), daily_lim = 1;
    n = N + M + 2, s = N + M + 1, t = N + M + 2;
    for (int i = 1; i <= N; ++i)
    {
        int l = rd(), r = rd(), need_days = 1;
        // add <source, task> need_days
        add_edge(s, i, need_days), add_edge(i, s, 0);
        // add <task, time> 1
        for (int j = l; j <= r; ++j)
            add_edge(i, j + N, 1), add_edge(j + N, i, 0);
    }
    // add <time, sink> daily_lim
    for (int i = N + 1; i <= N + M; ++i)
        add_edge(i, t, daily_lim), add_edge(t, i, 0);
    ISAP(s, t);
    printf("%lld", maxflow);
}