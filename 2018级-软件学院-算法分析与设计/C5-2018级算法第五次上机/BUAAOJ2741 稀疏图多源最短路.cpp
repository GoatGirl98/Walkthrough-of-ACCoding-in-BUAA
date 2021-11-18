#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
const int maxn = 210;
const int maxm = 1010;
const int INF = 0x3f3f3f3f;
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
int t;
int n, m;
int u, v, w;
struct edge {
    int next, to, w;
}edges[maxm];
int head[maxn], cnt;
inline void addedge(int u, int v, int w) {
    edges[cnt].next = head[u];
    edges[cnt].to = v;
    edges[cnt].w = w;
    head[u] = cnt++;
}
int dis[maxn][maxn];
int max_dis;
bool vis[maxn];
struct node {
    int v, w;
    node(int _v = 0, int _w = 0) {v = _v, w = _w;}
    bool operator < (const node & o) const {
        return o.w < w;
    }
};
priority_queue<node> q;
inline void init() {
    memset(dis, 0x3f, sizeof(dis));
    memset(head, 0xff, sizeof(head));
    cnt = 0;
    max_dis = INT_MIN;
}
inline void dijkstra(int s, int* d) {
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    q.push(node(s, 0));
    while(!q.empty()) {
        node tmp = q.top(); q.pop();
        int u = tmp.v;
        if(vis[u])continue;
        vis[u] = true;
        for(int i = head[u]; ~i; i = edges[i].next) {
            int v = edges[i].to, w = edges[i].w;
            if(!vis[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(node(v, d[v]));
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(i == s)continue;
        if(d[i] != INF && d[i] > max_dis) max_dis = d[i];
    }
}
inline void print() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(dis[i][j] != INF && dis[i][j] == max_dis)
                write(i), putchar_unlocked(' '), write(j), putchar_unlocked('\n');
}

int main() {
    t = read();
    while(t--) {
        init();
        n = read(), m = read();
        while(m--) {
            u = read(), v = read(), w = read();
            if(u != v)addedge(u, v, w);
        }
        for(int i = 1; i <= n; ++i) dijkstra(i, dis[i]);
        print();
    }
}
