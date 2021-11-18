#include<iostream>
#include<cstring>
#define maxn 510
#define debug 0
using namespace std;
int mask[maxn][maxn];
long long dp[maxn][maxn];
int m, n;
inline long long Max(long long a, long long b) {
    return (a > b ? a : b);
}
inline void erase() {
    memset(mask, 0, sizeof(mask));
    memset(dp, 0, sizeof(dp));
}
inline void buildDP() {
    dp[1][1] = 1ll * mask[1][1];

    for (int i = 2; i <= m; ++i) {
        dp[1][i] = dp[1][i - 1] + 1ll * mask[1][i];
    }

    for (int i = 2; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] + 1ll * mask[i][1];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]) + mask[i][j];
        }
    }

}
inline int read() {
    int k = 0;
    int f = 1;
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
inline void write(long long x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline void printDP() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            write(dp[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        erase();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> mask[i][j];
            }
        }
        buildDP();
        if (debug)printDP();
        cout << dp[n][m] << endl;
    }

}
