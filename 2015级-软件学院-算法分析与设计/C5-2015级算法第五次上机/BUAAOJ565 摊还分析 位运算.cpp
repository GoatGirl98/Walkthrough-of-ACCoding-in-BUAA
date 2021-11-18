#include<cstdio>
#include<cstring>
typedef long long ll;
const ll radix = 1ll << 31;
ll n, x, cnt, tmp;
inline ll realCost(ll Xor) {
    ll ret = 0;
    while (Xor)ret++, Xor = Xor & (Xor - 1);
    return ret;
}
int main() {
    while (scanf("%lld%lld", &n, &x) != EOF) {
        for (ll i = 1; i <= n; ++i) {
            scanf("%lld", &cnt);
            printf("Case %lld:\n", i);
            for (ll j = 1; j <= cnt; ++j) {
                tmp = x;
                x = (x + 1) % radix;
                printf("%lld ", realCost(x ^ tmp));
                if (!x)puts("0"); else puts("2");
            }
            printf("Sum: %lld\n", x);
        }
    }
}
