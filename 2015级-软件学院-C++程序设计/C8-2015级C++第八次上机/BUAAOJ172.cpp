#include<cstdio>
#include<cstring>
#define maxn 1010
int a[maxn][maxn];
int n, m;
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", a[i] + j);
        for (int i = n; i; --i) {
            for (int j = m; j; --j)
                printf("%d ", a[i][j]);
            puts("");
        }
    }

}
