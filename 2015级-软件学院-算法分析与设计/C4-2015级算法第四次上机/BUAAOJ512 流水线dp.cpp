#include<cstdio>
#include<climits>
#include<cstring>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define maxn 1010
typedef long long ll;
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
int m, n;
int pre, now;
ll dp[maxn][2];
ll ans;
int work[maxn];
int to[maxn][maxn];
/*****************************
******************************/
inline void init() {
    for (int i = 1; i <= n; ++i)dp[i][0] = LLONG_MAX, dp[i][1] = LLONG_MAX;
    memset(work, 0, sizeof(work));
    memset(to, 0, sizeof(to));
}
inline void buildDP() {
    for (int i = 1; i <= n; ++i)dp[i][now] = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][now] = Min(dp[i][now], work[i] + dp[j][pre] + to[j][i]);
        }
    }
    now = 1 - now, pre = 1 - pre;
}
inline void printAns() {
    ans = LLONG_MAX;
    for (int i = 1; i <= n; ++i)ans = Min(ans, dp[i][pre]);
    write(ans), putchar('\n');
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        now = 1, pre = 0;
        for (int i = 1; i <= n; ++i)
            dp[i][pre] = read();
        for (int i = 2; i <= m; ++i) {
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                    to[j][k] = read();
            for (int j = 1; j <= n; ++j)
                work[j] = read();
            buildDP();
        }
        printAns();
    }
}
