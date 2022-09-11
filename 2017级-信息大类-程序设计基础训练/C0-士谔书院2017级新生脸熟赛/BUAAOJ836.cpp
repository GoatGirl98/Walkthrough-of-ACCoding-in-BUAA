#pragma G++ optimize(2)
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string a;
inline bool handle() {
    if (a.length() < 5)return false;
    if (!(isdigit(a[0]) && isdigit(a[1]) && isdigit(a[2]) && isdigit(a[3]) && isspace(a[4]))) return false;
    a = a.replace(0, 5, "");
    int pos;
    if ((pos = a.find(" ")) == a.npos)return false;
    a = a.replace(0, pos + 1, "");
    if ((pos = a.find(" ")) != a.npos)return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (getline(cin, a)) {
        if (a.empty())continue;
        cout << (handle() ? "meng xin bao zhao!" : "qiu qiu ni le, gai ming pian ba") << endl;
    }
}
