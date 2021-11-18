#include<cstdio>
long long dp[2][55];
int n;
inline void buildDP() {
    dp[0][1] = 1, dp[1][1] = 0;
    dp[0][2] = 2, dp[1][2] = 0;
    dp[0][3] = 3, dp[1][3] = 1;
    for (int i = 4; i < 55; ++i) {
        dp[0][i] = dp[0][i-1] + dp[0][i-2] + dp[1][i-1] + dp[1][i-2];
        dp[1][i] = dp[0][i-3];
    }
}
int main() {
    buildDP();
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", dp[0][n] + dp[1][n]);
}
