#include<stdio.h>
#include<stdlib.h>
int n, L, t, i;
int c[55], w[55];
int cmp(const void* p1, const void* p2) {
    int* a = (int*)p1, * b = (int*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
int main() {
	scanf("%d%d%d", &n, &L, &t);
    for (i = 0; i < n; ++i) { 
        scanf("%d%d", &c[i], &w[i]); 
        if (w[i] == 1) c[i] += t;
        else c[i] -= t;
        while (c[i] < 0) c[i] += L; c[i] %= L;
    }
    qsort(c, n, sizeof(c[0]), cmp);
    for (i = 0; i < n; ++i) printf("%d ", c[i]);
}