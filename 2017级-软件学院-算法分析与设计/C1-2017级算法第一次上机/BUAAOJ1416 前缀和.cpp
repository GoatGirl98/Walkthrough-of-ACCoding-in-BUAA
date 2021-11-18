#pragma GCC optimize(2)
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 1000010
#define RADIX 10
#define MOD 10007
typedef long long ll;
int n, q;
ll a[maxn];
int tmp;
int l, r;
inline int read() {
    int k = 0;
    char c = getchar();
    while (!isdigit(c))c = getchar();
    while (isdigit(c)) { k = (k << 1) + (k << 3) + c - 48; c = getchar(); }
    return k;
}
inline void write(ll a) {
    if (a >= RADIX)write(a / RADIX);
    putchar(a % RADIX + 48);
}
int main() {
    while (scanf("%d", &n) != EOF) {
        q = read();
        for (int i = 1; i <= n; ++i) {
            tmp = read();
            a[i] = (tmp + a[i - 1]) % MOD;
        }
        while (q--) {
            l = read(), r = read();
            write((a[r] - a[l - 1] + MOD) % MOD);
            putchar('\n');
        }
    }
}
