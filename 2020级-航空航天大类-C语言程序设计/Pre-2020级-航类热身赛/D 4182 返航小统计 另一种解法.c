#include <stdio.h>

int main()
{
    int date, n, xh, d, hh, mm, i, count=0;
    scanf("%d", &date);
    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        scanf("%d %d %d:%d", &xh, &d, &hh, &mm);
        if (d == date)
        {
            count++;
            printf("%d %02d:%02d\n", xh, hh, mm);
        }
    }
    printf("%d",count);
}