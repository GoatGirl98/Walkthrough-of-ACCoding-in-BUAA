#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define maxn 110
#define maxDep 8
char map[maxn][maxn];
bool occur[maxn][maxn];
char target[10] = "communism";
struct node {
	int x, y;
}route[maxn];
int nx[8] = { -1,-1,-1,0,0,1,1,1 };
int ny[8] = { -1,0,1,1,-1,-1,0,1 };
//坐标,方向,深度
int n;
inline bool illegal(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= n;
}
void dfs(int x, int y, int k, int dep) {
	if (dep > maxDep)
		for (int i = 0; i <= maxDep; ++i)occur[route[i].x][route[i].y] = true;
	if (illegal(x, y))return;
	if (map[x][y] != target[dep])return;
	else {
		int dx = x + nx[k], dy = y + ny[k];
		route[dep].x = x, route[dep].y = y;
		dfs(dx, dy, k, dep + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);
	memset(occur, false, sizeof(occur));
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			for (int k = 0; k < 8; ++k) 
				dfs(i, j, k, 0);
			
		
	
	for (int i = 0; i < n; ++i, putchar('\n')) 
		for (int j = 0; j < n; ++j) 
			putchar(occur[i][j] ? map[i][j] : '*');
}