#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long ll;
const ll mod = 100007;
ll m, n;
ll ans;
typedef struct info {
    ll num, cnt;
}info;
int cmp(const void* p1, const void* p2) {
    info* x = (info*)p1, * y = (info*)p2;
    if (x->num > y->num) return -1;
    else if (x->num < y->num)return 1;
    else return 0;
}
info a[114514];
int sz, i;
ll remain_cnt;
int main() {
    scanf("%lld%lld", &m, &n);
    while (scanf("%lld%lld", &a[sz].num, &a[sz].cnt) != EOF) ++sz;
    qsort(a, sz, sizeof(a[0]), cmp);
    remain_cnt = m * n;
    for (i = 0; i < sz && remain_cnt; ++i) {
        if (remain_cnt < a[i].cnt && remain_cnt < m) ans += a[i].num * remain_cnt, ans %= mod, remain_cnt = 0;
        else if (a[i].cnt > m) ans += a[i].num * m, ans %= mod, remain_cnt -= m;
        else ans += a[i].num * a[i].cnt, ans %= mod, remain_cnt -= a[i].cnt;
    }
    printf("%lld\n", ans);
}