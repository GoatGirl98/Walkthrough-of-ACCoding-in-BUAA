#include <stdio.h>
int main()
{
    int n, a, b;

    n = 1;

    while(n--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", (a+b));
    }

    /* // 或用如下for循环代替while循环
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", (a+b));
    }
    */

    return 0;
}