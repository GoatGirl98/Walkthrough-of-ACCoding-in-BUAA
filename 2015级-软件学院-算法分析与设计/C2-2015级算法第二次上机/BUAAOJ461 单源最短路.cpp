#pragma G++ optimize(2)
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define maxn 100010
#define INF 1000000000
#define print 0
using namespace std;
bool occur[maxn];
int d[maxn];
int n, m, k;
int x, y, t;
struct node {
    int v, w;
    node(int _v = 0, int _w = 0) { v = _v; w = _w; }
    bool operator < (const node& o) const {
        return o.w < w;//按照权值排序
    }
};
vector<node>g[maxn];
inline void init() {
    for (int i = 0; i < maxn; ++i) {
        g[i].clear();
        occur[i] = false;
        d[i] = INF;
    }
}
void dijkstra(int s) {
    priority_queue<node>q;
    q.push(node(s, 0));
    d[s] = 0;
    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        int v = tmp.v;
        if (occur[v])continue;
        occur[v] = true;
        for (int i = 0; i < g[v].size(); ++i) {
            int v2 = g[v][i].v;
            int w = g[v][i].w;
            if (print) {
                printf("from v(%d) to v2(%d)\n", v, v2);
                printf("now d[%d(v2)] is %d\n", v2, d[v2]);
            }
            if (!occur[v2] && d[v2] > w + d[v]) {

                d[v2] = w + d[v];
                q.push(node(v2, d[v2]));
            }
        }
    }
}
inline void write(int x) {
    if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        for (int i = 0; i < m; ++i) {
            x = read(), y = read(), t = read();
            g[x].push_back(node(y, t));
            g[y].push_back(node(x, t));
        }
        dijkstra(1);
        bool flag = false;
        for (int i = 2; i <= n; ++i) {
            if (d[i] < INF)write(d[i]);
            else write(-1);
            putchar(' ');
        }
        putchar('\n');
    }
}
