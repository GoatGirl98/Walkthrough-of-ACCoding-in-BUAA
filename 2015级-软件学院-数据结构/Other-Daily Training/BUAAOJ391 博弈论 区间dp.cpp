#pragma G++ optimize(2)
#include<cstdio>
#include<cstring>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define maxn 110
int a[maxn], dp[maxn][maxn], sum[maxn][maxn];
int n;
inline void buildSum() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum[i][j] = sum[i][j - 1] + a[j];
        }
    }
}
inline void buildDP() {
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            dp[i][j] = sum[i][j] - Min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        dp[i][i] = sum[i][i] = a[i];
    }
    buildSum(), buildDP();
    printf("%d %d\n", dp[0][n - 1], sum[0][n - 1] - dp[0][n - 1]);
}
