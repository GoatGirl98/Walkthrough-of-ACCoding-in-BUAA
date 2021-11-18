#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 2010
#define maxm 114514
#define mp make_pair
#define x first
#define y second
#define debug 0
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
inline void write(int c) {
    if (c < 0)putchar('-'), c = -c;
    if (c > 9)write(c / 10);
    putchar(c % 10 + 48);
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
int d[maxn][maxn];
int di[maxn];
bool occur[maxn][maxn]; // 是否计算过到i走j条边
struct Edge {
    int v, w, next;
}edges[maxm];
int head[maxn], cnt;
inline void addEdge(int u, int v, int w) {
    edges[++cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}
int T;
int n, m, q, s, t, dt, u, v, w;
queue<PII> Q;
inline void init() {
    memset(edges, 0, sizeof(edges));
    memset(d, 0x3f, sizeof(d));
    memset(di, 0x3f, sizeof(di));
    memset(head, 0, sizeof(head));
    memset(occur, false, sizeof(occur));
    cnt = 0;
    while (!Q.empty())Q.pop();
}
inline void SPFA(int s) {
    d[s][0] = di[s] = 0;
    occur[s][0] = true;
    Q.push(mp(s, 0));
    while (!Q.empty()) {
        PII p = Q.front();
        int X = p.x, Y = p.y;
        for (int e = head[X]; e > 0; e = edges[e].next) {
            int v = edges[e].v, w = edges[e].w;
            if (d[v][Y + 1] > d[X][Y] + w) {
                d[v][Y + 1] = d[X][Y] + w;
                if (d[v][Y + 1] >= di[v]) continue;
                else di[v] = d[v][Y + 1];
                if (!occur[v][Y + 1]) {
                    Q.push(mp(v, Y + 1));
                    occur[v][Y + 1] = true;
                }
            }
        }
        Q.pop();
        occur[X][Y] = false;
    }
}
int main() {
    T = read();
    while (T--) {
        init();
        n = read(), m = read(), q = read();
        while (m--) {
            u = read(), v = read(), w = read();
            addEdge(u, v, w);
        }
        s = read(), t = read();
        SPFA(s);
        int L = 0, R = 0;
        //确定暴力枚举的查询区间
        for (int i = 0; i <= n; ++i) {
            if (d[t][i] != INF) {
                if (!L)L = i;
                R = i;
            }
        }
        while (q--) {
            dt = read();
            int ans = INF;
            for (int j = L; j <= R; ++j) {
                if (d[t][j] != INF) {
                    if (d[t][j] + j * dt < ans) ans = d[t][j] + j * dt;
                }
            }
            write(ans), putchar('\n');
        }
    }
}
