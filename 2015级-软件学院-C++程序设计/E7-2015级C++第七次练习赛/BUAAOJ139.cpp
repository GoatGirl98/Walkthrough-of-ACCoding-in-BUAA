#include<cstdio>
#define maxn 101
typedef unsigned long long ull;
ull dp[maxn][maxn];
int n;
/***************************************
杨辉三角状态转移方程:
dp[i][j] = dp[i-1][j]+dp[i-1][j-1]
***************************************/
inline void buildDP() {
    dp[1][1] = 1;
    for (int i = 2; i < maxn; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}
inline void print(int n) {
    for (int i = 1; i <= n; ++i) {
        //for (int j = 0; j < ((n - i) << 2); ++j) putchar(' ');
        for (int j = 1; j <= i; ++j) {
            //printf("%4llu    ", dp[i][j]);
            printf("%llu ", dp[i][j]);
        }
        putchar('\n');
    }
    //putchar('\n');
}
int main() {
    buildDP();
    while (scanf("%d", &n) != EOF)print(n);
}
