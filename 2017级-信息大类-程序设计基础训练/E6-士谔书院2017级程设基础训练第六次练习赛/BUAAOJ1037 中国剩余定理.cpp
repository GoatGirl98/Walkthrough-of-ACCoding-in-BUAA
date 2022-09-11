#include<cstdio>
#include<cstring>
#define maxn 15
typedef long long ll;
ll divisor[maxn], remainder[maxn];
int n;
ll GCD, LCM;
ll ans;
ll gcd(ll a, ll b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
inline ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) { x = 1, y = 0; return a; }
    ll q = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return q;
}
inline ll chinaRemain() {
    ll ret = 0, mod = 1;
    for (int i = 1; i <= n; ++i)mod *= divisor[i];
    for (int i = 1; i <= n; ++i) {
        ll m, p, d, y;
        m = mod / divisor[i];
        d = exgcd(m, divisor[i], p, y);
        ret = (ret + m * p * remainder[i]) % mod;
    }
    while(ret < 0)ret += mod;
    return ret;
}
int main() {
    n = 3;
    while (scanf("%lld%lld%lld%lld%lld%lld", divisor + 1, remainder + 1,  divisor + 2,  remainder + 2,  divisor + 3, remainder + 3) != EOF) {
        GCD = divisor[1], LCM = divisor[1];
        for(int i = 2; i <= 3; ++i)
            LCM = lcm(LCM, divisor[i]);
        ans = chinaRemain();
        printf("%lld\n", ans + (ans == 1 ? LCM : 0));
    }
}
