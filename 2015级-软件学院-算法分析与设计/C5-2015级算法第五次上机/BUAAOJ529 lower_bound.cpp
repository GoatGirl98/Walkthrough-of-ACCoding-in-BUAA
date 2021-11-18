#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 4000010;
int a[maxn];
int n, m;
int tmp;
int Case;
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
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < m; ++i)
            a[i] = read();
        printf("Case %d:\n", ++Case);
        while (n--) {
            tmp = read();
            int lala = *lower_bound(a, a + m, tmp);
            puts(tmp == lala ? "Yes" : "No");
        }
    }
}
