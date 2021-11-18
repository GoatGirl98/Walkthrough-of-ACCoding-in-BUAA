#include<iostream>
#define maxn 100010
using namespace std;
/************************
其实这题贪心也是可以的
************************/
int num[maxn], b[maxn], cnt[2 * maxn];

int main() {
    int n;
    int res = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        b[i] = b[i - 1] + 2 * num[i] - 1;
        if (cnt[b[i] + maxn]) {
            if (res < i + 1 - cnt[b[i] + maxn]) {
                res = i + 1 - cnt[b[i] + maxn];
            }
        }
        else cnt[b[i] + maxn] = i + 1;

    }
    cout << res;
}
