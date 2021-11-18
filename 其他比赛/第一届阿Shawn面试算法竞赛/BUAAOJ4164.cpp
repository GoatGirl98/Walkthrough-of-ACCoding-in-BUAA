#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;
string s[10010], x;
unordered_map<string, int> a;
int n;
int ans;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        ans ^= i;
        cin >> s[i], a[s[i]] = i;
    }
    for(int i = 1; i < n; ++i) {
        cin >> x, ans ^= a[x];
    }
    cout << s[ans] << endl;
}