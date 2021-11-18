#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[55];

inline void buildDP() {
    dp[1] = 3, dp[2] = 6, dp[3] = 6;
    for (int i = 4; i < 55; ++i) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
}
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    buildDP();
    while (cin >> n) cout << dp[n] << endl;
}
