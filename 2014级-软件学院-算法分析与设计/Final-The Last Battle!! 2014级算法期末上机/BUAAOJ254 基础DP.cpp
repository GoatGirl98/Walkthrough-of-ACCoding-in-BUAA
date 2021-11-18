#include<cstdio>
#include<cstring>
#define maxn 100005
typedef unsigned long long ull;

ull dp[maxn];
ull tmp[maxn];
ull n, k;
ull a[40];
inline ull buildDP() {
	ull ret = 0;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		memset(tmp, 0, sizeof(tmp));
		for (int j = 0; j < maxn - a[i]; ++j) {
			tmp[j + a[i]] = dp[j];
			//if (dp[j])printf("tmp[%llu] is dp[%d]:%llu\n", j + a[i], j, dp[j]);
		}
		for (int j = 0; j < maxn; ++j) {
			dp[j] += tmp[j];
		}
	}
	for (int i = k; i < maxn; ++i)ret += dp[i];
	return ret;
}
int main() {
	while (scanf("%llu%llu", &n, &k) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%llu", a + i);
		}
		printf("%llu\n", buildDP());
	}
}