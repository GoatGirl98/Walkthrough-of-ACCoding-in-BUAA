#include<iostream>
#include<cstring>
#define maxn 10100
using namespace std;
int A[maxn], B[maxn];
short dp[2][maxn];
int curLen;
int cur, pre;
int n, m;
inline void eraseDP() {
    memset(dp, 0, sizeof(dp));
    pre = 0, cur = 1, curLen = 0;
}
inline void buildDP() {
    for (int i = 1; i <= n; ++i) {
        curLen = 0;//将dp[pre][j]的结果充分利用，避免重复运算
        for (int j = 1; j <= m; ++j) {
            dp[cur][j] = dp[pre][j];

            if (B[j]<A[i] && dp[pre][j] > curLen) {
                curLen = dp[pre][j];
            }
            if (B[j] == A[i])dp[cur][j] = curLen + 1;
        }
        cur = 1 - cur, pre = 1 - pre;
    }
}
inline void printAns() {
    short ans = 0;
    for (int i = 1; i <= m; ++i) if (dp[pre][i] > ans)ans = dp[pre][i];
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i)cin >> A[i];
        for (int i = 1; i <= m; ++i)cin >> B[i];
        eraseDP(); buildDP();
        printAns();
    }
}
