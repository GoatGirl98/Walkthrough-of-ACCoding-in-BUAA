#include<cstdio>
#include<cstring>
#define maxn 15
typedef long long ll;
ll divisor[maxn], remainder[maxn];
int n;
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
inline void init() {
	n = 3, divisor[1] = 25, divisor[2] = 28, divisor[3] = 33;
}
int main() {
	/*
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; ++i)
			scanf("%lld%lld", divisor + i, remainder + i);
		printf("%lld\n", chinaRemain());
	}
	*/
	init();
	while (scanf("%lld%lld%lld", remainder + 1, remainder + 2, remainder + 3) != EOF) {
		printf("%lld\n", chinaRemain());
	}
}