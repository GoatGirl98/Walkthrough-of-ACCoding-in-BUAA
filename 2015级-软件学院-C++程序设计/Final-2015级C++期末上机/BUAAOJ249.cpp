#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 1010
using namespace std;
int n;
int need[maxn];
int occured[maxn];
int got;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n) {
		got = 0; ans = 0;
		memset(occured, 0, sizeof(occured));
		for (int i = 1; i <= n; ++i) cin >> need[i];
		while (got < n) {
			for (int i = 1; i <= n; ++i) {
				if (need[i] <= got && !occured[i]) {
					got++; occured[i] = true;
				}
			}
			if (got == n)break;
			ans++;
			for (int i = n; i >= 1; --i) {
				if (need[i] <= got && !occured[i]) {
					got++; occured[i] = true;
				}
			}
			if (got == n)break;
			ans++;
		}
		cout << ans << endl;
	}

}
