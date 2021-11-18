#include<cstdio>
long long dp[55];
int n;
inline void buildDP() {
    dp[0] = 1, dp[1] = 1;
    dp[2] = 2, dp[3] = 4;
    dp[4] = 7;
    for (int i = 5; i < 55; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 4] + dp[i - 5];
}
int main() {
    buildDP();
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", dp[n]);
}
