#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int m, n;
char s[8][8];
char pattern[15][15];
char tmp[15];
bool vis[8][8];
int ans;

int calc() {
	int ret = 0;
	for (int i = 1; i <= m; ++i) ret += strstr(tmp + 1, pattern[i] + 1) != NULL;
	return ret;
}

void dfs(int x, int y, int step) {
	if (step == n) { ans = max(ans, calc()); return; }
	if (step & 1) {
		for (int nx = 1; nx <= 6; ++nx) {
			if (vis[nx][y]) continue;
			vis[nx][y] = 1, tmp[step + 1] = s[nx][y];
			dfs(nx, y, step + 1);
			vis[nx][y] = 0, tmp[step + 1] = '\0';
		}
	}
	else {
		for (int ny = 1; ny <= 6; ++ny) {
			if (vis[x][ny]) continue;
			vis[x][ny] = 1, tmp[step + 1] = s[x][ny];
			dfs(x, ny, step + 1);
			vis[x][ny] = 0, tmp[step + 1] = '\0';
		}
	}
}


int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= 6; ++i) scanf("%s", s[i] + 1);
	for (int i = 1; i <= m; ++i) scanf("%s", pattern[i] + 1);

	for (int i = 1; i <= 6; ++i) vis[1][i] = 1, tmp[1] = s[1][i], dfs(1, i, 1), tmp[1] = '\0';
	printf("%d", ans);
}