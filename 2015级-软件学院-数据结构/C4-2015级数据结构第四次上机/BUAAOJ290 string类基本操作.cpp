#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;
//本题意在模仿string类的stl操作，但是在不禁stl的情况下就直接用吧
string add = "Add";
string del = "Del";
string rep = "Rep";
string a;
string op;

int opA;
char opB;
int opC;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        cin >> a;
        vector<char> b;
        for (int i = 0; i < a.length(); ++i) {
            b.push_back(a[i]);
        }
        while (m--) {
            cin >> op;
            
            if (op == add) {
                cin >> opA >> opB;
                b.insert(b.begin()+opA-1, opB);
            }
            else if (op == del) {
                cin >> opA >> opC;
                while (opC--) {
                    b.erase(b.begin() + opA - 1);
                }
            }
            else {
                cin >> opA >> opB;
                b[opA - 1] = opB;
            }

        }
        for (char c : b)cout << c;
        cout << endl;
    }
}
