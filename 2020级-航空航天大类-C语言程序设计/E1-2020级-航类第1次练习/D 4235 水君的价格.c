#include<stdio.h>

int main()
{
	long long a;
	while(~scanf("%lld",&a))
	{
		if(a==0)
		{
			printf("0\n");
		}
		else if(a>0)
		{
			unsigned long long sum=2*a;
			printf("%llu00\n",sum);
		}
		else if(a==-9223372036854775808)
		{
			printf("-1844674407370955161600\n");
		}
		else if(a<0)
		{
			a=-a;
			unsigned long long sum=2*a;
			printf("-%llu00\n",sum);
		}
	}
	return 0;
}