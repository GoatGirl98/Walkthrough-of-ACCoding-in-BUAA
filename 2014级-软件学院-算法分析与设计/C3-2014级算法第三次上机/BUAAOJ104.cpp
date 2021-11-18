#include<iostream>
#include<algorithm>
#define maxn 10010
int a[maxn];
int n;
typedef long long ll;
using namespace std;
ll res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        res = 0;
        for (int i = 0; i < n; ++i) {
            res += a[i] * (n - 1 - i);
        }
        cout << res << endl;
    }
}
