#include <stdio.h>
long long n, a, b;
int main() {
	scanf("%lld", &n);
	while (n--) {
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", (a + b - 1) / b);
	}
	return 0;
}