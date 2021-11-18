#include<cstdio>
#include<cmath>
typedef long long ll;
ll a,b;
int main() {
    while (scanf("%lld%lld", &a,&b) != EOF) {
        ll afloor = (ll)(log(a) / log(2));
        ll bfloor = (ll)(log(b) / log(2));
        while (afloor > bfloor) {
            a >>= 1; afloor--;
        }
        while (bfloor > afloor) {
            b >>= 1; bfloor--;
        }
        while (a != b) {
            a >>= 1, b >>= 1;
        }
        printf("%lld\n", a);
    }
}
