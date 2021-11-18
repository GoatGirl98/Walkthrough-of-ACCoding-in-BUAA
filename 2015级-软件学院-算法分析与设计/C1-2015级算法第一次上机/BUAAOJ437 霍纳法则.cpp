#include<cstdio>
#include<cstring>
typedef long long ll;
const int maxn = 10000 + 10;
const int MOD = 1000007;
int n, x, t;
int a[maxn];
int Case;
ll ans;
int main() {
    while (scanf("%d%d%d", &n, &x, &t) != EOF) {
        printf("Case #%d:\n", ++Case);
        while (t--) {
            for (int i = 0; i <= n; ++i)scanf("%d", a + i);
            ans = 0;
            for (int i = n; i >= 0; --i) {
                ans = ((ans * x) % MOD + a[i]) % MOD;
            }
            printf("%lld\n", ans);
        }
    }
}
