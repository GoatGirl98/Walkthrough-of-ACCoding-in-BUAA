#include<iostream>
#include<algorithm>
#define maxn 100010
using namespace std;
int n;
int map[maxn];

inline int buildMax(int l, int r) {
    int last1 = 0, last2 = 0;
    for (int i = l; i <= r; ++i) {
        int tmp = last1;
        last1 = max(last1, last2 + map[i]);
        last2 = tmp;
    }
    //动态打表
    return last1;
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 1; i <= n; ++i)cin >> map[i];
        if (n == 1)cout << map[1] << endl;
        else if (n == 2)cout << (max(map[1], map[2])) << endl;
        else cout << (max(buildMax(1, n - 1), buildMax(2, n))) << endl;
    }
}
