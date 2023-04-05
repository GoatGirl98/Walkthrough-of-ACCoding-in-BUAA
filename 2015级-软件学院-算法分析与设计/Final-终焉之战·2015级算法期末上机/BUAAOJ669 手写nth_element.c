#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
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
void wr(int x) 
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 ^ '0');
}
int n, k;
int x[4010], s[4010];
int a[8100000], len;
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
    while (rd(&n))
    {
        len = 0;
        rd(&k), k = (k - 1) >> 1;
        for (int i = 1; i < n; ++i)
            rd(&x[i]), s[i] = s[i - 1] + x[i];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                a[len++] = s[j] - s[i];
        nth_element(0, k, len - 1);
        wr(a[k]), putchar('\n');
    }
}