#pragma G++ optimize(2)
#include<iostream>
using namespace std;
int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int y, m, d;
inline bool isRun() {
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}
inline bool isIllegal() {
	return (y <= 0 || y > 2016 || y == 2016 && (m > 10 || m == 10 && d > 19));
}
inline bool isIllegal2() {
	return (d <= 0 || m <= 0 || m > 12 || d > day[m - 1]);
}
inline void print() {
	cout << "Wang assistant is " << y << " year";
	if (y > 1) cout << "s";
	cout << ", " << m << " month";
	if (m > 1)cout << "s";
	cout << ", " << d << " day";
	if (d > 1)cout << "s";
	cout << " old." << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> y >> m >> d) {
		if (isRun()) day[1] = 29;
		if (isIllegal() || isIllegal2())cout << "Invaild date." << endl;
		else {
			if (m < 10) {
				y = 2016 - y;
				if (d <= 19) {
					d = 19 - d;
					m = 10 - m;
				}
				else {
					d = day[m - 1] - d + 19;
					m = 9 - m;
				}
			}
			else if (m > 10) {
				y = 2015 - y;
				if (d <= 19) {
					d = 19 - d;
					m = 22 - m;
				}
				else {
					d = day[m - 1] - d + 19;
					m = 21 - m;
				}
			}
			else {
				if (d <= 19) {
					y = 2016 - y;
					d = 19 - d;
					m = 0;
				}
				else {
					y = 2015 - y;
					d = 50 - d;
					m = 11;
				}
			}
			print();
		}
		day[1] = 28;
	}
}