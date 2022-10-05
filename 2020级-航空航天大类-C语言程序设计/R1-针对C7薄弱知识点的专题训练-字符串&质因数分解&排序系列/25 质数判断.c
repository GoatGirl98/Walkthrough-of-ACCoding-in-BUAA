#include<stdio.h>
#include<math.h>

int main()
{
    int i,j,n,a,b,flag;
	scanf("%d",&n);
    for(i=0;i<n;i++)
	{
        scanf("%d",&a);
        if(!(a%2)&&a-2)
		{
			printf("No\n");
		} 
        else
		{
            flag=1;
            b=sqrt(a);
            for(j=2;j<=b;j++)
			{
                if(a%j==0)
				{
                    flag=0;
                    break;
                }
            }
            if(a!=1&&flag||a==2)
			{
				printf("Yes\n");
			} 
            else
			{
				printf("No\n");
			} 
        }
    }
}

