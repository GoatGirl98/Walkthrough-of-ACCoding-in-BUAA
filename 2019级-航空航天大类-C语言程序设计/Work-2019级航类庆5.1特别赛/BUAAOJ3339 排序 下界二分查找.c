#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define maxn 114514
typedef long long ll;
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
ll m, n;
ll a[maxn], b;
ll ans;
int cmp(const void* p1, const void* p2) {
    ll* a = (ll*)p1, * b = (ll*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
int lower_bound(ll a[], int lo, int hi, ll val) {
    if (val > a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] < val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int upper_bound(ll a[], int lo, int hi, ll val) {
    if (val >= a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] <= val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int main() {
    m = rd(), n = rd();
    for (int i = 1; i <= m; ++i) a[i] = rd();
    qsort(a + 1, m, sizeof(a[0]), cmp);
    while (n--) {
        b = rd();
        int l = lower_bound(a, 1, m, b);
        if (l > 1)ans += min(llabs(a[l] - b), llabs(a[l - 1] - b));
        else ans += llabs(a[l] - b);
    }
    wr(ans);
}