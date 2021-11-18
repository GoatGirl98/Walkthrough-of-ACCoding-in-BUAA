#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define maxn 100010
typedef long long ll;
typedef unsigned long long ull;
//龟速乘&快速幂
inline ll AmulBmodP(ll a, ll b, ll p) {
    ull c = (long double)a / p * b;
    ll ret = (ull)a * b - (ull)c * p;
    ret %= p;
    if(ret < 0) ret += p;
    return ret % p;
}
inline ll ApowBmodP(ll a, ll b, ll p) {
    ll ret = 1;
    while(b) {
        if(b & 1)ret = AmulBmodP(ret, a, p);
        a = AmulBmodP(a, a, p);
        b >>= 1;
    }
    return ret % p;
}
//质数表&埃式筛法
int not_prime[maxn];
int prime[maxn], size;
inline void get_prime() {
    for(int i = 2; i < maxn; ++i) {
        if(!not_prime[i]) {
            prime[++size] = i;
            for(int j = i + i; j < maxn; j += i)
                not_prime[j] = 1;
        }
    }
}
int Miller_Rabin(ll x) {
    if (x == 2)
        return 1;
    if (x <= 1 || ~x & 1)
        return 0;
    if (x < maxn)
        return !not_prime[x];
    ll s = 0, t = x - 1;
    while (~t & 1) s++, t >>= 1;
    for(int i = 1; i <= 5; ++i) {
        ll b = prime[rand() % size + 1], k;
        b = ApowBmodP(b, t, x);
        for(int j = 1; j <= s; ++j) {
            k = AmulBmodP(b, b, x);
            if (k == 1 && b != 1 && b != x - 1)
                return 0;
            b = k;
        }
        if (b != 1)
            return 0;
    }
    return 1;
}
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
ll n;
int t;
int main() {
    srand(NULL);
    get_prime();
    t = read();
    while(t--) {
        n = read();
        puts(Miller_Rabin(n) ? "YES" : "NO");
    }
}
