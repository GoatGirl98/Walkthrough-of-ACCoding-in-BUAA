#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cctype>
#define maxn 55
#define INF 0x3f3f3f3f
using namespace std;
inline int read() {
    char c = getchar();
    while (isspace(c))c = getchar();
    if (islower(c))return c - 'a' + 1;
    else return c - 'A' + 27;
}
inline int Trans(int a) {
    if (a <= 26)return a + 'a' - 1;
    else return a + 'A' - 27;
}
bool occur[maxn];
int d[maxn];
int m;
int x, y, t;
struct node {
    int v, w;
    node(int _v = 0, int _w = 0) { v = _v, w = _w; }
    bool operator <(const node& o)const {
        return o.w < w;
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
            if (!occur[v2] && d[v2] > w + d[v]) {

                d[v2] = w + d[v];
                q.push(node(v2, d[v2]));
            }
        }
    }
}
int main() {
    scanf("%d", &m);
    init();
    for (int i = 0; i < m; ++i) {
        x = read(), y = read();
        scanf("%d", &t);
        g[x].push_back(node(y, t));
        g[y].push_back(node(x, t));
    }
    dijkstra(52);
    int ans = d[27], idx = 27;
    for (int i = 27; i < 52; ++i) {
        if (ans > d[i])ans = d[i], idx = i;
    }
    putchar(Trans(idx)), putchar(' ');
    printf("%d\n", d[idx]);
}
