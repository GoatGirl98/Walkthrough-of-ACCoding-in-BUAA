#include<iostream>
#define maxn 110
using namespace std;
int a[maxn];
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (!n)cout << "NULL";
        while (n--) {
            cout << a[n] << " ";
        }
        cout << endl;
    }

}
