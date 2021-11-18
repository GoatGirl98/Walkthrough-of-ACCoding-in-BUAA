#include<cstdio>
#include<cstring>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define maxv 65536
#define maxn 300
#define init -114514
int dp[maxv];
int tmp[maxv];
inline void buildDP_01PackChange(int value, int cost) {
	for (int v = V; v >= cost; --v) {
		dp[v] = Max(dp[v], dp[v - cost] + value);
	}
}
int V, N;
int value, cost;
int main() {
	while (scanf("%d%d", &V, &N) != EOF) {
		memset(dp, init, sizeof(dp));
		dp[0] = 0;//保证dp[0]是0即可由此生成装满的01背包
		while (N--) {
			scanf("%d%d", &value, &cost);
			buildDP_01PackChange(value, cost);
		}
		if (dp[V] < 0)puts("jpx");
		else printf("%d\n", dp[V]);
	}
}