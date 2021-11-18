#include<stdio.h>
#include<ctype.h>
typedef long long ll;
const ll mod = 1000000007;
ll a[1919810], s[1919810], i, q, n;
ll rd() {
    ll k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
int main() {
	a[1] = a[2] = a[3] = 1;
	for (i = 4; i <= 1000000; ++i)a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % mod;
	for (i = 1; i <= 1000000; ++i)s[i] = (s[i - 1] + a[i]) % mod;
    q = rd();
    while (q--)n = rd(), wr(s[n]), putchar('\n');
}