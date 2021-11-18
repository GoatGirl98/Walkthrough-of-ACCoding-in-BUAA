#pragma G++ optimize(2)
#include<cstdio>
#include<climits>
#define maxn 210
#define maxt 15
#define INF 0x3f3f3f3f
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Abs(x) (((x)>0)?(x):(-(x)))
typedef long long ll;
int n, m, t;
int u, v, w;
ll dp[maxn][maxn];
ll res, tmp;
inline void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = Min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }
}
int trans[maxt];
bool occur[maxt];
int route[maxt];
inline void dfs(int level) {
    if (level == t + 1) {
        tmp += dp[route[t]][route[t + 1]];
        res = Min(res, tmp);
        tmp -= dp[route[t]][route[t + 1]];
        return;
    }
    for (int i = 1; i <= t; ++i) {
        if (!occur[i]) {
            occur[i] = true;
            route[level] = trans[i];
            tmp += dp[route[level - 1]][route[level]];
            dfs(level + 1);
            tmp -= dp[route[level - 1]][route[level]];
            route[level] = 0;
            occur[i] = false;
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &t);
    trans[0] = route[0] = 1;
    trans[t + 1] = route[t + 1] = n;
    for (int i = 1; i <= t; ++i) {
        scanf("%d", &trans[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        dp[u][v] = dp[v][u] = Min(dp[u][v], w);
    }
    floyd();
    res = LLONG_MAX; tmp = 0;
    dfs(1);
    printf("%lld\n", res);
}
