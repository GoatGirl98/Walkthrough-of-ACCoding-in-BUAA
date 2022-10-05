#include<stdio.h>
#include<string.h>
int main()
{
	#ifdef DEBUG
	freopen("in1.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	#endif
	char lan[25][25]={'\0'};
	char temp[25]={'\0'};
	int count[25]={0},i=0,j,max=0;
	while(scanf("%s",temp)!=EOF)
	{
		if(i==0)
		{
			strcpy(lan[0],temp);
			count[0]++; 
			i++;
		}
		else
		{
			int flag=0;
			for(j=0;j<i;j++)
			{
				if(strcmp(lan[j],temp)==0)
				{
					count[j]++;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				strcpy(lan[i],temp);
				count[i]=1;
				i++;
			}
		}
	}
	for(j=0;j<i;j++)
	{
		if(count[j]>max) max=count[j];
	}
	for(j=0;j<i;j++)
	{
		if(count[j]==max) printf("%s\n",lan[j]);
	}
	return 0;
}
