#include<iostream>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int t, a, b, r1, r2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b >> r1 >> r2;
		if (2 * Max(r1, r2) > Min(a, b))cout << "NO";
		else {
			if ((a - r1 - r2) * (a - r1 - r2) + (b - r1 - r2) * (b - r1 - r2) >= (r1 + r2) * (r1 + r2)) {
				cout << "YES";
			}
			else cout << "NO";
		}
		cout << endl;
	}
}