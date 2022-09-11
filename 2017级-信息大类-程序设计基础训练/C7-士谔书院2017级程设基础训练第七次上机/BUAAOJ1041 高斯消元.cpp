#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 605;
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
ll a[N][N];
ll n, mod;
ll det(ll a[][N], ll n) {
    ll i, j, k, r = 1, fh = 0, l;
    for (i = 1; i <= n; ++i) {
        k = i;
        for (j = i; j <= n; ++j) if (a[j][i]) {k = j; break;}
        if (a[k][i] == 0) return 0;
        for (++j; j <= n; ++j) if (a[j][i] && a[j][i] < a[k][i]) k = j;
        if (i != k) swap(a[k], a[i]), fh ^= 1;
        for (j = i + 1; j <= n; ++j) {
            if (a[j][i] > a[i][i]) swap(a[j], a[i]), fh ^= 1;
            while (a[j][i]) {
                l = a[i][i] / a[j][i];
                for (k = i; k <= n; k++) a[i][k] = (a[i][k] + (-l) * a[j][k]);
                swap(a[j], a[i]), fh ^= 1;
            }
        }
        r=(ll)r * a[i][i];
    }
    return fh ? -r : r;
}
int main() {
    n = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = read();
    printf("%lld\n", det(a, n));
}
