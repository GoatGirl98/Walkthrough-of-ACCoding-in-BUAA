#pragma GCC optimize(2)
#include<iostream>
#define maxn 70
using namespace std;
typedef long long ll;
ll dp[maxn];
inline void buildDP() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 3;
    dp[6] = 4;
    dp[7] = 6;
    for (int i = 8; i < maxn; ++i) {
        if (i <= 13) dp[i] = dp[i - 1] + dp[i - 3];
        else if (i <= 16)dp[i] = dp[i - 1] + dp[i - 3] - dp[i - 13];
        else dp[i] = dp[i - 1] + dp[i - 3] - dp[i - 13];
        //此处坑点，这个时候死掉的不能算上，会对后面有影响的
    }
}
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    buildDP();
    while (cin >> n) {
        cout << (n > 16 ? ((dp[n] - dp[n - 16]) << 1):(dp[n] << 1)) << endl;
    }
}
