#include<cstdio>
#include<cmath>
#include<unordered_set>
typedef long long ll;
using namespace std;
unordered_set<ll> res;
ll n;
int main() {
    while (scanf("%lld", &n) != EOF) {
        res.clear();
        ll k = 2;
        while (k <= (int)(sqrt(n)+1)) {
            if (!(n % k)) {
                n /= k;
                res.insert(k);
                continue;
            }
            k++;
        }
        res.insert(n);
        ll ans = 1;
        for (ll a : res) {
            ans *= a;
        }
        printf("%lld\n", ans);
    }
}
