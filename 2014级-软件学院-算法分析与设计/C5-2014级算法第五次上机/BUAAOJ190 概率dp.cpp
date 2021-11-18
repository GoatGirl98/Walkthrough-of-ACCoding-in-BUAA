#include<cstdio>
#include<cstring>
const int maxn = 10010;
int n;
double p, pl, pr;
double dp[maxn];
inline double E(int l, int r) {
	return dp[l] + dp[r] + (pl * dp[l] + pr * dp[r] + 1) / p;
}
inline void buildDP() {
	memset(dp, 0, sizeof(dp));
	p = 1 - pl - pr;
	dp[0] = 0, dp[1] = 1 / p;
	int left = 0;
	for (int i = 2; i <= n; ++i) {
		dp[i] = E(left, i - left - 1);

		for (int j = left + 1; j < i; ++j) {
			int l = j, r = i - j - 1;
			double tmp = E(l, r);
			if (tmp <= dp[i])dp[i] = tmp, left = j;
			else break;
		}
	}

}
int main() {
	while (scanf("%d%lf%lf", &n, &pl, &pr) != EOF) {
		buildDP(); printf("%.2lf\n", dp[n]);
	}
}