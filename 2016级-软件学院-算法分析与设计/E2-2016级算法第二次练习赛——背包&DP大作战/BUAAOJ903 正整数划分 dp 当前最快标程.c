#include <stdio.h>
#define N 50005
#define P 1000007
typedef long long ll;
ll f[N], g[N], dp[N];
int n;
int i, j;
int main() {
    for (i=1;i<=50000;++i) f[i] = (ll)i * (3 * i - 1) / 2;
    for (i=1;i<=50000;++i) g[i] = (ll)i * (3 * i + 1) / 2;
    dp[0] = 1;
    for (i=1;i<=50000;++i) {
        for (j = 1; f[j] <= i; j++)
            if (j & 1) {
                dp[i] += dp[i - f[j]];
                if (g[j] <= i)
                    dp[i] += dp[i - g[j]];
            } else {
                dp[i] -= dp[i - f[j]];
                if (g[j] <= i)
                    dp[i] -= dp[i - g[j]];
            }
        dp[i] %= P;
        if (dp[i] < 0)
            dp[i] += P;
    }
    while(scanf("%d", &n) != EOF)printf("%lld\n", dp[n]);
}
