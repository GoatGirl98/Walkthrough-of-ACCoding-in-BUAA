#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 505;
const int maxm = 1919810;
const ll INF = 1145141919810114514ll;
inline void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline ll read() {
    ll k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
int n, m;
int u[maxm], v[maxm]; ll w[maxm];
struct Maxflow_ISAP {
    static const ll INF = 1145141919810114514ll;
    static const int maxn = 2005;//点的大小
    static const int maxm = 1919810;//边
    struct edge {
        int next, to;
        ll w;
    }edges[maxm << 1];//双向边
    int head[maxn], cnt;
    inline void addedge(int u, int v, ll w) {
        edges[cnt].next = head[u];
        edges[cnt].to = v;
        edges[cnt].w = w;
        head[u] = cnt++;
        edges[cnt].next = head[v];
        edges[cnt].to = u;
        edges[cnt].w = 0;
        head[v] = cnt++;
    }
    int n;
    int s, t;
    ll maxflow;
    int dep[maxn], gap[maxn], cur[maxn];
    queue<int> q;
    inline void init(int n) {
        this->n = n;
        memset(head, 0xff, sizeof(head));
        while(q.size())q.pop();
        cnt = 0;
        //memset(edges, 0, sizeof(edges));
        memset(dep, 0, sizeof(dep));
        memset(gap, 0, sizeof(gap));
        memset(cur, 0, sizeof(cur));
        maxflow = 0;
    }
    
    //gap[i]指深度为i的点的数量
    //cur为当前弧优化
    inline void bfs() {
        for (int i = 0; i < maxn; ++i) {
            dep[i] = -1; gap[i] = 0;
        }
        q.push(t);
        dep[t] = 0, gap[0] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = head[u]; i >= 0; i = edges[i].next) {
                int v = edges[i].to;
                if (dep[v] != -1)continue;
                q.push(v);
                dep[v] = dep[u] + 1, gap[dep[v]]++;
            }
        }
    }

    inline ll dfs(int u, ll flow) {
        if (u == t) {
            maxflow += flow;
            return flow;
        }
        ll occured = 0;
        for (int& i = cur[u]; i >= 0; i = edges[i].next) {
            int v = edges[i].to;
            if (edges[i].w && dep[v] + 1 == dep[u]) {
                ll d = dfs(v, min(flow - occured, edges[i].w));
                if (d > 0) {
                    edges[i].w -= d; edges[i ^ 1].w += d;
                    occured += d;
                }
                if (occured == flow)return occured;
            }
        }
        //前面和dinic一样
        //后面表示所有点都流过了而且还有剩余
        --gap[dep[u]];
        if (!gap[dep[u]])dep[s] = n + 1;
        dep[u]++;
        gap[dep[u]]++;
        return occured;
    }

    inline ll ISAP(int S, int T) {
        this->s = S, this->t = T;
        bfs();
        while (dep[s] < n) {
            memcpy(cur, head, sizeof(head));
            dfs(s, INF);
        }
        return maxflow;
    }
}solver;
struct edge {
    int next, to;
    ll w;
}edges[maxm << 1];
int head[maxn], cnt;
ll dis[maxn];
ll c;
bool vis[maxn];
inline void addedge(int u, int v, ll w) {
    edges[cnt].next = head[u];
    edges[cnt].to = v;
    edges[cnt].w = w;
    head[u] = cnt++;
    edges[cnt].next = head[v];
    edges[cnt].to = u;
    edges[cnt].w = w;
    head[v] = cnt++;
}
inline void init() {
    memset(head, 0xff, sizeof(head));
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i) dis[i] = INF;
}
struct node {
    int v; ll w;
    node(int _v = 0, ll _w = 0) {v = _v, w = _w;}
    bool operator < (const node & o) const {
        return o.w < w;
    }
};
priority_queue<node> q;
inline void dijkstra(int s, ll* d) {
    while(!q.empty()) q.pop();
    d[s] = 0;
    q.push(node(s, 0));
    while(!q.empty()) {
        node tmp = q.top(); q.pop();
        int u = tmp.v;
        if(vis[u])continue;
        vis[u] = true;
        for(int i = head[u]; ~i; i = edges[i].next) {
            int v = edges[i].to; ll w = edges[i].w;
            if(!vis[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(node(v, d[v]));
            }
        }
    }
}
int main() {
    n = read(), m = read();
    solver.init(n << 1);
    init();
    for(int i = 1; i <= m; ++i) {
        u[i] = read(), v[i] = read(), w[i] = read();
        addedge(u[i], v[i], w[i]);
    }
    dijkstra(1, dis);
    for(int i = 1; i <= m; ++i) {
        if(dis[u[i]] + w[i] == dis[v[i]]) solver.addedge(u[i] + n, v[i], solver.INF);
        if(dis[v[i]] + w[i] == dis[u[i]]) solver.addedge(v[i] + n, u[i], solver.INF);
    }
    for(int i = 1; i <= n; ++i) {
        c = read();
        if(i != 1 && i != n) solver.addedge(i, i + n, c);
        else solver.addedge(i, i + n, solver.INF);
    }
    write(solver.ISAP(1, n << 1));
}
