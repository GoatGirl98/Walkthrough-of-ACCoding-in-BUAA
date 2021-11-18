#include<cstdio>
#include<cstring>
int occur_hang[25], occur_lie[25];
int occur_zuo_xie[50];
int occur_you_xie[50];
inline void init() {
	memset(occur_hang, 0, sizeof(occur_hang));
	memset(occur_lie, 0, sizeof(occur_lie));
	memset(occur_you_xie, 0, sizeof(occur_you_xie));
	memset(occur_zuo_xie, 0, sizeof(occur_zuo_xie));
}
int n;
char map[25][25];
int main() {
	while (scanf("%d", &n) != EOF) {
		init();
		for (int i = 1; i <= n; ++i)
			scanf("%s", map[i] + 1);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (map[i][j] == '1') {
					//printf("%d %d is 1 so hang %d lie %d youxie %d zuoxie %d plus\n", i, j, i, j, i - j + n, i + j);
					occur_hang[i]++;
					occur_lie[j]++;
					occur_you_xie[i - j + n]++;
					occur_zuo_xie[i + j]++;
				}
			}
		}
		bool flag = true;
		//printf("occur lie 8 is %d\n", occur_lie[8]);
		for (int i = 1; i <= n; ++i) {
			flag = flag && (occur_hang[i] == 1);
			flag = flag && (occur_lie[i] == 1);
		}
		for (int i = 1; i <= 2 * n - 1; ++i) {
			flag = flag && (occur_you_xie[i] <= 1);
			flag = flag && (occur_zuo_xie[i + 1] <= 1);
		}
		if (flag)puts("Move Forward!");
		else puts("Bad End!");
	}
}
