#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
string a, b;
double W1, W2, W3, W4;
double P1, P2, P3, P4;
double BP;
char c;
double calP(int n) {
	string token = "";//ÓÃÓÚÌæ»»ÒÑÆ¥Åä×Ö·û
	string A = a, B = b;
	for (int i = 0; i < n; ++i)token.push_back('\n');
	int start = 0;
	int matched = 0, total = 0;
	while (start <= A.size() - n) {
		total++;
		string tmp = A.substr(start, n);
		int pos = B.find(tmp);
		if (pos != B.npos)matched++, start += n, B.replace(pos, n, token);
		else start += 1;
	}
	return double(matched) / double(total);
}
int main() {
	getline(cin, a);
	if (a.back() == '\r')a.pop_back();
	getline(cin, b);
	if (b.back() == '\r')b.pop_back();
	cin >> W1 >> W2 >> W3 >> W4;
	BP = (a.length() <= b.length()) ? exp(1.0 - ((double)b.length() / (double)a.length())) : 1;
	P1 = calP(1), P2 = calP(2), P3 = calP(3), P4 = calP(4);
	double sum = ((W1 * log2(P1) + W2 * log2(P2) + W3 * log2(P3) + W4 * log2(P4)));
	double ans = BP * exp(sum);
	cout << fixed << setprecision(4) << ans;
}