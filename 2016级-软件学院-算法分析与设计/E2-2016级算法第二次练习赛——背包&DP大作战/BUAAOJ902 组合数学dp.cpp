#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define nmaxn 50050
#define mmaxn 350
#define debug 0
int dp[nmaxn][mmaxn];
//dp[i][j]为i恰好被分成j个数
inline void buildDP() {
    dp[0][0] = 1;
    
    for (int j = 1; j <= 330; ++j) {
        for (int i = 0; i <= 50000; ++i) {
            if (i - j >= 0) {
                dp[i][j] = (dp[i - j][j] + dp[i - j][j - 1]) % 1000007;
            }
        }
    }

}
inline void printPart() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            printf("%3d", dp[i][j]);
        }
        putchar('\n');
    }
}
int n;
int ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    buildDP();
    while (cin >> n) {
        ans = 0;
        for (int i = 1; i <= 330 && dp[n][i]; ++i) {
            ans += dp[n][i];
            ans %= 1000007;
        }
        cout << ans << endl;
    }
}
