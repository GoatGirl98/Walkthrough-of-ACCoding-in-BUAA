#include<cstdio>
#include<algorithm>
#define maxn 1000010
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
inline void Swap(int& a, int& b) {
    int& c = a;
    int d = a;
    a = b;
    b = d;
}
struct area {
    int l, r;
    bool operator <(const area& o)const {
        return r < o.r;
    }
} a[maxn];
int n;
int l, r;
int res;
int main() {
    while (scanf("%d", &n) != EOF) {
        res = 1;
        for (int i = 0; i < n; ++i) {
            l = read(), r = read();
            if (l > r)Swap(l, r);
            a[i].l = l, a[i].r = r;
        }
        if (n == 0 || n == 1) { write(n); return 0; }
        sort(a, a + n);
        int tmp = a[0].r;
        for (int i = 1; i < n; ++i) {
            if (a[i].l >= tmp) {
                ++res;
                tmp = a[i].r;
            }
        }
        write(res);putchar('\n');
    }
}
