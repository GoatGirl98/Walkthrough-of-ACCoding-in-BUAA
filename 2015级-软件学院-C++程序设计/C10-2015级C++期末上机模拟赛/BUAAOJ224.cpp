#pragma G++ optimize(2)
#include<iostream>
#include<string>
typedef long long ll;
using namespace std;
string a;
int quesMark;
inline ll getNum(string a) {
    ll k = 0, f = 1;
    unsigned int i = 0;
    if (a[0] == '-') { f = -1; ++i; }
    for (; i < a.length(); ++i) {
        k = (k << 1) + (k << 3) + a[i] - 48;
    }
    return k * f;
}
inline bool parse() {
    int plus = a.find("+");
    int equal = a.find("=");
    string op1 = a.substr(0, plus);
    string op2 = a.substr(plus + 1, equal - plus - 1);
    string op3 = a.substr(equal + 1, a.length() - equal - 1);
    if (getNum(op1) + getNum(op2) == getNum(op3)) return true;
    else return false;
}
inline ll handle() {
    int plus = a.find("+");
    int equal = a.find("=");
    if (quesMark > equal) {
        string op1 = a.substr(0, plus);
        string op2 = a.substr(plus + 1, equal - plus - 1);
        return getNum(op1) + getNum(op2);
    }
    else if (quesMark > plus) {
        string op1 = a.substr(0, plus);
        string op3 = a.substr(equal + 1, a.length() - equal - 1);
        return getNum(op3) - getNum(op1);
    }
    else {
        string op2 = a.substr(plus + 1, equal - plus - 1);
        string op3 = a.substr(equal + 1, a.length() - equal - 1);
        return getNum(op3) - getNum(op2);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    while (cin >> a) {
        quesMark = a.find("?");
        if (quesMark != a.npos)cout << handle() << endl;
        else cout << (parse() ? "Right!" : "Error!") << endl;
    }
}
