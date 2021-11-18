#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lower[27] = "abcdefghijklmnopqrstuvwxyz";
string input;
int start, finish;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> input) {
        if (isupper(input[0])) {
            start = input[0] - 'A';
            finish = input[1] - 'A';
            for (; start != finish; start = (start + 1) % 26) {
                cout << upper[start];
            }
            cout << upper[finish] << endl;
        }
        else {
            start = input[0] - 'a';
            finish = input[1] - 'a';
            for (; start != finish; start = (start + 1) % 26) {
                cout << lower[start];
            }
            cout << lower[finish] << endl;
        }
    }
}
