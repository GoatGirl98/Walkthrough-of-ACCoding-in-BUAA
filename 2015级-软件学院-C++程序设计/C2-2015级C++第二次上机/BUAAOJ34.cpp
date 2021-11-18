#include <cstdio>
#include<algorithm>
using namespace std;
int judgeTrangle(int a,int b,int c)
{
    if(a+b>c && a+c>b && b+c>a)
    {
       
            if(a*a+b*b==c*c)
                return 2;
    else if(a==b || b==c || a==c)
        {
        
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
    int a[3],t;
    while(scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF){
    sort(a,a+3);
    t=judgeTrangle(a[0],a[1],a[2]);
    switch(t)
    {
        case 0:printf("just a triangle\n");break;
        case 1:printf("perfect\n");break;
        case 2:printf("good\n");break;
        default:printf("wrong\n");break;
    }}
}
