#include<cstdio>
#include<cstring>
#define debug 0
typedef long long ll;
const int maxn = 60 + 5;
int n;
const char tower[4] = { '0','A','B','C' };
int start[maxn], finish[maxn];
int backup_start[maxn];
bool flag;
ll ans, backup_ans;
int number, size;
inline void dfs(int x, int y) {//盘子 目标柱
    if(debug) printf("now in dfs %d %d\n", x, y);
    if (backup_start[x] == y)return;
    for (int i = x - 1; i >= 1; --i) {
        if (backup_start[i] != 6 - backup_start[x] - y)
            dfs(i, 6 - backup_start[x] - y);
    }
    if(flag)printf("move %d from %c to %c\n", x, tower[backup_start[x]], tower[y]);
    backup_start[x] = y, ans++;
}
inline void normal_dfs() {
    for (int i = n; i >= 1; --i)dfs(i, finish[i]);
}
inline void special_dfs() {
    bool em = false;
    for (int i = n; i >= 1; --i) {
        if (!em && finish[i] != start[i]) {
            dfs(i, 6 - start[i] - finish[i]);
            dfs(i, finish[i]);
            em = true;
        }
        else dfs(i, finish[i]);
    }
}
int main() {
    while (scanf("%d", &n) != EOF && n) {
        flag = false;
        ans = 0;
        memset(start, 0, sizeof(start));
        memset(finish, 0, sizeof(finish));
        for (int i = 1; i <= n; ++i)scanf("%d", &number), start[i] = number;
        for (int i = 1; i <= n; ++i)scanf("%d", &number), finish[i] = number;
        for (int i = 1; i <= n; ++i)backup_start[i] = start[i];
        normal_dfs();
        backup_ans = ans;
        ans = 0;
        for (int i = 1; i <= n; ++i)backup_start[i] = start[i];
        special_dfs();
        //flag = true;
        for (int i = 1; i <= n; ++i)backup_start[i] = start[i];
        if (backup_ans < ans) {
            normal_dfs();
            printf("%lld\n", backup_ans);
        }
        else {
            ans = 0;
            special_dfs();
            printf("%lld\n", ans);
        }
    }
}
