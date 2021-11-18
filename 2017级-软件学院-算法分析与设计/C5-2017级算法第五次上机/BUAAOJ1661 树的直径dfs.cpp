#include<cstdio>
#include<cstring>
#include<climits>
#include<vector>
#include<algorithm>
#define maxn 100010
using namespace std;
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
int dis[maxn];
vector<int> g[maxn];
int n, m;
int u, v;
inline void init() {
    memset(dis, 0, sizeof(dis));
    for (int i = 1; i < maxn; ++i)g[i].clear();
}
void dfs(int u, int step) {
    if (dis[u])return;
    dis[u] = step;
    for (int i = 0; i < g[u].size(); ++i) {
        dfs(g[u][i], step + 1);
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 1; i <= n; ++i) {
            u = read(), v = read();
            if (v) {
                g[i].push_back(v);
                g[v].push_back(i);
            }
            if (u) {
                g[i].push_back(u);
                g[u].push_back(i);
            }
        }
        dfs(1, 1);
        int max = 0, maxIndex = 0;
        for (int i = 1; i <= n; ++i)
            if (dis[i] > max)
                max = dis[i], maxIndex = i;
        memset(dis, 0, sizeof(dis));
        dfs(maxIndex, 1);
        max = 0;
        for (int i = 1; i <= n; ++i)
            if (dis[i] > max)
                max = dis[i];
        write(max - 1), putchar('\n');
    }
}
