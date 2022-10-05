#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[1000005];

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int i;
	for(i=0; i<m; i++)
	{
		int c;
		scanf("%d",&c);
		a[c]++;
	}
	int sum=0;
	for(i=0; i<n; i++)
	{
		int b;
		scanf("%d",&b);
		int d=b,f=b;
		while(a[f]==0&&a[d]==0)
		{
			f++;
			d--;
		}
		f=f-b;
		d=b-d;
		int min=f;
		if(d<min)
		{
			min=d;
		}
		sum+=min;
	}
	printf("%d",sum);

}