#include<cstdio>
#include<algorithm>
#define mp make_pair
#define p first
#define q second
#define maxn 10
using namespace std;
typedef long long ll;
typedef pair<ll, ll>PLL;
int n;
ll a[maxn], b[maxn];
ll gcd(ll a, ll b) {
	while (b ^= a ^= b ^= a %= b);
	return a;
}
PLL dfs(int i) {
	if (i == n) { ll g = gcd(a[n], b[n]); return mp(b[n] / g, a[n] / g); }
	PLL tmp = dfs(i + 1);
	ll P = b[i] * tmp.q;
	ll Q = a[i] * tmp.q + tmp.p;
	ll g = gcd(P, Q);
	return mp(P / g, Q / g);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)scanf("%lld", a + i);
	for (int i = 1; i <= n; ++i)scanf("%lld", b + i);
	PLL res = dfs(1);
	printf("%lld %lld", res.p, res.q);
}