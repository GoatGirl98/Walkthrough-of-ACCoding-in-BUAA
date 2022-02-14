#include<stdio.h>
#include<string.h>
char str[1010];
int a[1010];
int notEnd(int p) {
	for (int i = p; ~i; --i)
		if (a[i] != 0)return i;
	return -1;
}
int q;
int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%s", str);
		int len = strlen(str), ans = 0;
		int p = len - 1;
		for (int i = 0; i < len; ++i)a[i] = str[len - i - 1] - '0';
		while ((p = notEnd(p)) != -1) {
			ans += a[0] % 2;
			for (int i = p; ~i; --i) {
				a[i - 1] = a[i] % 2 * 10 + a[i - 1];
				a[i] /= 2;
			}
		}
		printf("%d\n", ans);
	}
}