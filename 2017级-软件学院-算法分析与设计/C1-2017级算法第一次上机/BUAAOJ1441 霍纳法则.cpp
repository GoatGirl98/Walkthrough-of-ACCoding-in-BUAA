#include<iostream>
#include<string>
using namespace std;
#define INF 100010
#define RADIX 8
#define MOD 1000000007
string a;
int t;
int handlemod(int a) {
    int res = a;
    for (int i = 1; i < RADIX; ++i) {
        res += a;
        res %= MOD;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a;
        int res = 0;
        for (int i = 0; i < a.length(); ++i) {
            //cout << res << endl;
            res = (handlemod(res) + a[i] - 48) % MOD;
            //cout << res << endl;
        }
        cout << res << endl;
    }
}
