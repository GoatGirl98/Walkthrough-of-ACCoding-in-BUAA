#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[1000010];
int t;
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
    t = read();
    while (t--) {
        n = read();
        for (int i = 0; i < n; ++i)a[i] = read();
        sort(a, a + n);
        write(a[0] + a[1]);
        putchar(' ');
        write(a[n - 1] + a[n - 2]);
        putchar('\n');
    }
}
