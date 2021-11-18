#include<iostream>
#include<algorithm>
#include<cmath>
#define maxn 10010
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
typedef long long ll;
int res;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m) {
        double t, ans = 0;
        for (int i = 1; i <= n; ++i) {
            t = (double)i / n * (n + m);
            ans += fabs(t - floor(t + 0.5)) / (n + m);
        }
        printf("%.15lf\n", ans * (n + m));
    }
}
