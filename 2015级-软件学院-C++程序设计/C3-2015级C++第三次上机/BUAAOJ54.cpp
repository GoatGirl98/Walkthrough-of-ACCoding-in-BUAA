#include<iostream>
#include<cctype>
#include<algorithm>
#include<string>
using namespace std;
int counter,code;
string lalala;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> lalala) {
        counter = 1;
        code = 0;
        for (int i = 0; i < lalala.length() - 1; ++i) {
            if (lalala[i] == '-')continue;
            code += (lalala[i] - 48) * counter;
            //cout << "code is " << code << endl;
            ++counter;
        }
        code %= 11;
        if (lalala[lalala.length() - 1] == code + 48)cout << "Right" << endl;
        else if (lalala[lalala.length() - 1]=='X' && code==10)cout << "Right" << endl;
        else { lalala[lalala.length() - 1] = (code==10)?'X' : code + 48; cout << lalala << endl; }
    }
}
