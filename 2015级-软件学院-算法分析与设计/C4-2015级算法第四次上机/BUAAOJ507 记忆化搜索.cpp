#include<cstdio>
#include<cstring>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))

/***********************************
成了，看过题解的复杂度分析之后
这题没办法，老老实实搜索做吧
***********************************/
int map[105][105];
bool occur[105][105];
int tmp[105][105];
int dp[105][105];
int r, c;
int nx[4] = { 1,0,-1,0 };
int ny[4] = { 0,1,0,-1 };
inline bool isLegal(int x, int y) {
    return x > 0 && x <= r && y > 0 && y <= c;
}
inline bool debug(int x, int y) {
    return x == 3 && y == 2 && false;
}
inline int dfs(int x, int y) {
    if (occur[x][y])return dp[x][y];
    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int dx = x + nx[i];
        int dy = y + ny[i];
        if (isLegal(dx, dy) && map[dx][dy] > map[x][y]) {
            int tmp = 1 + dfs(dx, dy);
            ret = Max(ret, tmp);
        }
    }
    occur[x][y] = true;
    dp[x][y] = ret;
    return ret;
}
int main() {
    while (scanf("%d%d", &r, &c) != EOF) {
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j)
                scanf("%d", &map[i][j]);
        memset(occur, false, sizeof(occur));
        int ans = 1;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                int tmp = dfs(i, j);
                ans = Max(ans, tmp);
            }
        }
        printf("%d\n", ans);
    }
}
