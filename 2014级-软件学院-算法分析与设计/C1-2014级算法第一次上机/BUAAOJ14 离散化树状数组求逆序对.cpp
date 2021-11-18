#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
inline void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline int read() {
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
struct BIT {
    static const int maxn = 1000010;
    int c[maxn];
    int n;
    inline int lowbit(int c) {
        return c & (-c);
    }
    inline void init(int N) {
        n = N;
        for (int i = 0; i <= n; ++i) c[i] = 0;
    }
    inline void add(int loc, int v) {
        while (loc <= n) {
            c[loc] += v, loc += lowbit(loc);
        }
    }
    inline int sum(int loc) {
        int ret = 0;
        while (loc) {
            ret += c[loc], loc -= lowbit(loc);
        }
        return ret;
    }
    inline int query(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }
} tree;
int n, x;
int a[1000010], tmp[1000010];
int real_m;
ll result;
int main() {
    while(scanf("%d", &n) != EOF) {
        result = 0;
        tree.init(1000000);
        for(int i = 0; i < n; ++i) tmp[i] = a[i] = read();
        sort(tmp, tmp + n);
        real_m = unique(tmp, tmp + n) - tmp;
        for(int i = 0; i < n; ++i) {
            x = lower_bound(tmp, tmp + real_m, a[i]) - tmp + 1;
            result += tree.query(x + 1, real_m);
            tree.add(x, 1);
        }
        write(result), putchar_unlocked('\n');
    }
}
