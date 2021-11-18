#include<cstdio>
#define maxn 510

unsigned long long dp[maxn][maxn];//i,j i被不超过j的数拆分的可能性

inline void buildDP() {
    for (int i = 1; i < maxn; ++i) {
        dp[i][1] = 1ll * 1;
    }
    for (int i = 2; i < maxn; ++i) {
        for (int j = 2; j < i; ++j) {
            int temp = ((j >= i - j) ? i - j : j);
            dp[i][j] = dp[i][j - 1] + dp[i - j][temp];
        }
        dp[i][i] = 1ll * 1 + dp[i][i - 1];
    }
}
int n;
int main() {
    buildDP();
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", dp[n][n]);
    }
}
