#include<iostream>
#include<algorithm>
#define maxn 3000100
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll a[maxn];
ll A, B, C, k;
inline void buildArray() {
    for (int i = 2; i <= 3000000; ++i)
        a[i] = ((1LL * a[i - 1] * A ^ B) + C) % 1000000007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> A >> B >> C >> a[1] >> k) {
        buildArray();
        nth_element(a + 1, a + k, a + 3000000 + 1);
        cout << a[k] << endl;
    }
}
