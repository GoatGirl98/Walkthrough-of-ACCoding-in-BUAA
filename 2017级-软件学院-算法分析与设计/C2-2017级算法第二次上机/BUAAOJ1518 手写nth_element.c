#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxn 3000000
int A, B, C, k;
int a[maxn + 10];
void init()
{
    for(int i = 2; i <= maxn; ++i)
        a[i] = ((1ll * a[i - 1] * A ^ B) + C) % 1000000007;
}
int partition(int lo, int hi)
{
    int rand_pick = lo + rand() % (hi - lo + 1);
    int tmp = a[lo];
    a[lo] = a[rand_pick], a[rand_pick] = tmp;
    int pivot = a[lo];

    while (lo < hi)
    {
        while (lo < hi)
        {
            if (pivot < a[hi])
                hi--;
            else
            {
                a[lo++] = a[hi];
                break;
            }
        }

        while (lo < hi)
        {
            if (a[lo] < pivot)
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
    while (scanf("%d%d%d%d%d", &A, &B, &C, &a[1], &k) != EOF)
        init(), nth_element(1, k, maxn), printf("%d\n", a[k]);
}