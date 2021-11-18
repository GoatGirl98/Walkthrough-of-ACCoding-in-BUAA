#include<cstdio>
#define maxn 310
#define INF 0x3f3f3f3f
typedef unsigned long long ull;
int m[maxn][maxn], s[maxn][maxn];
int a[maxn];
int tmp1, tmp2;
int n;
inline void buildDP_Matrixchain() {
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INF;
            for (int k = i; k < j; ++k) {
                int tmp = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (tmp <= m[i][j])m[i][j] = tmp, s[i][j] = k;
            }
        }
    }
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
inline void print_Matrix(int i, int j) {
    if (i == j)printf("A%d", i);
    else {
        putchar('(');
        print_Matrix(i, s[i][j]);
        print_Matrix(s[i][j] + 1, j);
        putchar(')');
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) a[i - 1] = read(), a[i] = read();
        for (int i = 0; i <= n; ++i)m[i][i] = 0;
        buildDP_Matrixchain();
        printf("%d\n", m[1][n]);
        //print_Matrix(1, n);
        //putchar('\n');
    }
}
