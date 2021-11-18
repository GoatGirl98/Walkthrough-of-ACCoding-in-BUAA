#pragma G++ optimize(2)
#include<cstdio>
#include<cstring>
#define maxn 1000010
int lo, mi, hi;
int n, m;
int r[maxn], d[maxn], s[maxn], t[maxn];
int sum[maxn];
inline bool judge(int x) {//无法满足要求则返回true
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= x; ++i) {
        sum[s[i]] += d[i];
        sum[t[i] + 1] -= d[i];
    }
    if (sum[1] > r[1])return true;
    for (int i = 2; i <= n; ++i) {
        sum[i] += sum[i - 1];
        if (sum[i] > r[i])return true;
    }
    return false;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)scanf("%d", &r[i]);
    for (int i = 1; i <= m; ++i)scanf("%d%d%d", &d[i], &s[i], &t[i]);
    lo = 1, hi = m;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        //printf("lo : %d hi : %d mi : %d\n", lo, hi, mi);
        if (judge(mi))hi = mi;
        else lo = mi + 1;
    }
    if (hi < m) {
        printf("-1\n%d\n", hi);
    }
    else puts("0");
}
