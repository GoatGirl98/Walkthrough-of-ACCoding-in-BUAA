#include<cstdio>
#include<cmath>
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int s=1;
        scanf("%d",&n);
        int b=(int)sqrt(n);
        for(int i=2;i<=b;i++)
            if(!(n%i)){s=s+i;int t = n / i;if( t != i)s += t;}
        printf("%d\n",s);}
    return 0;
}
