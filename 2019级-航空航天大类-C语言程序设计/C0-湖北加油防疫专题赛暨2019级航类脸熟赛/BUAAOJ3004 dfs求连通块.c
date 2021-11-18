#include<stdio.h>
#include<string.h>
#define maxn 55
typedef long long ll;
ll n, d;
char map[maxn][maxn];
int occur[maxn][maxn];//是否被算过
int flag_edge, flag_white, flag_black;
//表示周围被这几种棋子围住了
ll block_size;//连通块面积
ll black_cnt, white_cnt;
ll black_empty, white_empty;
int nx[4] = { -1,0,1,0 };
int ny[4] = { 0,1,0,-1 };
int isEdge(int x, int y) {
	return x == 0 || x == n + 1 || y == 0 || y == n + 1;
}
int isBlack(int x, int y) {
	return map[x][y] == 'B';
}
int isWhite(int x, int y) {
	return map[x][y] == 'W';
}
void dfs(int x, int y) {
	block_size++;
	occur[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int dx = nx[i] + x, dy = ny[i] + y;
		if (isEdge(dx, dy))flag_edge = 1;
		else if (isBlack(dx, dy))flag_black = 1;
		else if (isWhite(dx, dy))flag_white = 1;
		else if (!occur[dx][dy])dfs(dx, dy);
	}
}
int main() {
	scanf("%lld%lld", &n, &d);
	ll i, j;
	for (i = 1; i <= n; ++i)scanf("%s", map[i] + 1);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (!occur[i][j] && map[i][j] == 'E') {
				block_size = flag_edge = flag_black = flag_white = 0;
				dfs(i, j);
				if (flag_black && !flag_white)black_empty += block_size;
				else if (flag_white && !flag_black)white_empty += block_size;
			}
			else if (map[i][j] == 'W')white_cnt++;
			else if (map[i][j] == 'B')black_cnt++;
		}
	}
	printf("%lld\n", black_cnt + black_empty - white_cnt - white_empty - (2 * d));
}