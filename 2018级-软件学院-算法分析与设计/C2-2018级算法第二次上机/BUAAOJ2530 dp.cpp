#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll MOD = 100000007;
inline void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline ll read() {
    ll k = 0, f = 1;
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
ll a[1010];
ll dp[1010][1010];
ll n, k;
ll ret;
ll solve(int x) {//x<=|ai-aj|的子序列个数
    dp[0][0] = 1;
    int Li = 0;
    for(int i = 1; i <= n; ++i) {
        while(a[i] - a[Li + 1] >= x) ++Li;
        dp[i][0] = dp[i - 1][0];
        for(int j = 1; j <= k && j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[Li][j - 1];
            dp[i][j] %= MOD;
        }
    }
    return dp[n][k];
}

int main() {
    n = read(), k = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + n + 1);
    for(int i = 1; i * (k - 1) <= a[n] - a[1]; ++i)
        ret += solve(i), ret %= MOD;
    write(ret);
}
