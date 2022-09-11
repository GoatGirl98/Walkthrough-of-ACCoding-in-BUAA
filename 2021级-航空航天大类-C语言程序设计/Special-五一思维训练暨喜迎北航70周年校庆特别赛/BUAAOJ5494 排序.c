#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
typedef struct info
{
    int no, _time;
} info;
int n;
ll ans;
info a[1010];
int cmp(const void *p1, const void *p2)
{
    info *a = (info *)p1, *b = (info *)p2;
    if (a->_time < b->_time)
        return -1;
    else if (a->_time > b->_time) return 1;
    else return 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i].no = i, scanf("%d", &a[i]._time);
    qsort(a + 1, n, sizeof(a[0]), cmp);
    for (int i = 1; i <= n; ++i)
        ans += 1ll * a[i]._time * (1ll * n - i), printf("%d ", a[i].no);
    putchar('\n');
    printf("%.2f", (double)ans / (double)n);
}