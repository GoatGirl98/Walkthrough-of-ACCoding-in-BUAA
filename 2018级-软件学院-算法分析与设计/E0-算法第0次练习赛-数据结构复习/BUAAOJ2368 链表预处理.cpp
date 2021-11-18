#include <stdio.h>
#define N 300010
typedef long long ll;
int max(int x,int y) {return x > y ? x : y; }
int Nxt[N], Pre[N], n, a[N], dep[N];
void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
int read() {
    int k = 0, f = 1;
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
int main() {
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i) {
        a[i] = read();
        Nxt[i] = i + 1;
        Pre[i] = i - 1;
    }
    Nxt[0] = 1; Pre[n + 1] = n;
    for(int i = n;i >= 1; --i) {
        Nxt[Pre[a[i]]] = Nxt[a[i]];
        Pre[Nxt[a[i]]] = Pre[a[i]];
    }
    ll ans = 0; dep[0] = dep[n + 1] = -1;
    for(int i = 1;i <= n; ++i) {
        dep[a[i]] = max(dep[Pre[a[i]]], dep[Nxt[a[i]]]) + 1;
        ans += dep[a[i]];
        write(ans),putchar_unlocked('\n');
    }
}
