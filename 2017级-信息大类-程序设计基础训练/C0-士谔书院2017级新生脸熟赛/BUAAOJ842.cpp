#include<cstdio>
typedef long long ll;
int t;
int k, n, m;
inline ll compose(int n, int m) {
    //组合Ckm的计算,不用担心乘法出问题
    ll ret = 1;
    for (int i = 1; i <= m; ++i) {
        ret *= (1ll * n - 1ll * i + 1ll);
        ret /= (i * 1ll);
    }
    //printf("C(%d, %d) is %lld\n", n, m, ret);
    return ret;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &k, &n, &m);
        //printf("k is %d, n - m is %d\n", k, n - m);
        if (k > n - m) puts("100%");
        else {
            double ans = 100.0;
            ans *= (1.0 - (compose(n - m, k) * 1.0 / compose(n, k)));
            printf("%.0f%%\n", ans);
        }
    }
}
