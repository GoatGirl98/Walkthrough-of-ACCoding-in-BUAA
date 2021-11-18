#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
bool occur[26];
bool judge(const string& s) {
	int ret = 0;
	memset(occur, 0, sizeof(occur));
	for (int i = 0; i < s.length(); ++i) {
		if (!islower(s[i])) return false;
		else occur[s[i] - 'a'] = 1;
	}
	for (int i = 0; i <= 25; ++i)ret += occur[i];
	return ret >= 26;
}
string in;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (getline(cin, in)) {
		if (in.back() == '\r')in.pop_back();
		in = in.substr(1, in.length() - 2);
		puts(judge(in) ? "True" : "False");
	}
}