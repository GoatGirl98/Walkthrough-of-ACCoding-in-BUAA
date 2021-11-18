#include<cstdio>
#define MOD 1000000007
#define maxn 100010
typedef long long ll;
ll dp[maxn];
//×´Ì¬×ªÒÆ:dp[k]=kdp[k-1]+(k-1)*(k-1)!
inline void buildDP() {
	dp[0] = dp[1] = 0;
	dp[2] = 1, dp[3] = 7;
	ll factor = 6;
	for (int i = 4; i <= 100000; ++i) {
		dp[i] = ((i * dp[i - 1]) % MOD + ((factor % MOD) * (i - 1)) % MOD) % MOD;
		factor = (factor * i) % MOD;
	}
}
int Case;
int n;
int main() {
	buildDP();
	while (scanf("%d", &n) != EOF)
		printf("Case #%d: %lld\n", ++Case, dp[n]);
}
