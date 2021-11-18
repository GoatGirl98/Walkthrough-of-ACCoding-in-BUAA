#include<cstdio>
#include<cstring>
typedef long long ll;
ll sumAB[2000010];
const int maxn = 4010;
const int MID = 1000000;
int n;
ll ans;
int a[maxn], b[maxn], c[maxn], d[maxn];
inline void write(ll x) {
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
    while (scanf("%d",&n) != EOF) {
        memset(sumAB, 0, sizeof(sumAB));
        ans = 0;
        for (int i = 0; i < n; ++i)a[i] = read();
        for (int i = 0; i < n; ++i)b[i] = read();
        for (int i = 0; i < n; ++i)c[i] = read();
        for (int i = 0; i < n; ++i)d[i] = read();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sumAB[a[i] + b[j] + MID]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += sumAB[MID - (c[i] + d[j])];
            }
        }
        write(ans), putchar('\n');
    }
}
