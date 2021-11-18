#include<cstdio>
#include<cstring>
#define maxn 105
double res[maxn][maxn];//i j 为打完i盘赢了j局 但是没到胜率的概率
int t;
int a, b, n;
double p;
inline void buildDP() {
    memset(res, 0, sizeof(res));
    res[0][0] = 1.0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j * b <= i * a; ++j) {
            if (j == 0)res[i][j] = res[i - 1][j] * (1 - p);
            else res[i][j] = res[i - 1][j] * (1 - p) + res[i - 1][j - 1] * p;
        }
    }
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d/%d %d", &a, &b, &n);
        double ans = 0.0;
        p = (double)a / (double)b;
        buildDP();
        for (int i = 0; i <= n; ++i)ans += res[n][i];
        printf("%d\n", (int)(1 / ans));
    }
}
