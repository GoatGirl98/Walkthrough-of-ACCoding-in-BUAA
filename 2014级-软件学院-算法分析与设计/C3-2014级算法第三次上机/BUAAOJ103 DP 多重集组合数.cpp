#include<cstdio>
#include<cstring>
#define maxn 1010
typedef unsigned long long ull;
int n, m, MOD;
int a[maxn];
/***************************************************
这个dp倒是还蛮有意思的
如果同一类选了多个的话，是不做区分的
所以对其他的再选一定会有影响
首先dp[i][j]为前i种物品选j个的方案的最大值
dp[i][j] = dp[i][j-1]+dp[i-1][j]
(j<=a[i])
dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1-a[i]]
(j>a[i])
初始状态:dp[i][0]=1
***************************************************/
int dp[2][maxn];
int now, pre;
inline void buildDP() {
	memset(dp, 0, sizeof(dp));
	pre = 0, now = 1;
	dp[pre][0] = dp[now][0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[now][0] = 1;
		for (int j = 1; j <= m; ++j) {
			if (j > a[i])
				dp[now][j] = (dp[now][j - 1] + dp[pre][j] - dp[pre][j - 1 - a[i]] + MOD) % MOD;
			else
				dp[now][j] = (dp[now][j - 1] + dp[pre][j]) % MOD;
		}
		now = 1 - now;
		pre = 1 - pre;
	}
}
int main() {
	while (scanf("%d%d%d", &n, &m, &MOD) != EOF) {
		for (int i = 1; i <= n; ++i)scanf("%d", a + i);
		buildDP();
		printf("%d\n", dp[pre][m]);
	}
}