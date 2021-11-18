#include<cstdio>
#include<algorithm>
using namespace std;
inline void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
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
struct BIT {
    static const int maxn = 500005;
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
        return sum(r) - sum(l - 1);
    }
} tree;
int m, x;
int a[105], tmp[105];
int real_m;
int main() {
    tree.init(100);
    m = read();
    for(int i = 0; i < m; ++i) tmp[i] = a[i] = read();
    sort(tmp, tmp + m);
    real_m = unique(tmp, tmp + m) - tmp;
    for(int i = 0; i < m; ++i) {
        x = lower_bound(tmp, tmp + real_m, a[i]) - tmp;
        write(tree.sum(x)), putchar(' ');
        tree.add(x + 1, 1);
    }
}
