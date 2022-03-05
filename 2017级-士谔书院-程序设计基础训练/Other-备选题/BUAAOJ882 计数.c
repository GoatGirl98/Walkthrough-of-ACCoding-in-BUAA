#include <stdio.h>
#include <stdlib.h>
int a[1010];
int b[1010];
int result[2000010];
int n, m, ans;

void uniqfy(int *array, int *size)
{
    int i = 0, j = 0;
    while (++j < *size)
        if (array[i] != array[j]) // skip duplicate
            array[++i] = array[j];
    *size = ++i;
}

int compare(const void *p1, const void *p2)
{
    int *a = (int *)p1, *b = (int *)p2;
    if (*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ++result[a[i] + b[j]];
    for (int i = 0; i <= 2000000; ++i)
        if (result[i])
            ++ans;
    printf("%d", ans);

    return 0;
}