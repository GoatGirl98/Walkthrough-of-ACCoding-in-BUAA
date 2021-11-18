#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1010
typedef long long ll;
ll a[maxn];
ll maxMiss;
int n; ll m;
int res;
int main() {
    while (~scanf("%d%lld", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", a + i);
        }
        sort(a, a + n);
        res = 0;
        maxMiss = 1;
        int cnt = 0;
        while (maxMiss <= m) {

            if (maxMiss < a[cnt]) {
                ++res; maxMiss <<= 1;
            }
            else {
                if (cnt < n) {
                    maxMiss += a[cnt];
                    ++cnt;
                }
                else { ++res; maxMiss <<= 1; }
            }
        }
        printf("%d\n", res);
    }
}
