#include<iostream>
#include<algorithm>
#include<climits>
#define maxn 100010
using namespace std;
int n;
int l[maxn], r[maxn];
int g[maxn];
int dp[maxn];
int ans;

inline void dfs(int x) {
    if (x != 0) {
        dfs(l[x]), dfs(r[x]);
        g[x] = max(g[l[x]], g[r[x]]) + 1;
    }
    else {
        g[x] = 0;
    }
}
inline void buildDP() {
    dfs(1);
    ans = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        dp[i] = g[l[i]] + g[r[i]] + 1;
        if (dp[i] > ans)ans = dp[i];
    }
    cout << ans - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
    }
    buildDP();
}
