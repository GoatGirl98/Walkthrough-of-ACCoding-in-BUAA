#include<cstdio>
#include<cstring>
#define maxn 1000010
char a[maxn];
int main()
{

    int i, l = 0, flag;
    while (scanf("%s", a)!=EOF)
    {
        flag = 1;
        l = (int)strlen(a);
        if(l % 2 != 0)
        {
            printf("NO\n");
            return 0;
        }

        for(i = 0; i < l / 2; i++)
        {
            if (a[i] != a[i + l / 2])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
