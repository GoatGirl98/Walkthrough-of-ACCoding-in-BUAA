#pragma G++ optimize(2)
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#define maxn 10010
#define maxm 100010
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
inline int read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
int n, m, s, t;
ll maxflow;

struct edge {
    int next, to, w;
}edges[maxm << 1];//双向边
int head[maxn], cnt;
inline void addEdge(int u, int v, int w) {
    edges[cnt].next = head[u];
    edges[cnt].to = v;
    edges[cnt].w = w;
    head[u] = cnt++;
}
int dep[maxn], gap[maxn], cur[maxn];
queue<int> q;
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

inline void ISAP(int s, int t) {
    bfs();
    while (dep[s] < n) {
        memcpy(cur, head, sizeof(head));
        dfs(s, INF);
    }
}

int main() {
    memset(head, -1, sizeof(head));
    n = read(), m = read();// s = read(), t = read();
    s = 1, t = n;
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        u = read(), v = read(), w = read();
        addEdge(u, v, w); addEdge(v, u, w);//无向图权值一样，有向图是0
    }
    ISAP(s, t);
    printf("%lld\n", maxflow);

}
