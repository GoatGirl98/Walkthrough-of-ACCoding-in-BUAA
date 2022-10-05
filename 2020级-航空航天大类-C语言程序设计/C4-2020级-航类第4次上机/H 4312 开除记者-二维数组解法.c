#include <stdio.h>
#include <string.h>

char ans[11][1100][1100] = {0};

void puts2(char *a){
    while(*a){
        putchar(*a);
        putchar(' ');
        a++;
    }
    printf("\n");
    return;
}

int main()
{
    int i, m, n, helf;
    ans[0][0][0] = '1';

    for (i = 1; i <= 10; ++i)
    {
        helf = 1 << (i - 1);
        for (m = 0; m < helf; ++m)
        {
            for (n = 0; n < helf; ++n)
            {
                ans[i][m][n] = '0';
            }
        }
        // a[1][2][3];   // char
        // a[1][2];     // char 数组
        for (m = 0; m < helf; ++m)
        {
            strcat(ans[i][m], ans[i - 1][m]);
        }
        for (m = helf; m < (helf * 2); ++m)
        {
            strcat(ans[i][m], ans[i - 1][m - helf]);
            strcat(ans[i][m], ans[i - 1][m - helf]);
        }
    }

    while (scanf("%d", &n) > 0)
    {
        for (i = 0; i < (1 << n); ++i)
        {
            puts2(ans[n][i]);
        }
        putchar('\n');
    }
}