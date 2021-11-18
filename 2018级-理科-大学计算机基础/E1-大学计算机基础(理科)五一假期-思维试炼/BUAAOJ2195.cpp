#include<iostream>
#define maxn 10010
using namespace std;
int n;
int tmp;
int eightcount, target;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    target = (n - 8) / 2 + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        if (i <= n - 7 && tmp == 8)eightcount++;
    }
    if (eightcount >= target)cout << "YES" << endl;
    else cout << "NO" << endl;
}
