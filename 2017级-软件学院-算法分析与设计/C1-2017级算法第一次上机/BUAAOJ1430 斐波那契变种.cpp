#pragma GCC optimize(2)
#include<iostream>
#define maxn 70
using namespace std;
typedef long long ll;
ll dp[maxn];
inline void buildDP() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 5;
    dp[6] = 8;
    dp[7] = 13;
    for (int i = 8; i < maxn; ++i) {
        if (i <= 12) dp[i] = dp[i - 1] + dp[i - 2];
        else if (i <= 20)dp[i] = dp[i - 1] + dp[i - 2] - dp[i - 12];
        else dp[i] = dp[i - 1] + dp[i - 2] - dp[i - 12];
        //此处坑点，这个时候死掉的不能算上，会对后面有影响的
    }
}
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    buildDP();
    while (t--) {
        cin >> n;
        cout << (n > 20 ? ((dp[n] - dp[n - 20]) << 1):(dp[n] << 1)) << endl;
    }
}
