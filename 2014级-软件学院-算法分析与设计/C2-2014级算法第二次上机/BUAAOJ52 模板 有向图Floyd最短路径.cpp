#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define maxn 510
#define INF 2147483647
using namespace std;
/****************************************************************
floyd板子题目:

多次查询，那就一次算完，空间o(n^2)时间o(n^3)

(这个算法本质上也是DP思想，3维转2维)
最短路状态转移方程为
floyd[i][j] = min{floyd[i][k]+floyd[k][j],floyd[i][j]}
负权可以处理，所以这题-1要变成INF，但是负环不行
但是这题兜圈的可能性只有自己到自己
****************************************************************/
unsigned int floyd[maxn][maxn];
int n, q;
int start, finish;
inline void eraseMap() {
	memset(floyd, 0, sizeof(floyd));
}
inline void buildMap() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> q) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> floyd[i][j];
				if (floyd[i][j] == -1)floyd[i][j] = INF;
			}
		}
		buildMap();
		while (q--) {
			cin >> start >> finish;
			if (start == finish || floyd[start][finish] >= INF)
				cout << "jujue" << endl;
			else cout << floyd[start][finish] << endl;
		}

	}
}