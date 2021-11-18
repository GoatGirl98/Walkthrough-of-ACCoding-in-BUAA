#include<stdio.h>
int n, i;
int a[1010], b[1010], d[1010], s[1010];
int k, l, m, ans_k, ans_l, ans_m;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)scanf("%d%d", &a[i], &b[i]), d[i] = a[i] - b[i], s[i] = s[i - 1] + d[i];
	for (i = 1; i <= n; ++i) {
		if (d[i] >= ans_k) k = i, ans_k = d[i];
		if (s[i] >= ans_l) l = i, ans_l = s[i];
	}
	m = n; while (s[m] == 0)--m;
	printf("%d %d %d", k, l, m + 1);
}