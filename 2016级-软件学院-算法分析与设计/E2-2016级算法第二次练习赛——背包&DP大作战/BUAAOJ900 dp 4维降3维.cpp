#include<iostream>
#include<cstring>
#define maxn 205
#define print 0
using namespace std;

int mask[maxn][maxn];
long long dp[maxn][maxn][maxn];
//视为两个人同时走路，(i,j)是第一个人的坐标，k是第二个人的x坐标，此时y坐标即为i+j-k
int n, m;
inline void erase() {
    memset(mask, 0, sizeof(mask));
    memset(dp, 0, sizeof(dp));
}
inline long long max(long long a, long long b, long long c, long long d) {
    if (a >= b && a >= c && a >= d)return a;
    if (b >= a && b >= c && b >= d)return b;
    if (c >= a && c >= b && c >= d)return c;
    if (d >= a && d >= b && d >= c)return d;
}
inline void buildDP() {
    dp[1][1][1] = 1ll * mask[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= n && k <= (i + j); k++) {
                int p = i + j - k;
                if (k != i) {
                    dp[i][j][k] = mask[i][j] + mask[k][p] +
                        max(dp[i - 1][j][k - 1], dp[i - 1][j][k],
                            dp[i][j - 1][k - 1], dp[i][j - 1][k]);
                }
                else {
                    dp[i][j][k] = mask[i][j] +
                        max(dp[i - 1][j][k - 1], dp[i - 1][j][k],
                            dp[i][j - 1][k - 1], dp[i][j - 1][k]);
                }
                //整个for循环其实不用考虑边界，0的地方自然就是0
            }
        }
    }
}
inline void printDP() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= n && k <= (i + j); k++)
                cout << dp[i][j][k];
            cout << endl;
        }
        cout << "-------------------" << endl;
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
        if (print)printDP();
        cout << dp[n][m][n] << endl;
    }
}
