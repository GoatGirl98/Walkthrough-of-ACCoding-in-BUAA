#include<stdio.h>
#include<math.h>
typedef long long ll;
void wr(ll x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + 48);
}
ll rd() {
    ll k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
ll gcd(ll a, ll b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
ll t;
ll x, y;
ll ans;
ll product;
ll lim;
ll same;
int main() {
    scanf("%d", &t);
    while(t--) {
        ans = same = 0;
        x = rd(), y = rd();
        lim = ceil(sqrt(x * y));
        product = x * y;
        for(ll i = 1; i <= lim; ++i) {
            if((product % i == 0) && gcd(i, product / i) == x) ++ans, same += (i * i == product);
        }
        wr((ans << 1) - same), putchar('\n');
    }
}
