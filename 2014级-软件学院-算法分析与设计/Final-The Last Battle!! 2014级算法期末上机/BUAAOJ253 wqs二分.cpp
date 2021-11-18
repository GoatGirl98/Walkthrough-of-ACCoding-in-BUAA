#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100010;
const ll INF = 1145141919810ll;
int n, k;
ll a[maxn];
ll dp[maxn], tp[maxn], sum;//dp是在给定c下取到的权值  tp是用了多少对
inline void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline ll read() {
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
inline bool solve(ll c) {
    tp[0] = dp[0] = 0;
    for(int i = 1; i <= n; ++i) dp[i] = sum, tp[i] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1], tp[i] = tp[i - 1];
        if(dp[i - 2] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]) + c < dp[i]) {
            dp[i] = dp[i - 2] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]) + c;
            tp[i] = tp[i - 2] + 1;
        }
        else if(dp[i - 2] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]) + c == dp[i] && tp[i - 2] + 1 > tp[i])
            tp[i] = tp[i - 2] + 1;
    }
    return tp[n] >= k;
}
int main() {
    while(scanf("%d%d", &n, &k) != EOF) {
        sum = 0;
        for(int i = 1; i <= n; ++i) a[i] = read(), sum += a[i] * a[i];
        sort(a + 1, a + n + 1);
        ll lo = -INF, mi = -INF, hi = 0;
        while(hi > lo) {
            mi = (hi + lo) >> 1;
            if(!solve(mi)) hi = mi;
            else lo = mi + 1;
        }
        solve(lo - 1);
        write(dp[n] - 1ll * k * (lo - 1)), putchar_unlocked('\n');
    }
}
