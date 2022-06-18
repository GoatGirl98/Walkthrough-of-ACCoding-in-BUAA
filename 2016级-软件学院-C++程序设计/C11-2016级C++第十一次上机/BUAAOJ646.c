#include <stdio.h>
typedef unsigned long long ull;
ull a[20001];
int main()
{
    int n, i, j, ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%llu", &a[i]);
    ull maybe;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {

            maybe = a[i] + a[j];
            if ((maybe & (maybe - 1)) == 0)
                ans++;
        }
    }
    printf("%d", ans);
}