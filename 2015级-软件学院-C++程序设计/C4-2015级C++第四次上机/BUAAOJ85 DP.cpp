#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define maxn 10010
ll dp[maxn];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	dp[1] = 1ll * 2;
	for (int i = 2; i < maxn; ++i) {
		dp[i] = dp[i - 1] + 6 * (i - 1);
	}
	while (cin >> n)cout << dp[n] << endl;
}
