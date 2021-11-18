#include<cstdio>
#include<cmath>
typedef long long ll;
int n, k;
ll res;
ll last, now;
int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        res = 0;
        scanf("%lld", &now);
        last = now;
        for (int i = 2; i <= n; ++i) {
            res += 1ll * k * ((1ll * now - 1ll * last == 0) ? 0 : 1);
            last = now;
            scanf("%lld", &now);
        }
        res += 1ll * k * ((1ll * now - 1ll * last == 0) ? 0 : 1);
        printf("%lld\n", res);
    }
}
