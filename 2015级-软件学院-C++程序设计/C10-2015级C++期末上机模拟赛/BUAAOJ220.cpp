#include<cstdio>
#define maxn 35
short a[maxn][maxn];
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                a[i][j] = cnt++;
            }
            for (int j = i + 1; j <= n; ++j) {
                a[j][i] = cnt++;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n - 1; ++j) {
                printf("%d ", a[i][j]);
            }
            printf("%d\n", a[i][n]);
        }
        putchar('\n');
    }
}
