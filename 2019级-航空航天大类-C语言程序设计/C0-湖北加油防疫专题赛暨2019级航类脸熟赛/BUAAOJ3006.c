#include<stdio.h>
int ans[4];
int s[4];
int loss[4] = { 40,30,35,20 };
int n, x;
char op[2];
int main() {
	scanf("%d", &n);
	while (n--) {
		while (1) {
			scanf("%s", op);
			if (op[0] == 'N')break;
			int o = op[0] - 'A';
			scanf("%d", &x), s[o] += x;
			if (s[o] > loss[o])ans[o] += s[o] - loss[o], s[o] = 0;
		}
	}
	printf("%d", ans[0] + ans[1] + ans[2] + ans[3]);
}