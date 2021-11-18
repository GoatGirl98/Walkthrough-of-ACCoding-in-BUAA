#include<cstdio>
#define maxn 1010
int n;
int l, r;
int a[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)scanf("%d", a + i);
    a[0] = 1, a[n] = -1;
    for (int i = 1; i <= n; ++i) {
        l = i - 1, r = i;
        while (a[l] == 0 && l >= 0)--l;
        while (a[r] == 0 && r <= n)++r;
        if (a[l] > 0 && a[r] < 0)printf("%d ", i);
    }
}
