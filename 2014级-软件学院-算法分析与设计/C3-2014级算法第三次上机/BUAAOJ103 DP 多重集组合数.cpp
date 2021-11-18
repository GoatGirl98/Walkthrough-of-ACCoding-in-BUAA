#include<cstdio>
#include<cstring>
#define maxn 1010
typedef unsigned long long ull;
int n, m, MOD;
int a[maxn];
/***************************************************
���dp���ǻ�������˼��
���ͬһ��ѡ�˶���Ļ����ǲ������ֵ�
���Զ���������ѡһ������Ӱ��
����dp[i][j]Ϊǰi����Ʒѡj���ķ��������ֵ
dp[i][j] = dp[i][j-1]+dp[i-1][j]
(j<=a[i])
dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1-a[i]]
(j>a[i])
��ʼ״̬:dp[i][0]=1
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