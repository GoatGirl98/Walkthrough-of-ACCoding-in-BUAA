#include<cstdio>
#include<cstring>
#define maxv 100010
#define maxn 10010
typedef long long ll;
ll f[maxv];
int n, V;
int t;
ll value[maxn], cost[maxn], like[maxn];
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
inline void buildDP_01Pack(int cost, int value) {
    for (int v = V; v >= cost; --v) {
        if (f[v - cost] + value > f[v])f[v] = f[v - cost] + value;
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(f, 0, sizeof(f));
        memset(value, 0, sizeof(value));
        memset(cost, 0, sizeof(cost));
        memset(like, 0, sizeof(like));
        for (int i = 1; i <= n; ++i) {
            cost[i] = read(), value[i] = read(), like[i] = read();
        }
        V = read();
        for (int i = 1; i <= n; ++i) {
            if (like[i] && value[i] > 0) {
                buildDP_01Pack(cost[i], value[i]);
            }
        }
        write(f[V]), putchar('\n');
    }
    
}
