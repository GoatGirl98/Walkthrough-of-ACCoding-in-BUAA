#include<cstdio>
#include<cstring>
#define max(a,b) (((a)>(b))?(a):(b))
inline void write(int x) {
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
int a[10010];
int n;
int l, r;
int ans;
int main() {
    while(scanf("%d",&n) != EOF) {
        ans = 0;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; ++i) {
            l = read(), r = read();
            if(l > r) l ^= r, r ^= l, l ^= r;
            a[l] += 1, a[r + 1] -= 1;
        }
        for(int i = 1; i <= 10000; ++i)
            a[i] += a[i - 1], ans = max(ans, a[i]);
        write(ans), putchar_unlocked('\n');
    }
}
