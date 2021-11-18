#include<stdio.h>
int n;
int main() {
	scanf("%d", &n);
	if (__builtin_popcount(n) != 1) printf("false");
	else printf("true %d", __builtin_ctz(n));
}