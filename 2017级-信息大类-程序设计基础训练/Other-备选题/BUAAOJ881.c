#include <stdio.h>
int ans[1000];
int n, x;
int main()
{
    for (int i = 0; i <= 255; i++)
        ans[((i << 1) & 255) ^ i] = i;
 
    while (scanf("%d", &n) != EOF)
        for (int i = 0; i < n; i++, putchar(i == n ? '\n' : ' '))
            scanf("%d", &x), printf("%d", ans[x]);
    return 0;
}
