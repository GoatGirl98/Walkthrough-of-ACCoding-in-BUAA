#include<iostream>
#define maxn 10010
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n) {
        if (n <= 2)cout << "impossible!" << endl;
        else {
            cout << "YES" << endl;
            if (n & 1) {
                cout << 1 << " " << (n + 1) / 2 << endl;
                cout << n - 1 << " ";
                for (int i = 1; i <= n; ++i) {
                    if (i != (n + 1) / 2)cout << i << " ";
                }
                cout << endl;
            }
            else {
                cout << 2 << " " << 1 << " " << n << endl;
                cout << n - 2 << " ";
                for (int i = 2; i < n; ++i)cout << i << " ";
                cout << endl;
            }
        }
    }
}
