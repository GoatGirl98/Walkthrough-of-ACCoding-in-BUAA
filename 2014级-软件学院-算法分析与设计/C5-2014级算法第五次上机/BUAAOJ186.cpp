#include <cstdio>

int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int m,d,ans;
    while(~scanf("%d%d",&m,&d))
    {
        ans=0;
        if(m==12&&d==12){
            printf("Oh my god! It's today!!\n");
        }
        else if(m==12&&d>12)
        {
            printf("Lucky , it has passed!\n");
        }
        else {
            if(m==12)
                ans=12-d;
            else if(m<12){
                for(int i=m+1;i<=11;i++)
                    ans+=a[i];
                ans+=a[m]-d+12;
            }
            printf("It will come in %d day(s) ORZ\n",ans);
        }
    }
}
