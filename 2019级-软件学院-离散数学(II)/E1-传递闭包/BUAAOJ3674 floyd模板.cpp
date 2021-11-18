#include<cstdio>
#define INF 0x3f3f3f3f
typedef long long ll;
ll dp[105][105];
int n;
void floyd() {
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%lld", &dp[i][j]);
            if(dp[i][j] == 0)dp[i][j] = INF;
        }
    }
    floyd();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            printf("%d ", dp[i][j] < INF ? 1 : 0);
        }
        putchar('\n');
    }
}

