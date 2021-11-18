#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lower[27] = "abcdefghijklmnopqrstuvwxyz";
string input;
int sizela;
bool flag;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> sizela) {
        flag = false;
        cin >> input;
        for (int i = 0; i < input.length() - 2; ++i) {
            if (input[i + 2] - input[i + 1] == 1 && input[i + 1] - input[i] == 1)flag = true;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

}
