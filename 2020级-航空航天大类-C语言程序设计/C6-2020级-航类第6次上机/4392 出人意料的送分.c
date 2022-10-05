#include<stdio.h>
#include<stdlib.h>

int n;
int a[200005];

int cmp(const void *a, const void *b)
{
	int *c=(int*)a;
	int *d=(int*)b;
	if(*c>*d)
	{
		return 1;
	}
	else if(*c<*d)
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
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
	}
	qsort(a+1, n, sizeof(a[1]), cmp);
	for(i=1; i<=n; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}