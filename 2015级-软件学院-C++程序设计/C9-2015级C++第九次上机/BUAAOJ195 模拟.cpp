#include<cstdio>
#include<cstring>
#define maxn 105
int n;
int map[maxn][maxn];
enum Direction { R, LD, D, RU };
Direction cur;
int dy[] = { 1,-1,0,1 };
int dx[] = { 0,1,1,-1 };
int main() {
	while (scanf("%d", &n) != EOF) {
		memset(map, 0, sizeof(map));
		int x = 1, y = 1;
		cur = R;
		for (int i = 1; i < n * n; ++i) {
			int nx = x + dx[cur], ny = y + dy[cur];
			//printf("map[%d][%d] is %d\n", nx, ny, i);
			map[nx][ny] = i;
			if (cur == R && nx == 1)cur = LD;
			else if (cur == R && nx == n)cur = RU;
			else if (cur == LD && ny == 1 && nx < n)cur = D;
			else if (cur == LD && nx == n)cur = R;
			else if (cur == D && ny == 1)cur = RU;
			else if (cur == D && ny == n)cur = LD;
			else if (cur == RU && nx == 1 && ny < n)cur = R;
			else if (cur == RU && ny == n)cur = D;
			x = nx, y = ny;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				printf("%d%c", map[i][j], (j == n ? '\n' : ' '));
		}
	}
}