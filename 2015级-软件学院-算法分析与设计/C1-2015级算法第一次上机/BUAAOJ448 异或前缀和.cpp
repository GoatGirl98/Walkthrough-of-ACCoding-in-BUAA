#include<cstdio>
#define maxn 1000010
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
int n, k, x, y;
int a[maxn];
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i)
            a[i] = read(), a[i] ^= a[i - 1];
        k = read();
        while (k--) {
            x = read(), y = read();
            if (x > y) { int k = x; x = y, y = k; }
            write(a[y] ^ a[x - 1]); putchar('\n');
        }
    }
}
