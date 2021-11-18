#include<cstdio>
#include<cctype>
#include<cstring>
#define MAXN 55
int a[MAXN];
int f[MAXN];
int n,m;
/***********************************************
动态规划思路:
设f[k]为前k个可取到的最值
则f[k]=max(f[k-1],f[k-2]+a[k])
***********************************************/
inline int max(int a, int b) {
    if (a > b)return a;
    else return b;
}
inline void init() {
    f[1] = a[1];
    f[2] = max(a[1], a[2]);
    for (int i = 3; i <= n; ++i) {
        f[i] = max(f[i - 1], f[i - 2] + a[i]);
    }
}
inline void erase() {
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        init();
        scanf("%d", &m);
        printf("%s\n", (f[n] < m) ? "Poor AZY!" : "AZY is back, baby!");
        erase();
    }
}
