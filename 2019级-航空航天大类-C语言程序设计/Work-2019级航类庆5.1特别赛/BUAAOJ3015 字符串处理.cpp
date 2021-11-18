#include<iostream>
#include<cctype>
#include<sstream>
#include<vector>
using namespace std;
int m, n;
string a, b;
string input;
vector<string>reala, realb;
string tmp;
bool sync;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	getline(cin, input);
	stringstream s1(input);
	sync = true;
	s1 >> m >> n;
	while (m--) {
		getline(cin, input);
		a += input + '\n';
	}
	while (n--) {
		getline(cin, input);
		b += input + '\n';
	}
	if (a == b)puts("Accepted");
	else {
		stringstream A(a), B(b);
		while (A >> tmp)reala.push_back(tmp);
		while (B >> tmp)realb.push_back(tmp);
		if (reala.size() != realb.size())sync = false;
		else {
			for (int i = 0; i < reala.size(); ++i)
				if (reala[i] != realb[i]) { sync = false; break; }
		}
		if (sync)puts("Presentation Error");
		else puts("Wrong Answer");
	}
}