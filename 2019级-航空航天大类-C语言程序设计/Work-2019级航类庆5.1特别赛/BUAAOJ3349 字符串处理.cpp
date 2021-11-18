#include<iostream>
#include<string>
using namespace std;
string text, pattern;
int pos;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (cin >> text >> pattern) {
		text.push_back(';');
		while ((pos = text.find(pattern)) != text.npos)
			text.replace(pos, pattern.length(), ";\n");
		puts(text.c_str());
	}
}