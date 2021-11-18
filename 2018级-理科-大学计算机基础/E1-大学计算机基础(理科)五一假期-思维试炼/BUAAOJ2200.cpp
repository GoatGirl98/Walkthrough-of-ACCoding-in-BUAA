#include<iostream>
#define maxn 10010
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int n;
int tmp;
int odd1, noodd1, odd2, noodd2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> tmp;
            if (tmp & 1)++odd1; else ++noodd1;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> tmp;
            if (tmp & 1)++odd2; else ++noodd2;
        }
        cout << Min(odd1, noodd2) + Min(odd2, noodd1) << endl;
    }
}
