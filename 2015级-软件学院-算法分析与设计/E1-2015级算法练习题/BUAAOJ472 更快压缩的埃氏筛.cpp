#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <bitset>
using namespace std;
typedef long long ll;
ll rd() {
	ll k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}
void wr(int x) {
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}
bitset<25111005> a;
int cnt[25000005];
int n;
void get_prime(int n) {
	cnt[0] = 1;//2 is prime
	int lim = 2 * sqrt(n);
	for (int i = 9; i <= n; i += 6) a.set(i >> 1);//6i+3 not prime
	for (int i = 15; i <= n; i += 10) a.set(i >> 1);//10i+5 not prime
	int i = 0, j = 0;
	for (i = 7; i <= lim; i += 2) {
		if (a.test(i >> 1)) continue;
		for (j = i * (i / 6 * 6 + 1); j <= n; j += i * 6)
			a.set(j >> 1), a.set((j >> 1) + (i << 1));
	}
	for (int i = 3; i <= n; i += 2) cnt[i >> 1] = cnt[(i >> 1) - 1] + !a.test(i >> 1);
}
bool is_prime(int x) {
	if (x == 2) return 1;
	else if (x < 2) return 0;
	else if ((x & 1) == 0) return 0;
	else return !a.test(x >> 1);
}
int main() {
	get_prime(50000000);
	while (scanf("%d", &n) != EOF) {
		wr(n == 1 ? 0 : n == 2 ? 1 : cnt[(n - 1) >> 1]);
		putchar('\n');
	}
}
