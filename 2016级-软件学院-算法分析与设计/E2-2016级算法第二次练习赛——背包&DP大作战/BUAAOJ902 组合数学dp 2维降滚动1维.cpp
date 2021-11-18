#include <cstdio>
#include <cstring>
#define MOD 1000007
int n;
int dp[50005][2];
int ans = 0;
inline void buildDP() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    ans = 0;
    for (int i = 1; i < 350; ++i) {
        for (int j = 0; j < 350; ++j)
            dp[j][i&1] = 0;

        for (int j = 0; j <= n; ++j) {
            if (j - i >= 0)
                dp[j][i&1] = (dp[j - i][i&1] + dp[j - i][(i - 1)&1]) % MOD;
        }
        ans = (ans + dp[n][i&1]) % MOD;
    }
}
int main() {
    while(scanf("%d", &n) != EOF) {
        buildDP();
        printf("%d\n", ans);
    }
}
