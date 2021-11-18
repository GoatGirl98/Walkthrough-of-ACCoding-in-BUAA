#include<stdio.h>
typedef long long ll;
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
ll rd() {
    ll k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(ll x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
ll n, s;
ll a[1145140], sum[1145140];
ll L, R;
ll ans, i;
int main() {
	n = rd(), s = rd();
	ans = n + 1;
	for(i = 1; i <= n; ++i)
		a[i] = rd(), sum[i] = sum[i - 1] + a[i];
	L = 1, R = 1;
	while(L <= R && R <= n) {
		if(sum[R] - sum[L - 1] < s) ++R;
		else ans = min(ans, R - L + 1), ++L;
	}
	wr(ans > n ? -1 : ans);
}
