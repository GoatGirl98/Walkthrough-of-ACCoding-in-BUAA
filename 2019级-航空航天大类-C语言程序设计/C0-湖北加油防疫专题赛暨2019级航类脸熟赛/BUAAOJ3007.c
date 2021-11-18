#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
int n, m, i;
typedef struct info {
	int a, b, c, sum;
}info;
int cmp(const void* p1, const void* p2) {
    info* a = (info*)p1, * b = (info*)p2;
    if (a->sum > b->sum)return -1;
    else if (a->sum < b->sum)return 1;
    else return 0;
}
info s[100010];
int main() {
    n = rd(), m = rd();
    if (m > n)m = n;
    for (i = 0; i < n; ++i)s[i].a = rd(), s[i].b = rd(), s[i].c = rd(), s[i].sum = s[i].a + s[i].b + s[i].c;
    qsort(s, n, sizeof(s[0]), cmp);
    for (i = 0; i < m; ++i)
        wr(s[i].a), putchar(' '), wr(s[i].b), putchar(' '), wr(s[i].c), putchar('\n');
}