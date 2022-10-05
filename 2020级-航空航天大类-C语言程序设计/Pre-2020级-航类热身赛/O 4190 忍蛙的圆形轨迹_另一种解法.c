#include<stdio.h>
#include<stdlib.h>
#include<float.h>

int comp(const void *p1,const void *p2)
{
	double *a=(double*)p1;
	double *b=(double*)p2;
	if(*a<*b)
	{
		return 1;
	}
	else if(*a>*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

struct poi
{
	double first;
	double second;
};

struct poi points[10010];
int topp;

double m[10010];
int topm;

int maxPoints()
{
	int res=1;
	int i;
	for(i=0; i<topp; ++i)
	{
		topm=0;
		int j;
		for(j=i+1; j<topp; ++j)
		{
			if(points[j].first*points[i].second==points[i].first*points[j].second)
			{
				continue;
			}
			double dx=points[j].first-points[i].first;
			double dy=points[j].second-points[i].second;
			if(dy!=0)
			{
				m[topm]=dx/dy;
			}
			else
			{
				m[topm]=DBL_MAX;
			}
			topm++;
		}
		qsort(m,topm,sizeof(double),comp);
		int l,r;
		for(l=0; l<topm;)
		{
			r=l;
			while(m[l]-m[r]<1e-14&&m[r]-m[l]<1e-14&&r<topm)
			{
				r++;
			}
			res=res>(r-l+1)?res:(r-l+1);
			l=r;
		}
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	double x,y;
	while(n--)
	{
		scanf("%lf%lf",&x,&y);
		double temp=x*x+y*y;
		struct poi pp;
		pp.first=x/temp;
		pp.second=y/temp;
		points[topp]=pp;
		topp++;
	}
	printf("%d\n",maxPoints());
	return 0;
}

