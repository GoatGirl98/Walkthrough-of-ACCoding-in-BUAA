#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1010;
const int maxm = 50010;
inline void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
struct edge {
    int v, w, next;
}edges[maxm];
int head[maxn], cnt;
inline void addEdge(int u, int v, int w) {
    edges[++cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}
bool vis[maxn];
int dis[maxn];
int path[maxn];//最短路径树的边
int s[maxn];//1到k的路径
int size;//路径个数
struct node {
    int v, w;
    node(int _v = 0, int _w = 0) {v = _v, w = _w;}
    bool operator < (const node & o) const {
        return o.w < w;
    }
};
priority_queue<node> pq;
void dijkstra(int s, int t) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0, path[s] = 0;//通用,表示s是起点
    while(pq.size())pq.pop();
    pq.push(node(s, 0));
    while(!pq.empty()) {
        node tmp = pq.top();
        pq.pop();
        int u = tmp.v;
        if(vis[u])continue;
        vis[u] = true;
        for(int i = head[u]; i; i = edges[i].next) {
            int v = edges[i].v;
            int w = edges[i].w;
            if(!vis[v] && dis[v] > w + dis[u]) {
                dis[v] = w + dis[u];
                path[v] = u;//最短路径树上从u到v有边
                pq.push(node(v, dis[v]));
            }
        }
    }
}
int n, m, S, T;
int u, v, w;
int main() {
    n = read(), m = read(), S = read(), T = read();
    for(int i = 0; i <= m; ++i)
        path[i] = i;//初始化:所有点都只到自己
    while(m--) {
        u = read(), v = read(), w = read();
        addEdge(u, v, w);
    }
    dijkstra(S, T);
    int t = T;
    if(dis[t] == INF) {puts("-1"); return 0;}
    while(path[t] != t)
        s[++size] = t, t = path[t];
    //write(size),putchar('\n');
    for(int i = size; i; --i)
        write(s[i]), putchar(' ');
    putchar('\n');
    write(dis[T]);
}
