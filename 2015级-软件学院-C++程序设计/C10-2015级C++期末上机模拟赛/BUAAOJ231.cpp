#pragma G++ optimize(2)
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 110
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
int height[maxn][maxn];
int occur[maxn][maxn];
int n, m, k;
int u, v;
queue<PII> q;
int nx[4] = { 1,-1,0,0 };
int ny[4] = { 0,0,1,-1 };
inline bool islegal(int a, int b) {
    return a <= n && a >= 1 && b <= m && b >= 1;
}
inline void bfs() {
    while (!q.empty()) {
        PII a = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            if (!occur[a.x + nx[i]][a.y + ny[i]] && height[a.x][a.y] >= height[a.x + nx[i]][a.y + ny[i]] && islegal(a.x + nx[i], a.y + ny[i])) {
                occur[a.x + nx[i]][a.y + ny[i]] = 1;
                q.push(mp(a.x + nx[i], a.y + ny[i]));
            }
        }
    }
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(occur, 0, sizeof(occur));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &height[i][j]);
            }
        }
        scanf("%d", &k);
        while (!q.empty())q.pop();
        while (k--) {
            scanf("%d%d", &u, &v);
            if (!occur[u][v]) {
                occur[u][v] = 1;
                q.push(mp(u, v));
            }
        }
        bfs();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                printf("%d", occur[i][j]);
            }
            puts("");
        }
    }
}
