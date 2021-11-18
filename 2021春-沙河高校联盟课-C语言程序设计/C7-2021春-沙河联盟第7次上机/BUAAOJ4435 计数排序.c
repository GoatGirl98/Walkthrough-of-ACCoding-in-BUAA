#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, l, r;
    scanf("%d", &n);
    int i, line[101][101] = {0};
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        line[l][r]++;
    }
    for (l = 0; l < 101; l++)
    {
        for (r = 0; r <= 100; r++)
        {
            while (line[l][r])
                printf("%d %d\n", l, r), line[l][r]--;
        }
    }
    return 0;
}