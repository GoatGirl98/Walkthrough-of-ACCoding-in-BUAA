#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1145141919810ll;
const ll INF_1 = -1ll;
const int maxn = 210;
const int maxm = 2010;
inline void write(ll c) {
    if (c < 0)putchar_unlocked('-'), c = -c;
    if (c > 9)write(c / 10);
    putchar_unlocked(c % 10 + 48);
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
int T;
int n, m;
int u, v;
ll w;
ll h[maxn];
ll d[maxn][maxn];
bool occur[maxn];
struct Edge {
    int v, next;
    ll w;
}edges[maxm];
int head[maxn], cnt;
inline void addEdge(int u, int v, ll w) {
    edges[++cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}
struct node {
    int v; ll w;
    node(int _v = 0, ll _w = 0) {v = _v, w = _w;}
    bool operator < (const node& o) const {
        return o.w < w;
    }
};
queue<int> q;
priority_queue<node> pq;
int enqueue_cnt[maxn];
inline void init() {
    memset(enqueue_cnt, 0, sizeof(enqueue_cnt));
    //memset(edges, 0, sizeof(edges));
    memset(head, 0, sizeof(head));
    memset(occur, false, sizeof(occur));
    cnt = 0;
    while (!q.empty())q.pop();
    while (!pq.empty())pq.pop();
}
inline bool SPFA(int s, ll *d) {
    for(int i = 0; i <= n; ++i) d[i] = INF;
    memset(occur, false, sizeof(occur));
    while (!q.empty())q.pop();
    d[s] = 0;
    occur[s] = true;
    q.push(s);
    enqueue_cnt[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        occur[u] = false;
        for (int e = head[u]; e > 0; e = edges[e].next) {
            int v = edges[e].v, w = edges[e].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!occur[v]) {
                    enqueue_cnt[v]++;
                    if(enqueue_cnt[v] >= n + 1) return false;//因为开了源点,导致该图的节点个数有变化
                    q.push(v);
                    occur[v] = true;
                }
            }
        }
    }
    return true;
}
inline void dijkstra(int s, ll *d) {
    for(int i = 0; i <= n; ++i) d[i] = INF;
    memset(occur, false, sizeof(occur));
    while (!pq.empty())pq.pop();
    d[s] = 0;
    pq.push(node(s, 0));
    while (!pq.empty()) {
        node tmp = pq.top();
        pq.pop();
        int u = tmp.v;
        if (occur[u])continue;
        occur[u] = true;
        for (int i = head[u]; i; i = edges[i].next) {
            int v = edges[i].v;
            int w = edges[i].w;
            if (!occur[v] && d[v] > w + d[u]) {
                d[v] = w + d[u];
                pq.push(node(v, d[v]));
            }
        }
    }
}
inline bool johnson() {
    for(int i = 1; i <= n; ++i) addEdge(0, i, 0);
    if(!SPFA(0, h)) return false;//判负环+势能修正
    
    for(int u = 1; u <= n; ++u) {
        for(int i = head[u]; i; i = edges[i].next) {
            int v = edges[i].v;
            edges[i].w += (h[u] - h[v]);
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        dijkstra(i, d[i]);
        for(int j = 1; j <= n; ++j) {
            if(d[i][j] == INF) d[i][j] = INF_1;//不可达
            else d[i][j] += h[j] - h[i];//势能恢复
        }
    }
    return true;
}
ll max_dis;
int ans_u, ans_v;
int main() {
    T = read();
    while(T--) {
        n = read(), m = read();
        init();
        while (m--) {
            u = read(), v = read(), w = read();
            addEdge(u, v, w);
        }
        johnson();
        max_dis = -INF, ans_u = 0, ans_v = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(d[i][j] > max_dis)
                    max_dis = d[i][j], ans_u = i, ans_v = j;
        write(ans_u), putchar_unlocked(' '), write(ans_v), putchar_unlocked('\n');
    }
}
