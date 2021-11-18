#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPrime(int a) {
	if (!(a & 1)) {
		if (a == 2)return true;
		else return false;
	}
	else if (a == 1)return false;
	else {
		int b = (int)sqrt(a);
		for (int k = 3; k <= b; k += 2) {
			if (!(a % k))return false;
		}
		return true;
	}
}

int primeCount(int n, int m) {
	int res = 0;
	while (n) {
		n /= m;
		res += n;
	}
	return res;
}
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> m) {
		if (!isPrime(m)) cout << "I choose go die" << endl;
		else cout << primeCount(n, m) << endl;
	}
}