#include<iostream>
#define maxn 1000010
using namespace std;
int a[maxn];
int n;
int main() {
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= n; ++i)cin >> a[i];
        for (int hi = n, lo = 1; hi >= lo; hi--, lo++) {
            cout << a[hi] << " ";
            if (hi > lo)cout << a[lo] << " ";
        }
        cout << endl;
    }
}
