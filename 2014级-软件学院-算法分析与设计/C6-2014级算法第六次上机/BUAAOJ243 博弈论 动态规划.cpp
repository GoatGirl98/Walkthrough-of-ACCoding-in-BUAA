#include<cstdio>
#include<cstring>
#define maxn 100010
int n, k;
bool dp[maxn];
int take[20];
int main() {
	while (scanf("%d%d", &n, &k) != EOF) {
		memset(dp, false, sizeof(dp));
		memset(take, 0, sizeof(take));
		for (int i = 1; i <= k; ++i)
			scanf("%d", take + i);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= k; ++j)
				if (i - take[j] >= 0 && !dp[i - take[j]]) {
					dp[i] = true; break;
				}
		//�˴�˵���˾�����ռ�Ȼ�,�����������ʯ�Ӿ;��������ȹ�
		puts(dp[n] ? "sente" : "gote");
	}
}