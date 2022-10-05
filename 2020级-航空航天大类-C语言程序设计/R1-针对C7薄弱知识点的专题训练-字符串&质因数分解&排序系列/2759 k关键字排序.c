#include<stdio.h>

int main()
{
	int i, j, n, k, l;
	int a[1100][20];
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			scanf("%d", &a[i][j]);
		}
		a[i][j] = i + 1;
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			int flag = 0;
			for (l = 0; l < k; l++)
			{
				if (a[j][l] < a[j + 1][l])
				{
					break;
				}
				if (a[j][l] > a[j + 1][l])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				int temp;
				for (l = 0; l <= k; l++)
				{
					temp = a[j][l];
					a[j][l] = a[j + 1][l];
					a[j + 1][l] = temp;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i][k]);
	}
	return 0;
}