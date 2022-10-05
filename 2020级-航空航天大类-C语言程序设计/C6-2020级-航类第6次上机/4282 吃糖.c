#include<stdio.h>

int n, m, Ans;
int a[100005];

int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
	}
	if(a[1]+a[2] > m)
	{
		Ans += a[1]+a[2]-m;
		if(a[1]+a[2]-m > a[2])
		{
			a[2] = 0;
			a[1] = m;
		}
		else
		{
			a[2] = m-a[1];
		}
	}
	for(i=2; i<n; ++i)
	{
		if(a[i]+a[i+1] <= m)
		{
			continue;
		}
		Ans += a[i]+a[i+1]-m;
		a[i+1] = m-a[i];
	}
	printf("%d", Ans);
	return 0;
}