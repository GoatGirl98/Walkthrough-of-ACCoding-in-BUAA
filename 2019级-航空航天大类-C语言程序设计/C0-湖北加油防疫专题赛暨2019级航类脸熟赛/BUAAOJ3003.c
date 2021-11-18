#include<stdio.h>
int n, x, ans;
int main() {
	scanf("%d", &n);
	while (n)scanf("%d", &x), ans += x * n, n--;
	printf("%d", ans);
}