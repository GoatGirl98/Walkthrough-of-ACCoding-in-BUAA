#include<cstdio>
char map[105][105];
int n, m;
bool flag;
inline bool check(int x, int y) {
    return map[x][y] == '1' && map[x][y + 1] == '0' && map[x][y + 2] == '1' && map[x][y + 3] == '0' && map[x][y + 4] == '1' && map[x + 1][y] == '0' && map[x + 1][y + 1] == '1' && map[x + 1][y + 2] == '0' && map[x + 1][y + 3] == '1' && map[x + 1][y + 4] == '0';
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)scanf("%s", map[i]);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 4; ++j) {
            //printf("i is %d, j is %d\n", i, j);
            flag = check(i, j);
            if (flag) { printf("%d %d", i, j); break; }
        }
        if (flag)break;
    }
    if (!flag)
        printf("error");
}
