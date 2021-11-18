#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
string a;
bool occur[27];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (getline(cin,a)) {
        if (a.empty())continue;
        memset(occur, 0, sizeof(occur));
        for (int i = 0; i < a.length(); ++i) {
            if(isalpha(a[i])) occur[toupper(a[i]) - 'A'] = true;
        }
        int cnt = 0;
        for (int i = 0; i < 26; ++i) { if (!occur[i]) { cout << (char)('A' + i) << " "; cnt++; } }
        if (!cnt)cout << "OK!";
        cout << endl;
    }
}
