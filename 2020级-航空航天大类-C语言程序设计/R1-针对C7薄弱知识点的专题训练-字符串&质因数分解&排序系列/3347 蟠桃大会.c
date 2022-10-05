#include<stdio.h>
#include<stdlib.h>

struct pz
{
	unsigned long long a,b;
};

int comp(const void *p,const void *q)
{
	if(((struct pz*)q)->a>((struct pz*)p)->a)
	{
		return 1;
	}
	else if(((struct pz*)q)->a<((struct pz*)p)->a)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

struct pz panzi[100005];

int main()
{
	unsigned long long m,n;
	scanf("%llu%llu",&m,&n);
	unsigned long long i=0;
	while(scanf("%llu%llu",&panzi[i].a,&panzi[i].b)!=EOF)
	{
		i++;
	}
	qsort(panzi,i,sizeof(struct pz),comp);
	unsigned long long point=0,sum=0;
	unsigned long long j;
	for(j=0; point<m*n&&j<i; j++)
	{
		if(panzi[j].b>=m)
		{
			sum+=m*panzi[j].a;
			point+=m;
		}
		else
		{
			sum+=panzi[j].b*panzi[j].a;
			point+=panzi[j].b;
		}
	}
	if(point>m*n)
	{
		sum=(sum-(point-m*n)*panzi[j-1].a)%100007;
	}
	else
	{
		sum%=100007;
	}
	printf("%llu",sum);
}