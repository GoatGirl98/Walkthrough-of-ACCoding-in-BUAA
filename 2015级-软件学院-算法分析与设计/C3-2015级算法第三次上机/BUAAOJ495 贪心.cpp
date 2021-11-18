#include<cstdio>
#include<cstring>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
typedef long long ll;
const int maxn = 1010;
const int INF = 1145141919810LL;
inline void write(ll x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline ll read() {
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
int t;
int n, m;
int tmp;
ll real[maxn];
int main() {
    t = read();
    for (int i = 1; i <= t; ++i) {
        n = read(), m = read();
        memset(real, INF, sizeof(real));
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= m; ++k) {
                tmp = read();
                real[k] = Min(real[k], tmp);
            }
        }
        ll ans = 0;
        for (int j = 1; j <= m; ++j)ans += real[j];
        printf("Case #%d: %lld\n", i, ans);
    }
}
