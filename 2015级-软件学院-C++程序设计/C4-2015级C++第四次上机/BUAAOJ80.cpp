#include<iostream>
#include<cstring>
#include<cctype>
#include<string>
using namespace std;
string n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n.length(); ++i) {
            if (islower(n[i])) {
                n[i] = toupper(n[i]);
            }
            else if (isupper(n[i])) {
                n[i] = tolower(n[i]);
            }
        }
        cout << n << endl;
    }
}
