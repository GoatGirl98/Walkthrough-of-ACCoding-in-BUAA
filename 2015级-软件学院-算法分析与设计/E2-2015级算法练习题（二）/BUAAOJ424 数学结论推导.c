#include<stdio.h>
#include<string.h>

int a[2555];

int main()
{
	a[0]=2;
	a[1]=6;
	int i;
	for(i=2;i<=2550;i++)
	{
		a[i]=6*a[i-1]-4*a[i-2];
		a[i]+=400000;
		a[i]%=100000;
	}
	long long n;
	while(~scanf("%lld",&n))
	{
		if(n<=5)
		{
			printf("%05d\n",a[n]-1);
			continue;
		}
		n%=2500;
		if(n<=5)
		{
			printf("%05d\n",a[n+2500]-1);
			continue;
		}
		printf("%05d\n",a[n]-1);
	}
}
