#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 200
#define debug 0
char map[maxn][maxn];
int dp[maxn][maxn];

int n;
void printMap() {
	for (int i = 0; i < n; ++i) {
		printf("%s\n", map[i]);
	}
}
void initDP() {
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (map[i][j] == '-')dp[i][j] = 1;
		}
	}
}
void printDP() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", dp[i][j]);
		}
		putchar('\n');
	}
}
void buildDP() {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (dp[i][j]) {
				if (dp[i - 1][j - 1] && dp[i - 1][j]) {
					dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
				}
			}
		}
	}
}
void printRes() {
	int curMax = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			curMax = max(curMax, dp[i][j]);
		}
	}
	printf("%d\n", curMax);
}
int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		scanf("%[^\n]", map[i]);
		getchar();
	}
	if (debug)printMap();
	initDP(); buildDP();
	printRes();
}