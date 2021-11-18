#include<cstdio>
#include<algorithm>
#define maxn 200010
using namespace std;
typedef long long ll;
struct node {
    ll pos;
    ll cost;
}list[maxn];
bool cmp(node a, node b) {
    return a.pos < b.pos;
}
int n;
ll res;
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &list[i].pos, &list[i].cost);
        }
        sort(list + 1, list + n + 1, cmp);
        ll minCost = list[1].cost;
        res = 0;
        for (int i = 2; i <= n; ++i) {
            if (list[i - 1].cost < minCost) minCost = list[i - 1].cost;
            res += (list[i].pos - list[i - 1].pos) * minCost;
        }
        printf("%lld\n", res);
    }

}
