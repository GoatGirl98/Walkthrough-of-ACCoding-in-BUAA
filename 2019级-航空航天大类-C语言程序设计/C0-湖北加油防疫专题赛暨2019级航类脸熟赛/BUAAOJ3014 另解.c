#include<stdio.h>

int num[200002];

int main()
{
	int ans, n, i, a, b, c, temp;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		num[temp] = i;
	}
	ans = 0;
	a = n;
	b = n - 1;
	while (num[b] < num[a] && b)
	{
		a--;
		b--;
	}
	if (b == 0);
	else
	{
		c = b - 1;
		ans++;
		while (c)
		{
			if (num[a] < num[b])
			{
				if (num[c]<num[a] || num[c]>num[b])
				{
					ans++;
					a = b;
					b = c;
					c--;
				}
				else
				{
					b = c;
					c--;
				}
			}
			else
			{
				if (num[c]<num[b] || num[c]>num[a])
				{
					b = c;
					c--;
				}
				else
				{
					ans++;
					a = b;
					b = c;
					c--;
				}
			}
		}
	}
	printf("%d", ans);
}