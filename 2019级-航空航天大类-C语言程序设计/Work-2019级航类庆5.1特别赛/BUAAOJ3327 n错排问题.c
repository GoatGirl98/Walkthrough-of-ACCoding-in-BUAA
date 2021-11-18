#include<stdio.h>
#define mod 1000000007
typedef long long ll;
ll dp[1010];
int n;
int main() {
	scanf("%d", &n);
	dp[1] = 0, dp[2] = 1, dp[3] = 2;
	for (int i = 4; i <= 1000; ++i)
		dp[i] = (i * 1ll - 1ll) * (dp[i - 1] + dp[i - 2]), dp[i] %= mod;
	printf("%lld", dp[n]);
}