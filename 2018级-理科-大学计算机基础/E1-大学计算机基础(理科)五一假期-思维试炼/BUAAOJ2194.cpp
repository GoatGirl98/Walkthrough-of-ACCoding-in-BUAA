#include<string>
#include<iostream>
#define maxn 100010
using namespace std;

int a[maxn];
inline void init() {
    for (int i = 1; i < maxn; ++i) {
        for (int j = i; j < maxn; j += i) a[j]++;
    }
}
int b;
long long ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init();
    cin >> b;
    for (int i = 1; i <= b; ++i)ans += a[i];
    cout << ans << endl;
    return 0;
}
