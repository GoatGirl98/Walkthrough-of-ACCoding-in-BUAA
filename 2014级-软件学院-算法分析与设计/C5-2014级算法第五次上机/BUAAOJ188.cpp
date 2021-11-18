#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000000 + 10;
int a[maxn];
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
int n, m;
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)a[i] = read();
        int* pos = lower_bound(a, a + n, m);
        int* pos2 = lower_bound(a, a + n, a[pos - a - 1]);
        write(pos - pos2), putchar('\n');
    }
}
