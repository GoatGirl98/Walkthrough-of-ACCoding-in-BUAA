#include<iostream>
#include<algorithm>
#define nmaxn 10101
#define mmaxn 1010
using namespace std;
//这题才不是一个第二类stirling数...
/***************************************
n球和m箱子的专题需要总结一下
当可以空的时候
初始条件
dp[k][1] = dp[1][k] = dp[0][k] = 1
转移方程
dp[n][m]=dp[n-m][m]+dp[n][m-1] n>=m
dp[n][m]=dp[n][m-1] n<m
不可以空的时候
f[n][m]=dp[n-m][m] n>=m  f[n][m]=0 n<m
***************************************/
int dp[nmaxn][mmaxn];

inline void buildDP() {
    for (int i = 1; i <= 10000; ++i) {
        dp[i][1] = 1;
        if (i <= 1000) {
            dp[1][i] = 1;
            dp[0][i] = 1;//初始化重要的一步!
        }
    }
    for (int i = 1; i <= 10000; ++i) {
        for (int j = 2; j <= 1000; ++j) {
            if (j > i)dp[i][j] = dp[i][j - 1];
            else dp[i][j] = (dp[i - j][j] + dp[i][j - 1]) % 1000007;
        }
    }
}
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    buildDP();
    while (cin >> n >> m) {
        if (n >= m)cout << dp[n - m][m] << endl;
        else cout << 0 << endl;
    }
}
