#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
/******************************************
更加强力数独剪枝模板
关键点在于先选取数多的一行开始填
省去相当一部分不合法情况
******************************************/
inline int areaID(int x, int y) {
	if (x <= 3 && y <= 3)return 1;
	if (x <= 3 && y <= 6)return 2;
	if (x <= 3 && y <= 9)return 3;
	if (x <= 6 && y <= 3)return 4;
	if (x <= 6 && y <= 6)return 5;
	if (x <= 6 && y <= 9)return 6;
	if (x <= 9 && y <= 3)return 7;
	if (x <= 9 && y <= 6)return 8;
	if (x <= 9 && y <= 9)return 9;
	return 0;
}
int res, tmp;
int ans;
int a[10][10];
bool h[10][10], l[10][10], g[10][10];//分别是行 列 第几个格子
bool occur[10];
inline bool check(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
	memset(occur, false, sizeof(occur));
	occur[a1] = occur[a2] = occur[a3] = occur[a4] = occur[a5] = occur[a6] = occur[a7] = occur[a8] = occur[a9] = true;
	return occur[1] && occur[2] && occur[3] && occur[4] && occur[5] && occur[6] && occur[7] && occur[8] && occur[9];
}
inline bool checkMatrix() {
	bool a1 = check(a[1][1], a[1][2], a[1][3], a[1][4], a[1][5], a[1][6], a[1][7], a[1][8], a[1][9]);
	bool a2 = check(a[2][1], a[2][2], a[2][3], a[2][4], a[2][5], a[2][6], a[2][7], a[2][8], a[2][9]);
	bool a3 = check(a[3][1], a[3][2], a[3][3], a[3][4], a[3][5], a[3][6], a[3][7], a[3][8], a[3][9]);
	bool a4 = check(a[4][1], a[4][2], a[4][3], a[4][4], a[4][5], a[4][6], a[4][7], a[4][8], a[4][9]);
	bool a5 = check(a[5][1], a[5][2], a[5][3], a[5][4], a[5][5], a[5][6], a[5][7], a[5][8], a[5][9]);
	bool a6 = check(a[6][1], a[6][2], a[6][3], a[6][4], a[6][5], a[6][6], a[6][7], a[6][8], a[6][9]);
	bool a7 = check(a[7][1], a[7][2], a[7][3], a[7][4], a[7][5], a[7][6], a[7][7], a[7][8], a[7][9]);
	bool a8 = check(a[8][1], a[8][2], a[8][3], a[8][4], a[8][5], a[8][6], a[8][7], a[8][8], a[8][9]);
	bool a9 = check(a[9][1], a[9][2], a[9][3], a[9][4], a[9][5], a[9][6], a[9][7], a[9][8], a[9][9]);
	bool b1 = check(a[1][1], a[2][1], a[3][1], a[4][1], a[5][1], a[6][1], a[7][1], a[8][1], a[9][1]);
	bool b2 = check(a[1][2], a[2][2], a[3][2], a[4][2], a[5][2], a[6][2], a[7][2], a[8][2], a[9][2]);
	bool b3 = check(a[1][3], a[2][3], a[3][3], a[4][3], a[5][3], a[6][3], a[7][3], a[8][3], a[9][3]);
	bool b4 = check(a[1][4], a[2][4], a[3][4], a[4][4], a[5][4], a[6][4], a[7][4], a[8][4], a[9][4]);
	bool b5 = check(a[1][5], a[2][5], a[3][5], a[4][5], a[5][5], a[6][5], a[7][5], a[8][5], a[9][5]);
	bool b6 = check(a[1][6], a[2][6], a[3][6], a[4][6], a[5][6], a[6][6], a[7][6], a[8][6], a[9][6]);
	bool b7 = check(a[1][7], a[2][7], a[3][7], a[4][7], a[5][7], a[6][7], a[7][7], a[8][7], a[9][7]);
	bool b8 = check(a[1][8], a[2][8], a[3][8], a[4][8], a[5][8], a[6][8], a[7][8], a[8][8], a[9][8]);
	bool b9 = check(a[1][9], a[2][9], a[3][9], a[4][9], a[5][9], a[6][9], a[7][9], a[8][9], a[9][9]);
	bool c1 = check(a[1][1], a[1][2], a[1][3], a[2][1], a[2][2], a[2][3], a[3][1], a[3][2], a[3][3]);
	bool c2 = check(a[4][1], a[4][2], a[4][3], a[5][1], a[5][2], a[5][3], a[6][1], a[6][2], a[6][3]);
	bool c3 = check(a[7][1], a[7][2], a[7][3], a[8][1], a[8][2], a[8][3], a[9][1], a[9][2], a[9][3]);
	bool c4 = check(a[1][4], a[1][5], a[1][6], a[2][4], a[2][5], a[2][6], a[3][4], a[3][5], a[3][6]);
	bool c5 = check(a[4][4], a[4][5], a[4][6], a[5][4], a[5][5], a[5][6], a[6][4], a[6][5], a[6][6]);
	bool c6 = check(a[7][4], a[7][5], a[7][6], a[8][4], a[8][5], a[8][6], a[9][4], a[9][5], a[9][6]);
	bool c7 = check(a[1][7], a[1][8], a[1][9], a[2][7], a[2][8], a[2][9], a[3][7], a[3][8], a[3][9]);
	bool c8 = check(a[4][7], a[4][8], a[4][9], a[5][7], a[5][8], a[5][9], a[6][7], a[6][8], a[6][9]);
	bool c9 = check(a[7][7], a[7][8], a[7][9], a[8][7], a[8][8], a[8][9], a[9][7], a[9][8], a[9][9]);
	return a1 && b1 && c1 && a2 && b2 && c2 && a3 && b3 && c3 && a4 && b4 && c4 && a5 && b5 && c5 && a6 && b6 && c6 && a7 && b7 && c7 && a8 && b8 && c8 && a9 && b9 && c9;
}
inline void printMap() {
	/*
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
	*/
	if (checkMatrix()) res++;
}
struct SearchNode {
	int line, sum;//记录每行要填充的个数
	bool operator < (const SearchNode& o) const {
		return sum < o.sum;
	}
}target[11];
void dfs(int hi, int x, int y) {
	if (hi == 10) {
		printMap();
		return;
	}
	if (y > 9) {
		dfs(hi + 1, target[hi + 1].line, 1);
		return;
	}
	if (a[x][y] == 0) {
		for (int i = 1; i <= 9; ++i) {
			if (h[x][i] && l[y][i] && g[areaID(x, y)][i]) {
				a[x][y] = i;
				h[x][i] = false;//行占领
				l[y][i] = false;//列占领
				g[areaID(x, y)][i] = false;
				dfs(hi, x, y + 1);
				a[x][y] = 0;
				h[x][i] = true;//行占领
				l[y][i] = true;//列占领
				g[areaID(x, y)][i] = true;
			}
		}
	}
	else dfs(hi, x, y + 1);
}
inline void init() {
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			h[i][j] = l[i][j] = g[i][j] = true;
		}
	}
}
int main() {
	init();
	for (int i = 1; i <= 9; ++i) {
		int need = 0;
		for (int j = 1; j <= 9; ++j) {
			scanf("%d", &a[i][j]);
			if (a[i][j]) {
				h[i][a[i][j]] = false;
				l[j][a[i][j]] = false;
				g[areaID(i, j)][a[i][j]] = false;
			}
			else need++;
		}
		target[i].line = i, target[i].sum = need;
	}
	sort(target + 1, target + 10);
	dfs(1, target[1].line, 1);
	printf("%d", res);
	return 0;
}