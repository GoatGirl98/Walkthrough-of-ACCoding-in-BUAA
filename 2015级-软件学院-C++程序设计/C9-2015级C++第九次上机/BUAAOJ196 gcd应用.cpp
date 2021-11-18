#include<cstdio>
int gcd(int a, int b) {
	while (b ^= a ^= b ^= a %= b);
	return a;
}
int a, b, l, ansa, ansb;
int main() {
	while (scanf("%d%d%d", &a, &b, &l) != EOF) {
		ansa = l, ansb = 1;
		for (int i = 1; i <= l; ++i) {
			for (int j = 1; j <= l; ++j) {
				if (gcd(i, j) == 1 && i * b >= j * a && i * ansb < j * ansa)ansa = i, ansb = j;
			}
		}
		printf("%d %d\n", ansa, ansb);
	}
}