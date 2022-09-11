#include<stdio.h>
#include<bitset>
#include<math.h>
using namespace std;
typedef long long ll;
namespace min_25 {
	//Euler Sieve
	bitset<1000010> a;
	unsigned prime[80010], cnt;
	unsigned pi[1000010];
	inline void get_prime(unsigned n) {
		cnt = 0;
		a.set(0), a.set(1);
		unsigned i = 0, j = 0;
		for (i = 2; i <= n; ++i) {
			if (!a.test(i))prime[++cnt] = i;
			pi[i] = cnt;
			for (j = 1; j <= cnt && prime[j] * i <= n; ++j) {
				a.set(i * prime[j]);
				if (i % prime[j] == 0)break;
			}
		}
	}
	//Min_25 Sieve
	static const int M = 1000010;
	int id1[M], id2[M], cntid;
	ll n, m, num[M << 1], f[M << 1];
	inline int Id(ll x) { return x <= m ? id1[x] : id2[n / x]; }
	inline void Min25(ll _n) {
	    n = _n;
		ll l = 1, v;
		cntid = 0;
		m = min(n, (ll)(floor(sqrt(1.0 * n)) + 1));
		if (n <= 1000000) return;
		while (l <= n) {
			v = n / l; if (v <= m) id1[v] = ++cntid; else id2[n / v] = ++cntid;
			num[cntid] = v, f[cntid] = v - 1, l = n / v + 1;
		}
		int i, j;
		for (i = 1; i <= cnt && 1ll * prime[i] * prime[i] <= n; ++i)
			for (v = 1ll * prime[i] * prime[i], j = 1; j <= cntid && num[j] >= v; ++j)
				f[j] -= f[Id(num[j] / prime[i])] - (1ll * i - 1);
	}
	inline ll query(ll x) { return (x <= 1000000) ? pi[x] : f[Id(x)]; }
};
ll n;
int main() {
	min_25::get_prime(1000000);
	min_25::Min25(10000000);
	while (scanf("%lld", &n) != EOF) 
		printf("%lld\n", min_25::query(n));
	
}
