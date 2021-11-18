#pragma G++ optimize(2)
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#define maxn 10010
#define maxm 200010
#define INF 1145141919810LL
typedef long long ll;
using namespace std;
inline ll read() {
    ll k = 0, f = 1;
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
    int next, to;
    ll w;
}edges[maxm << 1];//双向边
int head[maxn], cnt;
inline void addEdge(int u, int v, ll w) {
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

inline void ISAP(int s, int t) {
    bfs();
    while (dep[s] < n) {
        memcpy(cur, head, sizeof(head));
        dfs(s, INF);
    }
}
ll sum;
int N,M;
ll w;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
inline bool isLegal(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

inline int id(int i, int j) {return (i - 1) * M + j;}//i行j列的点标号
int main() {
    memset(head, -1, sizeof(head));
    N = read(), M = read();
    n = t = N * M + 2, s = N * M + 1;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            w = read();
            sum += w;
            if (!((i + j) & 1)) {
                addEdge(s, id(i, j), w), addEdge(id(i, j), s, 0);
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (isLegal(x, y))
                        addEdge(id(i, j), id(x, y), INF), addEdge(id(x, y), id(i, j), 0);
                }
            }
            else
                addEdge(id(i,j), t, w),addEdge(t, id(i,j), 0);
            //奇数点连源点 偶数点连汇点
        }
    }
    ISAP(s, t);
    printf("%lld\n", sum - maxflow);
}
