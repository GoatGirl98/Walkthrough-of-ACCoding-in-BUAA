#include<stdio.h>
#include<string.h>

char isPrime[5000010];
int countPrime[5000010];

void initial()
{
	memset(isPrime, 1, sizeof(isPrime));
	int i;
	for (i = 1; i < 5000010; ++i)
	{
		if (isPrime[i])
		{
			int k = (i << 1) + 1;
			int j;
			for (j = i + k; j < 5000010; j += k)
			{
				isPrime[j] = 0;
			}
		}
	}
	countPrime[1] = 2;
	for (i = 2; i < 5000010; ++i)
	{
		countPrime[i] = countPrime[i - 1] + isPrime[i];
	}
}

int main()
{
	int n;
	initial();
	while (scanf("%d", &n) != EOF)
	{
		if (n == 1)
		{
			printf("0\n");
		}
		else if (n == 2)
		{
			printf("1\n");
		}
		else
		{
			printf("%d\n", countPrime[(n - 1) >> 1]);
		}
	}
}