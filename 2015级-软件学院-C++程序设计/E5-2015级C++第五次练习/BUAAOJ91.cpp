#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define INF 10010

using namespace std;

int n;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        bool flag = false;
        for (int i = 1; i <= n; ++i) {
            if (i % 10 + (i % 100) / 10 + (i % 1000) / 100 + (i % 10000) / 1000 + (i % 100000) / 10000 + i == n) { cout << i << endl; flag = true; break; }

        }
        if(!flag)cout << 0 << endl;
    }


    return 0;
}
