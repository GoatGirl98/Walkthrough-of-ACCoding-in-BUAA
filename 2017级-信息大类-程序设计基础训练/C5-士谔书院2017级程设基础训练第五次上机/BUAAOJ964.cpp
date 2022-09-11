#include <cstdio>
int judgeTrangle(int a,int b,int c)
{
    if(a+b>c && a+c>b && b+c>a)
    {
        if(a==b || b==c || a==c)
        {
            if(a==b && b==c && a==c)
                return 2;
            else
                return 1;
        }
        else
            return 0;
    }
    else
        return -1;
}

int main()
{
    int a,b,c,t;
    scanf("%d%d%d",&a,&b,&c);
    t=judgeTrangle(a,b,c);
    switch(t)
    {
        case 0:printf("regular triangle!\n");break;
        case 1:printf("isosceles triangle!\n");break;
        case 2:printf("equilateral triangle!\n");break;
        default:printf("not a triangle!\n");break;
    }
}
