#include<cstdio>
#include<cstring>
#define maxn 15
int n, m;
int startx, starty;
int endx, endy;
int nx[4] = { -1,0,1,0 };
int ny[4] = { 0,1,0,-1 };
inline bool illegal(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}
int map[maxn][maxn];
bool occur[maxn][maxn];
bool flag;
inline void dfs(int x, int y) {
    occur[x][y] = false;
    if (map[x][y] == 1) { occur[x][y] = true; return; }
    if (x == endx && y == endy) {
        flag = true;
        occur[x][y] = true;
        return;
    }
    int dx, dy;
    for (int i = 0; i < 4; ++i) {
        dx = x + nx[i], dy = y + ny[i];
        if (illegal(dx, dy))continue;
        if (!occur[dx][dy])continue;
        dfs(dx, dy);
    }
    occur[x][y] = true;
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        startx = starty = endx = endy = 0;
        memset(map, 0, sizeof(map));
        memset(occur, true, sizeof(occur));
        flag = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &map[i][j]);
                if (map[i][j] == 2)startx = i, starty = j;
                if (map[i][j] == 3)endx = i, endy = j;
            }
        }
        if (!startx || !endx) { puts("No"); continue; }
        dfs(startx, starty);
        if (flag)puts("Yes"); else puts("No");
    }
}
