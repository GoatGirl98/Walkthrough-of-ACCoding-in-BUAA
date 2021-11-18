#include<iostream>
#include<string>
using namespace std;
string a;
int t;
int pos;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        getline(cin, a);if(a.back()=='\r')a.pop_back();
        if (a.empty()) { ++t; continue; }
        while ((pos = a.find("esolc")) != a.npos) {
            a = a.replace(pos, 5, "");
        }
        while ((pos = a.find("abc")) != a.npos) {
            a = a.replace(pos, 3, "dnalsi");
        }
        cout << a << endl;
    }
}
