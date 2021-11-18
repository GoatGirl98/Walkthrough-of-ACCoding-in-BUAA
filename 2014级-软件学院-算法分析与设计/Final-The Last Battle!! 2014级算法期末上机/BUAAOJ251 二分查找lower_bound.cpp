
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#define maxn 1000010
#define RADIX 10
using namespace std;
typedef long long ll;
int n; ll k; int cap;
int tmp;
ll sum[maxn];
inline int read() {
	int k = 0;
	char c = getchar();
	while (!isdigit(c))c = getchar();
	while (isdigit(c)) { k = (k << 1) + (k << 3) + c - 48; c = getchar(); }
	return k;
}
inline void write(ll a) {
	if (a >= RADIX)write(a / RADIX);
	putchar(a % RADIX + 48);
}
int main() {
	while(scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			sum[i] = read();
		}
		k = read();
		ll* pos = lower_bound(sum, sum + n, k);
		if (sum[pos - sum] == k) {
			write(sum[pos + 1 - sum]);
			putchar('\n');
		}
		else {
			write(sum[pos - sum]);
			putchar('\n');
		}
	}
}
