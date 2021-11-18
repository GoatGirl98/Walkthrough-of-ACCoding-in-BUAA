#include<stdio.h>
int n, tmp, ans;
int main() {
	scanf("%d", &n);
	while (n--)
		tmp = (tmp << 1) + (tmp << 3) + 6, ans += tmp;
	printf("%d", ans);
}