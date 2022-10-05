#include<stdio.h>

int bag[2][10]= {0};

int main()
{
	int n,m;
	int a,b;
	int p,q;
	int c=0,i;
	scanf("%d %d",&n,&m);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		bag[a][b]++;
	}
	while(m--)
	{
		scanf("%d %d",&p,&q);
		c=0;
		for(i=1; i<=q; ++i)
		{
			c/=3;
			c+=bag[p][i];
		}
		if(c)
		{
			printf("%%\n");
		}
		else
		{
			printf("\"\'\n");
		}
	}
}