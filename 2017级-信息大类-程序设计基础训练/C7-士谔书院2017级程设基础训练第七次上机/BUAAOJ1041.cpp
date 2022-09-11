#include<cstdio>
#include<cstring>
#define maxn 15
int a[maxn][maxn];
int n;
//hint:传参多维数组时，最后一维的长度必须有，且注意[][]与**在c/c++中有本质区别
int det(int a[][maxn], int x) {
    if (x == 1) return a[0][0];
    int b[maxn][maxn];
    int ret = 0;
    int cur = 1;
    //展开定理
    for (int k = 0; k < x; ++k) {
        for (int i = 1; i < x; ++i) {
            int sit = 0;
            for (int j = 0; j < x; ++j) {
                if (j == k)continue;
                b[i - 1][sit++] = a[i][j];
            }
        }
        ret += cur * a[0][k] * det(b, x - 1);
        cur *= -1;
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d\n", det(a, n));
}
