#include<string>
#include<iostream>
#include<climits>
#include<algorithm>
#define maxn 100010
using namespace std;
long long a[maxn];
int n;
long long result = LLONG_MAX;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        result = min(result, a[i + 1] - a[i]);
    }
    cout << a[0] << " " << result;
}
