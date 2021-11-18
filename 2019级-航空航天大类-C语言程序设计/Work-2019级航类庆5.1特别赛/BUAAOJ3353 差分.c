#include<stdio.h>
#define maxn 10100
int n, d1, h1, m1, d2, h2, m2;
int Index(int d, int m, int h) {
	return d * 1440 + m * 60 + h;
}
int a[maxn];
int ans;
int main() {
	while (scanf("%d%d%d:%d%d%d:%d", &n, &d1, &h1, &m1, &d2, &h2, &m2) != EOF) {
		a[Index(d1, h1, m1)] += n, a[Index(d2, h2, m2) + 1] -= n;
	}
	for (int i = 1; i <= 10080; ++i)
		a[i] += a[i - 1];
	for (int i = 0; i <= 10080; ++i)if (ans < a[i])ans = a[i];
	printf("%d", ans);
}
