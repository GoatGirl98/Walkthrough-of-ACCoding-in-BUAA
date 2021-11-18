#include<stdio.h>
#include<math.h>
int max(int a,int b);
int min(int a,int b);
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        if(a==b)
            printf("Nova\n");
        else
        {
            int aa=max(a,b);
            int bb=min(a,b);
            if((aa*1.0)/bb>(sqrt(5)+1)/2)
                printf("Nova\n");
            else
            {
                printf("LaoWang\n");
            }
        }
    }
}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
