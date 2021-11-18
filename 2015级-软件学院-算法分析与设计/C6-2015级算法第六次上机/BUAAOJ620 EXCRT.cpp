#include<cstdio>
#include<cstring>
#define maxn 100015
typedef long long ll;
ll divisor[maxn], remainder[maxn];
int n;
inline ll AmulBmodP(ll a, ll b, ll p) {
    ll ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % p;
        a = (a << 1) % p;
        b >>= 1;
    }
    return ret;
}
inline ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) { x = 1, y = 0; return a; }
    ll q = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return q;
}
inline ll EXCRT() {
    ll x, y, k, M=divisor[1], ans=remainder[1];
    for(int i=2;i<=n;i++) {
        ll c=(remainder[i] - ans % divisor[i] + divisor[i]) % divisor[i];
        ll t=exgcd(M, divisor[i], x, y), bg = divisor[i] / t;
        if(c % t) return -1;
        x = AmulBmodP(x, c / t, bg);     //x可能是负的
        ans += x * M;
        M *= bg;
        ans = (ans % M + M ) % M;
    }
    return (ans % M + M) % M;
}
int main() {
    n = 3;
    divisor[1] = 25, divisor[2] = 28, divisor[3] = 33;
    while (scanf("%lld%lld%lld", remainder + 1, remainder + 2, remainder + 3) != EOF)
        printf("%lld\n", EXCRT());
}
