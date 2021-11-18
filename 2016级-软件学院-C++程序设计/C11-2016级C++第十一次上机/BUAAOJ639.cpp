#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string a;
string tmp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    a = "";
    while (cin >> tmp) {
        a += toupper(tmp[0]);
    }
    cout << a;
}
