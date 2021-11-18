#include<iostream>
#define maxn 10010
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n) {
        if (!(n & 1))cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
