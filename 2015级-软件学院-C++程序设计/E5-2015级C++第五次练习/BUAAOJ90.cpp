#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define INF 10010

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    int t;
    int n;
    cin >> t;
    string a;
    string ans;
    while (t--) {
        cin >> n >> a;
        ans = "";
        int count = 1; char cur = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != cur) {
                if (cur)ans += to_string(count) + cur;
                count = 1; cur = a[i];
            }
            else count++;
            //cout << count << " " << cur << endl;
        }
        if (cur)ans += to_string(count) + cur;
        cout << ans << endl;
    }

    return 0;
}
