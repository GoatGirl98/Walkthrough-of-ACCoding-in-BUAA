#include<stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i; 
		for(i=2;i<=n;i++)
		{
			while(n!=i)
			{
				if(n%i==0)
				{
					printf("%d*",i);
					n/=i;
				}
				else
				{
					break;
				}
			}
		}
		printf("%d\n",n);
	}
}

