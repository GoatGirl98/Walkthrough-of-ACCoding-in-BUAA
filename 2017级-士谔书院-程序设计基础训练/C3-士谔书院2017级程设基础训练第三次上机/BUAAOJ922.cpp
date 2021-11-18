#include<iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    int k = 2;
    cin >> n;
    while (k <= n) {
        if (!(n % k)) {
            n /= k;
            cout << k << " ";
            continue;
        }
        k++;
    }
    return 0;
}
