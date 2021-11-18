#pragma GCC optimize(2)
#include<stdio.h>
#define maxn 105
typedef long long ll;
int dp[maxn][maxn];
inline void buildDP() {
    dp[1][1] = 1;
    for (int i = 2; i < maxn; ++i) dp[1][i] = dp[i][1] = 1;
    for (int i = 2; i < maxn; ++i) {
        for (int j = 2; j < i; ++j) {
            dp[i][j] = ((i - j >= j) ? dp[i - j][j] : dp[i - j][i - j]) + dp[i][j - 1];
        }
        dp[i][i] = 1 + dp[i][i - 1];
    }
}
int t, m, n;
int main() {
    buildDP();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        if (m < n)printf("%d\n", dp[m][m]);
        else printf("%d\n", dp[m][n]);
    }
}
