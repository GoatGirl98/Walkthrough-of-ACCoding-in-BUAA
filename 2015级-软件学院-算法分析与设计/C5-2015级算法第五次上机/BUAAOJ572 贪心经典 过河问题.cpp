#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 114514
using namespace std;
typedef long long ll;
ll a[maxn];
int n;
ll ans;
int main() {
    while (scanf("%d", &n) != EOF) {
        ans = 0;
        for (int i = 1; i <= n; ++i)scanf("%lld", a + i);
        sort(a + 1, a + n + 1);
        while (n > 3) {
            ans += min((a[1] << 1) + a[n] + a[n - 1], a[1] + (a[2] << 1) + a[n]);
            n -= 2;
        }
        if (n == 3)ans += a[1] + a[2] + a[3];
        if (n == 2)ans += max(a[1], a[2]);
        if (n == 1)ans += a[1];
        printf("%lld\n", ans);
    }
}
