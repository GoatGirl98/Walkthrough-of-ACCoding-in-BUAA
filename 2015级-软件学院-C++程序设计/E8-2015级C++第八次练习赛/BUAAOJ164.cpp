#include<cstdio>
#define maxn 105
int n, m, t;
char map[maxn][maxn];
char tmp[maxn][maxn];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
inline bool illegal(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}
int main() {
    while (scanf("%d%d%d", &n, &m, &t) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", map[i]);
        }
        while (t--) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int alive = 0, slept = 0;
                    for (int k = 0; k < 8; ++k) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (!illegal(nx, ny)) {
                            if (map[nx][ny] == '0')slept++;
                            else alive++;
                        }
                    }
                    if (map[i][j] == '1') {
                        if (alive < 2)tmp[i][j] = '0';
                        else if (alive > 3)tmp[i][j] = '0';
                        else tmp[i][j] = '1';
                    }
                    else {
                        if (alive == 3)tmp[i][j] = '1';
                        else tmp[i][j] = map[i][j];
                    }
                }
            }
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    map[i][j] = tmp[i][j];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                putchar(map[i][j]);
            puts("");
        }
    }
}
