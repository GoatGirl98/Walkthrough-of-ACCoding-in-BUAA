#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>

#define maxn 510
using namespace std;
int n, k;
int a[maxn];
bool dp[maxn][maxn];//前i个糖可以摆出值为j的

inline void erase() {
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
}

inline void initDP() {
	for (int i = 0; i <= n; ++i) dp[i][0] = true;
}

inline void buildDP() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (j >= a[i]) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
			else dp[i][j] = dp[i - 1][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> k) {
		erase();
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		initDP(); buildDP();
		cout << ((dp[n][k]) ? "Yes" : "No") << endl;
	}
}
