#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNumOfPlayer 50
#define maxLengthOfName 50

typedef struct
{
    char name[maxLengthOfName];
    int score;
} player;

player play[maxNumOfPlayer];

int cmp(const void*p1, const void*p2) {
    player* pp1 = (player*)p1;
    player* pp2 = (player*)p2;
    if (pp1->score != pp2->score)
        return pp2->score - pp1->score;
    else
        return strcmp(pp1->name, pp2->name);
}

int main()
{
    int n, i, j, point, flag, numOfPlayer = 0, mark;
    char c, name[maxLengthOfName];
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        // 读取行末换行符
        while (getchar() != '\n');
        c = getchar();
        j = 0;
        mark = 0;
        // 当字符c不是数字的时候继续读取
        while (!(c >= '0' && c <= '9'))
        {
            name[j++] = c;
            c = getchar();
        }
        name[j-1] = '\0';
        point = c-'0';
        scanf("%d", &flag);
        // 若没有进球，则continue
        if (!flag)
            continue;
        
        for (j = 0; j < numOfPlayer; j++)
        {
            if (!strcmp(play[j].name, name))
            {
                mark = 1;
                play[j].score += point;
                break;
            }
        }
        // 得分球员为新球员
        if (!mark)
        {
            numOfPlayer++;
            strcpy(play[j].name, name);
            play[j].score += point;
        }
    }
    
    qsort(play, numOfPlayer, sizeof(play[0]), cmp);
    for (i = 0; i < numOfPlayer; i++)
    {
        printf("%s %d\n", play[i].name, play[i].score);
    }
    
    return 0;
}
