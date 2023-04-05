#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define getchar getchar_unlocked
#define maxn 1000000
char eof_flag;
char rd(int *s)
{
    if (eof_flag)
        return 0;
    int k = 0, f = 1;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
    {
        if (c == EOF)
        {
            eof_flag = 1;
            return 0;
        }
        c = getchar();
    }
    f = (c == '-') ? -1 : 1;
    k = (c == '-') ? 0 : (c ^ 48);
    c = getchar();
    while (c >= '0' && c <= '9')
        k = (k << 1) + (k << 3) + (c ^ 48), c = getchar();
    if (c == EOF)
        eof_flag = 1;
    (*s) = f > 0 ? k : -k;
    return 1;
}
int n, k;
typedef struct info
{
    int idx, value;
} info;
info a[1000010];
char smaller(info a, info b) { return a.value == b.value ? a.idx < b.idx : a.value < b.value; }
int partition(int lo, int hi)
{
    int rand_pick = lo + rand() % (hi - lo + 1);
    info tmp = a[lo];
    a[lo] = a[rand_pick], a[rand_pick] = tmp;
    info pivot = a[lo];

    while (lo < hi)
    {
        while (lo < hi)
        {
            if (smaller(pivot, a[hi]))
                hi--;
            else
            {
                a[lo++] = a[hi];
                break;
            }
        }

        while (lo < hi)
        {
            if (smaller(a[lo], pivot))
                lo++;
            else
            {
                a[hi--] = a[lo];
                break;
            }
        }
    }
    a[lo] = pivot;
    return lo;
}
void nth_element(int l, int target, int r)
{
    while (l < r)
    {
        int pivot = partition(l, r);
        if (target <= pivot)
            r = pivot - 1;
        if (target >= pivot)
            l = pivot + 1;
    }
}
int main()
{
    srand(time(0));
    while (rd(&n))
    {
        rd(&k);
        for (int i = 1; i <= n; ++i)
            a[i].idx = i, rd(&a[i].value);
        nth_element(1, n + 1 - k, n);
        printf("map%d : %d\n", a[n + 1 - k].idx, a[n + 1 - k].value);
    }
}