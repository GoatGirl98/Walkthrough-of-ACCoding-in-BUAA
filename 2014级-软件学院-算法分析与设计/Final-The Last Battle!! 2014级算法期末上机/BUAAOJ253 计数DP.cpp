#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
/**************************************************
这种dp计数的题目一般都是使用dp[i][j]
的形式解答
本题则是前i个物品取j对的最小消耗
如果a<b<c<d 那么(a-b)^2+(c-d)^2就是最小

然后
i = 2j时
dp[i][j] = dp[i-2][j-1]+...
如果不是
dp[i][j] = max(dp[i-1][j],dp[i-2][j-1]+...)
初始:dp[2][1],dp[1][1]...仔细分析一下都不需要处理
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