#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct PERSON
{
    char name[100];
    int score;
} * ps[200], a;
int top = 0;

int cmp(const void *p, const void *q)
{
    struct PERSON *a, *b;
    a = *(struct PERSON **)p;
    b = *(struct PERSON **)q;
    if (a->score != b->score)
    {
        return b->score - a->score;
    }
    else
    {
        return strcmp(a->name, b->name);
    }
}

int main()
{
    char n1[100], n2[100], name[100];
    char s[200];
    int n, i, j, exist, point, flag;

    scanf("%d", &n);
    gets(s);

    for (i = 0; i < n; ++i)
    {
        gets(s);
        flag = -1;
        point = -1;
        for (j = strlen(s) - 1; j >= 0; --j)
        {
            if (isdigit(s[j]))
            {
                if (flag < 0)
                {
                    flag = s[j] - '0';
                }
                else
                {
                    point = s[j] - '0';
                    j--;
                    break;
                }
            }
            else if (isalpha(s[j]))
            {
                break;
            }
        }
        strcpy(name, s);
        name[j]='\0';
        exist = 0;
        for (j = 0; j < top; ++j)
        {
            if (strcmp(name, ps[j]->name) == 0)
            {
                exist = 1;
                ps[j]->score += point * flag;
                break;
            }
        }
        if (!exist)
        {
            ps[top] = malloc(sizeof a);

            strcpy(ps[top]->name, name);
            ps[top]->score = point * flag;
            top++;
        }
    }

    qsort(ps, top, sizeof ps[0], cmp);

    for (i = 0; i < top; ++i)
    {
        if (ps[i]->score <= 0)
        {
            break;
        }
        printf("%s %d\n", ps[i]->name, ps[i]->score);
    }
}