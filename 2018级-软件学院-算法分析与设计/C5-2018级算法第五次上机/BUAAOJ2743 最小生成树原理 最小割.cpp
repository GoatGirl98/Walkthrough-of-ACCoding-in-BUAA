#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
inline void write(int x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
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
struct Maxflow_ISAP {
    static const int INF = 0x3f3f3f3f;
    static const int maxn = 205;//点的大小
    static const int maxm = 1005;//边
    struct edge {
        int next, to, w;
    }edges[maxm << 1];//双向边
    int head[maxn], cnt;
    inline void addedge(int u, int v, int w) {
        edges[cnt].next = head[u];
        edges[cnt].to = v;
        edges[cnt].w = w;
        head[u] = cnt++;
        edges[cnt].next = head[v];
        edges[cnt].to = u;
        edges[cnt].w = w;
        head[v] = cnt++;
    }
    int n;
    int s, t;
    int maxflow;
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

    inline int dfs(int u, int flow) {
        if (u == t) {
            maxflow += flow;
            return flow;
        }
        int occured = 0;
        for (int& i = cur[u]; i >= 0; i = edges[i].next) {
            int v = edges[i].to;
            if (edges[i].w && dep[v] + 1 == dep[u]) {
                int d = dfs(v, min(flow - occured, edges[i].w));
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

    inline int ISAP(int S, int T) {
        this->s = S, this->t = T;
        bfs();
        while (dep[s] < n) {
            memcpy(cur, head, sizeof(head));
            dfs(s, INF);
        }
        return maxflow;
    }
}solver;
int n, m;
int u[105], v[105], w[105];
int main() {
    n = read(), m = read();
    for(int i = 1; i <= m; ++i)
        u[i] = read(), v[i] = read(), w[i] = read();
    for(int i = 1; i <= m; ++i) {
        solver.init(n);
        for(int j = 1; j <= m; ++j)
            if(w[j] < w[i])
                solver.addedge(u[j], v[j], 1);
        write(solver.ISAP(u[i], v[i])), putchar_unlocked(' ');
    }
}
