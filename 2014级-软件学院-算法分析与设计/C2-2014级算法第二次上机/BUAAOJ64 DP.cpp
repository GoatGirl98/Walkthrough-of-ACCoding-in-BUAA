#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
#define maxn 105
typedef long long ll;
/**********************************************
二维DP
dp[m][n]为在n工作线上，进行了第m步的开销
dp[m][n] = work[m][n]+dp[m-1][i]+to[i][n]
**********************************************/
int m, n;//m道工序，n条流水线
ll dp[maxn][maxn];
int work[maxn][maxn];
int to[maxn][maxn];

inline void erase() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = LLONG_MAX;
		}
	}
	memset(work, 0, sizeof(work));
	memset(to, 0, sizeof(to));
}

inline ll buildDP() {
	for (int i = 1; i <= n; ++i)dp[i][1] = work[i][1];
	for (int i = 2; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				dp[j][i] = min(dp[j][i], work[j][i] + dp[k][i - 1] + to[k][j]);
			}
		}
	}
	ll result = LLONG_MAX;
	for (int i = 1; i <= n; ++i) {
		result = min(dp[i][m], result);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> m) {
		erase();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> work[i][j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> to[i][j];
			}
		}
		cout << buildDP() << endl;
	}

}
