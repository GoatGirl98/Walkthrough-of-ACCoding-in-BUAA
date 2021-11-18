#include<stdio.h>
typedef long long ll;
typedef __int128 lll;
const ll mod = 1000000007;
ll n, ans;
ll mul(ll a, ll b) { return (lll)a * (lll)b % (lll)mod; }
ll int_sqrt(ll x) {
	if (x <= 1)
		return x;
	ll ret = x;
	ll rett = (ret + (x / ret)) >> 1;
	while (rett < ret) {
		ret = rett;
		rett = (ret + (x / ret)) >> 1;
	}
	return ret;
}
int main() {
	scanf("%lld", &n);
	n = int_sqrt(n), ans = 1;
	ll b = n, c = n + 1, d = (n << 1) + 1;
	if (b % 2 == 0)
		b >>= 1;
	else
		c >>= 1;
	if (b % 3 == 0)
		b /= 3;
	else if (c % 3 == 0)
		c /= 3;
	else
		d /= 3;
	ans = mul(ans, b), ans = mul(ans, c), ans = mul(ans, d);
	printf("%lld", ans);
}