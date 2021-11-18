#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int a[114514];
inline bool judge(int d) {
    int need = 1, cur = 1;
    while ((cur = upper_bound(a + 1, a + n + 1, a[cur] + d) - a) <= n) {
        ++need;
        if(need > m) return false;
    }
    return true;
}
int main() {
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int lo = 0, mi = 0, hi = a[n] - a[1];
    while (hi > lo) {
        mi = (hi + lo) >> 1;
        if (judge(mi)) hi = mi;
        else lo = mi + 1;
    }
    printf("%.1f", (double)lo * 0.5);
}
