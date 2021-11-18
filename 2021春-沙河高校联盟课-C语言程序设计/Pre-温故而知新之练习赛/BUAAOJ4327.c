#include<stdio.h>
int a[1010];
int n, x, i;
int main() {
	scanf("%d", &n);
	while (n--)scanf("%d", &x), a[x]++;
	for(i = 0; i <= 1001; ++i)
		if (a[i] == 0) {
			printf("%d", i);
			break;
		}
}