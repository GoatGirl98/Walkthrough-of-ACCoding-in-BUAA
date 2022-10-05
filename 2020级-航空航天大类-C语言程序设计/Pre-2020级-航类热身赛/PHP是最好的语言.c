#include <stdio.h>
#include <string.h>

char str[30][30];
char tmp[30] = {0};
int main()
{
    int count = 0;
    int num[30] = {0};
    int i;
    int exist;
    int maxIndex = 0, maxNum = -1;
    while (gets(tmp) != NULL)
    {
        exist = 0;
        for (i = 0; i < count; ++i)
        {
            if (strcmp(tmp, str[i]) == 0)
            {
                num[i]++;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            strcpy(str[count], tmp);
            num[count]++;
            count++;
        }
    }

    for (i = 0; i < count; ++i)
    {
        if (num[i] > maxNum)
        {
            maxNum = num[i];
            maxIndex = i;
        }
    }

    printf("%s",str[maxIndex]);
}