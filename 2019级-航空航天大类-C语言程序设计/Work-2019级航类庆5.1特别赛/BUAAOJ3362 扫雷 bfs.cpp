#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define maxn 255
#define mp make_pair
using namespace std;
typedef pair<int, int>PII;
queue<PII> q;
vector<PII>neighbor;
bool finished;
int n, m;
char map[maxn][maxn];
int x, y;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);
	scanf("%d%d", &x, &y);
	q.push(mp(x, y));
	while (!q.empty()) {
		PII tmp = q.front();
		q.pop();
		int mineCnt = 0;
		int x = tmp.first, y = tmp.second;
		if (map[x][y] == 'M') {
			map[x][y] = 'X';
			break;
		}
		neighbor.clear();
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				int nx = x + i, ny = y + j;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
				if (map[nx][ny] == 'M')++mineCnt;
				else if (map[nx][ny] == 'E')neighbor.push_back(mp(nx, ny));
			}
		}
		if (mineCnt)map[x][y] = mineCnt + 48;
		else {
			for (int i = 0; i < neighbor.size(); ++i) {
				map[neighbor[i].first][neighbor[i].second] = 'B';
				q.push(neighbor[i]);
			}
		}
	}
	for (int i = 0; i < n; ++i)
		puts(map[i]);
}