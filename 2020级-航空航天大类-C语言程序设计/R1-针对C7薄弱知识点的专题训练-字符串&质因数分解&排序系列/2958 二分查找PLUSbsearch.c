#include<stdio.h>
#include<stdlib.h>

int compare(const void *p1,const void *p2)
{
	int *a=(int*)p1;
	int *b=(int*)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int a[100010];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		int *result=bsearch(&x,a,n,sizeof(int),compare);
		if(result==NULL)
        {
        	printf("No\n");
		}
		else
		{
			int l=result-a;
			while(a[l-1]==a[l])
			{
				l--;
			}
			int u=result-a;
			while(a[u+1]==a[u])
			{
				u++;
			}
            printf("Yes %d %d\n",l+1,u-l+1);
		}
	}
}
