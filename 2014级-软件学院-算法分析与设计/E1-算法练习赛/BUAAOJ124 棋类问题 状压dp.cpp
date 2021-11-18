#include<cstdio>
#include<cstring>
#define INF 1145141919810LL
#define maxn 110
typedef unsigned long long ull;
/***************************************************
其实这个问题背景蛮经典的
首先想到的就是八皇后问题
但是放在这里其实是说明，本题可以使用状压dp
且状压dp比dfs可以应对更多的变化情况，且复杂度稳定

对于每个点位，就只有两种情况，放炮或不放
这个其实就可以表示成为一个01系列，并进行压缩

所以状态转移方程为:
dp[i][j]=lastdp[j][k]+num[i]
本行选择的是第i个方案，上一行是j方案，上上行是k方案
保证ijk都是可以共存的

然后这个状压dp还有个特殊的地方
就是将十进制数在不转化成01序列的情况下进行更新
dfs(l,c+3,content|(1<<c),sum+1)
dfs(l,c+1,content,sum)
行，列，方案，放置的炮台数

前者在该列放炮，后两者必不放，然后更新
后者不在这放炮，不做更多更新
***************************************************/
int n, m;
int pre, prepre, cur;
int last[maxn], lastlast[maxn], now[maxn];
//3层滚动dp
ull num[maxn], dp[maxn][maxn], tmp[maxn][maxn];
//dp[k][i][j]为k行用i方案，k-1行j方案，的炮兵数
inline void dfs(int id, int k, int p, int sum) {
	if (k >= m) {
		now[++cur] = p;
		num[cur] = sum;
		return;
	}
	dfs(id, k + 3, p | (1 << k), sum + 1);
	dfs(id, k + 1, p, sum);
}
inline void buildDP() {
	for (int k = 1; k <= n; ++k) {
		memset(now, 0, sizeof(now));
		cur = 0;
		dfs(k, 0, 0, 0);
		for (int i = 1; i <= cur; ++i)
			for (int j = 1; j <= pre; ++j)
				dp[i][j] = 0;
		for (int i = 1; i <= cur; ++i) {
			for (int j = 1; j <= pre; ++j) {
				for (int t = 1; t <= prepre; ++t) {
					if (now[i] & last[j])continue;
					if (now[i] & lastlast[t])continue;
					if (dp[i][j] < tmp[j][t] + num[i])dp[i][j] = tmp[j][t] + num[i];
				}
			}
		}
		for (int i = 1; i <= cur; ++i)
			for (int j = 1; j <= pre; ++j)
				tmp[i][j] = dp[i][j];
		for (int i = 1; i <= pre; ++i)lastlast[i] = last[i];
		prepre = pre;
		for (int i = 1; i <= cur; ++i)last[i] = now[i];
		pre = cur;
		//滚动
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		last[1] = lastlast[1] = tmp[1][1] = 0;
		prepre = pre = 1;
		buildDP();
		int sum = 0, cost = 0;
		for (int i = 1; i <= pre; ++i) {
			for (int j = 1; j <= prepre; ++j) {
				if (tmp[i][j] > sum)sum = tmp[i][j], cost = 1;
				else if (tmp[i][j] == sum)cost++;
			}
		}
		printf("%d %d\n", sum, cost);
	}
}