#include<string>
#include<iostream>
using namespace std;
int k,a;
string s1, s2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> s1 >> s2) {
        k = 0;
        for (int i = 0; i <= s1.length() - s2.length(); ++i) {
            if (s1.substr(i, s2.length()) == s2)++k;
        }
        cout << k << endl;

    }
    return 0;
}
