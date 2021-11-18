#include<iostream>
#include<stack>
#include<string>
using namespace std;

int T;
int m, n;
stack<string>subway;
string tmp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    while (cin >> T) {
        while (!subway.empty()) subway.pop();
        while (T--) {
            cin >> m >> n;
            while (m--) { if (!subway.empty())subway.pop();}
            while (n--) {
                cin >> tmp;
                subway.push(tmp);
            }
        }
        while (!subway.empty()) {
            cout << subway.top() << endl;
            subway.pop();
        }
    }

}
