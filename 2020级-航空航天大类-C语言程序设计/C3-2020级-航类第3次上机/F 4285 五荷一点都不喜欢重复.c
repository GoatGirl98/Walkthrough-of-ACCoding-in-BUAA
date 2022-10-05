#include <stdio.h>

int main()
{
    int m, n, level, i1, i2, i3, i4, i5;
    scanf("%d %d", &m, &n);

    for (i1 = 1; i1 <= m; ++i1)
    {
        for (i2 = 1; i2 <= m; ++i2)
        {
            if(i2==i1){
                continue;
            }
            for (i3 = 1; i3 <= m; ++i3)
            {
                if(i3==i2||i3==i1){
                    continue;
                }
                if (n >= 4)
                {
                    for (i4 = 1; i4 <= m; ++i4)
                    {
                        if(i4==i1||i4==i2||i4==i3){
                            continue;
                        }
                        if (n >= 5)
                        {
                            for (i5 = 1; i5 <= m; ++i5)
                            {
                                if(i5==i1||i5==i2||i5==i3||i5==i4){
                                    continue;
                                }
                                printf("%d%d%d%d%d\n", i1, i2, i3, i4, i5);
                            }
                        }
                        else
                        {
                            printf("%d%d%d%d\n", i1, i2, i3, i4);
                        }
                    }
                }
                else
                {
                    printf("%d%d%d\n", i1, i2, i3);
                }
            }
        }
    }
}