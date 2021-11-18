#include<iostream>
#include<stack>
#include<string>
using namespace std;
int n;
string op;
int opNum;

stack <int> lalala;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n) {
        while (!lalala.empty()) {
            lalala.pop();
        }
        while (n--) {
            cin >> op;
            if (op == "USH") {
                cin >> opNum;
                lalala.push(opNum);
            }
            else if (op == "GET") {
                if (lalala.empty()) cout << "EMPTY!" << endl;
                else {
                    cout << lalala.top() << endl;
                }
            }
            else {
                if (!lalala.empty())lalala.pop();
            }
        }
        cout << endl;
        cin >> n;
    }
}
