#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        cout << ((min(n, m) & 1) ? "jhljx" : "KamuiKirito") << endl;
    }
}
