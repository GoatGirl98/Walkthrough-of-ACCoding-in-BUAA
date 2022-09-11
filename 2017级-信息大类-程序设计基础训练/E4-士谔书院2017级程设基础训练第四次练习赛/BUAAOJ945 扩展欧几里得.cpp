#include <cstdio>
typedef long long ll;
inline ll read() {
    ll k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
inline void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
ll extgcd(ll a, ll b, ll &x, ll &y) {//Extend Euclid
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return gcd;
}
ll a, b, MOD;
ll x, y;
int main() {
    a = read(), b = read(), MOD = read();
    if(b == 0) {puts("Angry!");return 0;}
    //如果b mod 上述质数是0 那么必然是无解的
    extgcd(b, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    write(a * x % MOD);
}
