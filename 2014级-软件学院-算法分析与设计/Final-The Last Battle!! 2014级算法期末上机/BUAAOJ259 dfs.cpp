#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 110
using namespace std;
char map[maxn][maxn];
int nx[4] = { -1,0,1,0 };
int ny[4] = { 0,1,0,-1 };
int n, m;
void dfs(int x, int y, char target) {
	map[x][y] = 'w';
	for (int i = 0; i < 4; ++i) {
		int nextx = nx[i] + x, nexty = ny[i] + y;
		if (nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= m && map[nextx][nexty] == target) {
			dfs(nextx, nexty, target);
		}
	}

}
int result;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n >> m) {
		result = 0;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; ++i)cin >> map[i] + 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (map[i][j] != 'w') {
					char target = map[i][j];
					dfs(i, j, target);
					result++;
				}
			}
		}
		cout << result << endl;
	}

}