#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 4000;
inline void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
int a[maxn];
int tails[maxn];
int res;
int m, n;
int A, B, C;
inline int nxt(int pre) {
    return (1ll * pre * A + B) % C;
}
int main() {
    m = read(), n = read();
    tails[0] = -114514;
    for(int i = 1; i <= m; ++i) {
        a[1] = read(), A = read(), B = read(), C = read();

        for(int j = 2; j <= n; ++j)a[j] = nxt(a[j - 1]);
        
        sort(a + 1, a + n + 1);
        
        int x = upper_bound(a + 1, a + n + 1, tails[res]) - a;
        if(x != n + 1) tails[++res] = a[x];
        
        int cur = 114514;
        for(cur = res - 1; cur >= 0; --cur) {
            int x = upper_bound(a + 1, a + n + 1, tails[cur]) - a;
            if(x != n + 1) {tails[cur + 1] = min(tails[cur + 1], a[x]); }
        }
        
    }
    write(res);
}