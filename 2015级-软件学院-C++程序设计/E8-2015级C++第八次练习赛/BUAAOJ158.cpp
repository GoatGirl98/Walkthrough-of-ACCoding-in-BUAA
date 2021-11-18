#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct A {
    int l, r;
    bool operator < (const A& o) const {
        if (l != o.l)return l < o.l;
        else return r < o.r;
    }
}a[1010];
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)scanf("%d%d", &a[i].l, &a[i].r);
        sort(a, a + n);
        for (int i = 0; i < n; ++i)printf("%d %d\n", a[i].l, a[i].r);
    }
}
