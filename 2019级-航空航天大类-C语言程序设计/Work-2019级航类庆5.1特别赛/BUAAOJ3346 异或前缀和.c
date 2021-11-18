#include<stdio.h>
typedef long long ll;
void write(ll x) {
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
int read() {
	int k = 0, f = 1;
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
int a[100010];
ll cnt[100010];
ll ans;
int n;
int main() {
	n = read();
	for (int i = 1; i <= n; ++i)a[i] = read();
	for (int i = 1; i <= n; ++i)a[i] ^= a[i - 1];
	for (int i = 0; i <= n; ++i)cnt[a[i]]++;
	for (int i = 0; i <= 100000; ++i)ans += cnt[i] * (cnt[i] - 1) / 2;
	write(ans);
}