#include<stdio.h>
#include<string.h>
#define max(a,b) (((a)>(b))?(a):(b))
typedef long long ll;
ll a[1010];
ll dp[1010][1010][2];
int n, k;
void buildDP() {
    for(int i = 0; i <= k; ++i) dp[1][i][1] = -a[1];
    for(int i = 2; i <= n; ++i) {
        dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - a[i]);
        for(int j = 1; j <= k; ++j) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + a[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - a[i]);
        }
    }
}
int main() {
    while(scanf("%d%d", &n, &k) != EOF) {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        buildDP();
        printf("%lld\n", dp[n][k][0]);
    }
}
