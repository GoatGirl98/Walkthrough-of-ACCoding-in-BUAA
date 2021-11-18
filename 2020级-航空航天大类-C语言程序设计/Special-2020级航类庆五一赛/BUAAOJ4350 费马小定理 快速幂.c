#include<stdio.h>
typedef unsigned long long ll;
const ll mod = 100000007;
ll a, b, c;//a^b mod m
void wr(ll x) {
    if (x > 9)wr(x / 10);
    putchar(x % 10 + 48);
}
ll phi(ll x) {
    ll res = x;
    for (ll i = 2; i <= x / i; i++)
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}
ll AmulBmodP(ll a, ll b, ll p) {
    ll ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % p;
        a = (a << 1) % p;
        b >>= 1;
    }
    return ret;
}
ll ApowBmodP(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = (ret * a) % p;
        a = AmulBmodP(a, a, p);
        b >>= 1;
    }
    return ret % p;
}
int main() {
    while (scanf("%llu%llu%llu", &a, &b, &c) != EOF)
        printf("%llu\n", ApowBmodP(a, ApowBmodP(b, c, mod - 1), mod));
}