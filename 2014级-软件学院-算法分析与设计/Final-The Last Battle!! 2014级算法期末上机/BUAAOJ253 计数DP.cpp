#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
/**************************************************
����dp��������Ŀһ�㶼��ʹ��dp[i][j]
����ʽ���
��������ǰi����Ʒȡj�Ե���С����
���a<b<c<d ��ô(a-b)^2+(c-d)^2������С

Ȼ��
i = 2jʱ
dp[i][j] = dp[i-2][j-1]+...
�������
dp[i][j] = max(dp[i-1][j],dp[i-2][j-1]+...)
��ʼ:dp[2][1],dp[1][1]...��ϸ����һ�¶�����Ҫ����
**************************************************/
const int maxn = 2000 + 5;
ull dp[maxn][maxn];
int a[maxn];
int n, k;
inline void buildDP() {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (i == 2 * j)dp[i][j] = dp[i - 2][j - 1] + (1ll * a[i] - 1ll * a[i - 1]) * (1ll * a[i] - 1ll * a[i - 1]);
			else if (i > 2 * j)dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (1ll * a[i] - 1ll * a[i - 1]) * (1ll * a[i] - 1ll * a[i - 1]));
		}
	}
}
int main() {
	while (scanf("%d%d", &n, &k) != EOF) {
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; ++i)scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		buildDP();
		printf("%llu\n", dp[n][k]);
	}
}