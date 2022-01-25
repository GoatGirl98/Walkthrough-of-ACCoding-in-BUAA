#include <stdio.h>
int n, remain, week, x;
int main()
{
    scanf("%d", &n);
    remain = 48, week = 15 - n;
    while (n--)
        scanf("%d", &x), remain -= x;
    if (week * 10 < remain)
        puts("gg");
    else
        printf("%d", (remain + week - 1) / week);
}