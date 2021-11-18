#include <stdio.h>
#include <stdlib.h>
int a[20][20];
int cnt;
int bar_space(int x, int y, int z) //判断空余位置
{
    if (z == 1)
    {
        if (x - 1 >= 0 && a[x - 1][y] == 0)
            return 1;
        if (x + 4 < 19 && a[x + 4][y] == 0)
            return 1;
    }

    if (z == 2)
    {
        if (y - 1 >= 0 && a[x][y - 1] == 0)
            return 1;
        if (y + 4 < 19 && a[x][y + 4] == 0)
            return 1;
    }

    if (z == 3)
    {
        if (x - 1 >= 0 && y - 1 >= 0 && a[x - 1][y - 1] == 0)
            return 1;
        if (x + 4 < 19 && y + 4 < 19 && a[x + 4][y + 4] == 0)
            return 1;
    }

    if (z == 4)
    {
        if (x - 1 >= 0 && y + 1 < 19 && a[x - 1][y + 1] == 0)
            return 1;
        if (x + 4 < 19 && y - 4 >= 0 && a[x + 4][y - 4] == 0)
            return 1;
    }

    return 0;

}
int four_strike(int x, int y, int z)//只判断单方向即可，找最小的4连 
{
    if (z == 1)
    {
        if (x + 3 < 19 && a[x][y] == a[x + 1][y] && a[x][y] == a[x + 2][y] && a[x][y] == a[x + 3][y])
            return 1;
    }
    if (z == 2)
    {
        if (y + 3 < 19 && a[x][y] == a[x][y + 1] && a[x][y] == a[x][y + 2] && a[x][y] == a[x][y + 3])
            return 1;
    }
    if (z == 3)
    {
        if (x + 3 < 19 && y + 3 < 19 && a[x][y] == a[x + 1][y + 1] && a[x][y] == a[x + 2][y + 2] && a[x][y] == a[x + 3][y + 3])
            return 1;
    }
    if (z == 4)
    {
        if (x + 3 < 19 && y - 3 >= 0 && a[x][y] == a[x + 1][y - 1] && a[x][y] == a[x + 2][y - 2] && a[x][y] == a[x + 3][y - 3])
            return 1;
    }
    return 0;
}
int judgesin(int x, int y)
{
    int z;

    z = 1;
    if (four_strike(x, y, z))
        return z;

    z = 2;
    if (four_strike(x, y, z))
        return z;
    z = 3;
    if (four_strike(x, y, z))
        return z;
    z = 4;
    if (four_strike(x, y, z))
        return z;


    return 0;
}
int guocheng()
{
    int i, j;
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 19; j++)
        {
            if (a[i][j] == 1)
            {
                int z = judgesin(i, j);
                if (z == 1 || z == 2 || z == 3 || z == 4)
                {
                    if (bar_space(i, j, z))
                    {
                        printf("1\n%d\n%d %d\n", cnt, i + 1, j + 1);
                        return 1;
                    }
                }
            }
            if (a[i][j] == 2)
            {
                int z = judgesin(i, j);
                if (z == 1 || z == 2 || z == 3 || z == 4)
                {
                    if (bar_space(i, j, z))
                    {
                        printf("2\n%d\n%d %d\n", cnt, i + 1, j + 1);
                        return 1;
                    }
                }
            }
            if (a[i][j] == 0)continue;
        }

    }
    puts("NO");
    return 0;
}
int main()
{
    while (!feof(stdin)) {
        cnt = 0;
        int i, j;
        for (i = 0; i < 19; i++)
        {
            for (j = 0; j < 19; j++)
            {
                scanf("%d", &a[i][j]);
                cnt += a[i][j] == 1;
            }
        }
        guocheng();
        putchar('\n');
    }
    return 0;
}