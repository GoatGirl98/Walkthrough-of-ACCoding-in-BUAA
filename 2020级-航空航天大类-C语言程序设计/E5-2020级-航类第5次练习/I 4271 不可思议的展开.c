#include<stdio.h>

long long A[500][500];

void init()
{
	A[0][0]=1;
	int i;
	for(i=1;i<490;i++)
	{
		if(i%2==1)//奇数从左下往右上填
		{
			A[i][0]=0;
			int j;
			for(j=1;j<=i;j++)
			{
				A[i-j][j]=(A[i-j][j-1]+A[i-j+1][j-1])%998244353;
			}
		}
		else//偶数从右上往左下填
		{
			A[0][i]=0;
			int j;
			for(j=1;j<=i;j++)
			{
				A[j][i-j]=(A[j-1][i-j]+A[j-1][i-j+1])%998244353;
			}
		}
	}
}

int main()
{
	init();
	int m,n;
	scanf("%d%d",&m,&n);
	int i;
	for(i=0;i<m;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			printf("%lld",A[i][j]);
			if(j!=n-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}