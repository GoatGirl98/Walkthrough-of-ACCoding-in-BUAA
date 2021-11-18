#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef long long ll;
#define MAXN 100005
ll a[MAXN];
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
int cmp(const void* p1, const void* p2) {
    ll* a = (ll*)p1, * b = (ll*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
int t;
int n, i, j;
int main() {
    t = rd();
    while (t--) {
        n = rd();
        for (i = 0; i < n; ++i) a[i] = rd();
        qsort(a, 0, sizeof(a[0]), cmp);
        ll x = a[n / 2];
        ll ret = 0;
        for (i = 0; i < n; ++i) {
            ll lalala = a[i] - x;
            ret += lalala > 0 ? lalala : -lalala;
        }
        printf("%lld ", ret);
    }
    return 0;
}