#include<cstdio>
#define maxn 1010
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
typedef long long ll;
int value[maxn][maxn];
ll dp[maxn][maxn];
ll ans;
int n;
inline void buildDP() {
    dp[1][1] = 1ll * value[1][1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = Max(dp[i - 1][j - 1],dp[i - 1][j])+1ll * value[i][j];
        }
    }
    ans = -2147483647;
    for (int i = 1; i <= n; ++i)ans = Max(ans, dp[n][i]);
    printf("%lld\n", ans);
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                scanf("%d", &value[i][j]);
            }
        }
        buildDP();
    }
}
