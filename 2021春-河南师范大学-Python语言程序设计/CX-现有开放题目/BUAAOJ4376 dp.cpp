#include<stdio.h>
#define maxn 101
typedef unsigned long long ull;
ull dp[maxn][maxn];
int n;
/***************************************
杨辉三角状态转移方程:
dp[i][j] = dp[i-1][j]+dp[i-1][j-1]
***************************************/
void wr(ull x) {
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
void buildDP() {
    dp[1][1] = 1;
    int i = 0, j = 0;
    for (i = 2; i < maxn; ++i) {
        for (j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}
void print(int n) {
    putchar('[');
    int i = 0, j = 0;
    for (i = 1; i <= n; ++i) {
        putchar('[');
        for (j = 1; j <= i; ++j) {
            wr(dp[i][j]);
            if (j < i) putchar(','), putchar(' ');
        }
        putchar(']');
        if (i < n) putchar(','), putchar(' ');
    }
    putchar(']');
    putchar('\n');
}
int main() {
    buildDP();
    while (scanf("%d", &n) != EOF)print(n);
}