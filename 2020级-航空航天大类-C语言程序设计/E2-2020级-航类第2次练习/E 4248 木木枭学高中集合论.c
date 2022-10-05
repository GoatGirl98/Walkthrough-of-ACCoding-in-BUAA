#include<stdio.h>

int main()
{
	int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<(1<<n);i++)//所有可能元素选取
    {
        int j;
        for(j=0;j<n;j++)//每一位
        {
            if((i>>j)&1)//如果该位有元素
            {
				printf("%d",j);
            }
            else
            {
            	printf("-");
			}
        }
		printf("\n");
    }
}