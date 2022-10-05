#include <stdio.h>

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isRun(int y)
{
    if (y % 4 == 0 && y % 100 != 0)
    {
        return 1;
    }
    else if (y % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dayStep(int y, int m, int d)
{
    int i;
    int all=0;
    for (i = 1970; i < y; ++i)
    {
        all += 365 + isRun(i);  // 逻辑表达式真值！
    }

    for (i = 1; i < m; ++i)
    {
        all += month[i];
    }
    if (m > 2)
    {
        all += isRun(y);
    }

    all += d;
    return all;
}

int main()
{
    int n, i;
    int y1, y2, m1, m2, d1, d2;
    int X;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d-%d-%d %d-%d-%d", &y1, &m1, &d1, &y2, &m2, &d2);
        X = dayStep(y2, m2, d2) - dayStep(y1, m1, d1);

        if (X == 0)
        {
            printf("Today");
        }
        else if (X == 1)
        {
            printf("Yesterday");
        }
        else if (y1 == y2 && m1 == m2)
        {
            printf("%d days ago", X);
        }
        else if (y1 == y2)
        {
            printf("%02d-%02d %d days ago", m1, d1, X);
        }
        else
        {
            printf("%02d-%02d-%02d %d days ago", y1, m1, d1, X);
        }

        printf("\n");
    }
}