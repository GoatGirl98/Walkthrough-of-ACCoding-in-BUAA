#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n >> m) {
		if (m == 1)cout << n << endl;
		else if (m == 2) {
			cout << n + m << endl;
		}
		else {
			cout << n + m + m - 2 << endl;
		}
	}
}