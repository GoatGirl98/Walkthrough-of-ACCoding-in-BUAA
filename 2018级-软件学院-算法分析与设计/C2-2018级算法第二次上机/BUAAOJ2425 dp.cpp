#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100010;
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
ll n;
ll a[maxn];
ll score, max_score;
ll dp[maxn];
inline void buildDP() {
    dp[1] = a[1];
    dp[2] = max(a[1], a[2]);
    for(int i = 3; i <= max_score; ++i)
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
}
int main() {
    n = read();
    while(n--) {
        score = read();
        max_score = max(max_score, score);
        a[score] += score;
    }
    buildDP();
    printf("%lld\n", dp[max_score]);
}
