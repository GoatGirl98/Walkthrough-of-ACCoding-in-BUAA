#include<stdio.h>
#include<stdlib.h>
struct section {
    int l, r;
};
struct section a[1010];
int n, i;
int cmp(const void* p1, const void* p2) {
    struct section* a = (struct section*)p1, * b = (struct section*)p2;
    if (a->l < b->l)return -1;
    else if (a->l == b->l && a->r < b->r) return -1;
    else if (a->l == b->l && a->r > b->r) return 1;
    else if (a->l > b->l)return 1;
    else return 0;
}
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
    qsort(a, n, sizeof(a[0]), cmp);
    for (i = 0; i < n; ++i) printf("%d %d\n", a[i].l, a[i].r);
}