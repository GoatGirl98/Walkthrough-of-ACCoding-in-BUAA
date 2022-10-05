#include<stdio.h>
#include<string.h> 

int a[300],n,r;
char b[10101];

int main()
{
    int i;
    while(gets(b))
    {
        memset(a,0,sizeof a);
        r=0;
        n=strlen(b);
        for(i=0;i<n;i++)
        {
            if(b[i]>='A'&&b[i]<='Z')
            {
                a[b[i]-'A']=1;
            }
            else if(b[i]>='a'&&b[i]<='z')
            {
                a[b[i]-'a']=1;
            }
        }
        for(i=0;i<26;i++)
        {
            r+=a[i];
        }
        if(r==26)
        {
            printf("OK!\n");
            continue;
        }
        for(i=0;i<26;i++)
        {
            if(a[i]==0)
            {
                printf("%c ",i+'A');
            }    
        }
        printf("\n");
    }
}
