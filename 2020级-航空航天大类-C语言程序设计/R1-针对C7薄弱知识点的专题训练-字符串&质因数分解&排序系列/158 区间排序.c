#include<stdio.h>
#include<stdlib.h>

int n;

struct A
{
    int l,r;
};

struct A a[1010];

int compare(const void *p1,const void *p2)
{
	struct A *a=(struct A*)p1;
	struct A *b=(struct A*)p2;
	if(a->l>b->l)
	{
		return 1;
	}
	else if(a->l<b->l)
	{
		return -1;
	}
	else if(a->r>b->r)
	{
		return 1;
	}
	else if(a->r<b->r)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
    while(~scanf("%d",&n))
	{
		int i;
        for(i=0;i<n;++i)
		{
			scanf("%d%d",&a[i].l,&a[i].r);
		}
        qsort(a,n,sizeof(struct A),compare);
        for(i=0;i<n;++i)
		{
			printf("%d %d\n",a[i].l,a[i].r);
		}
    }
}