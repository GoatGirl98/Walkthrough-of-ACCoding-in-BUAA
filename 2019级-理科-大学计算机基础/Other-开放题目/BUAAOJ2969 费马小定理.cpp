#include<cstdio>
typedef long long ll;
const ll MOD = 1000000007;
inline ll read(bool flag) {
    //flag true表示幂数 false表示底数
    ll k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        k %= MOD - flag;
        c = getchar_unlocked();
    }
    return k * f;
}
ll ApowBmodP(ll a, ll b, ll p) {
    ll ret = 1;
    while(b) {
        if(b & 1)ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret % p;
}
ll a,b;
int main() {
    a = read(false), b = read(true);
    printf("%lld",ApowBmodP(a, b, MOD));
}

