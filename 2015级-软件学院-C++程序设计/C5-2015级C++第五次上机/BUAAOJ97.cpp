#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[50];

inline void buildDP() {
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i < 50; ++i) {
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
