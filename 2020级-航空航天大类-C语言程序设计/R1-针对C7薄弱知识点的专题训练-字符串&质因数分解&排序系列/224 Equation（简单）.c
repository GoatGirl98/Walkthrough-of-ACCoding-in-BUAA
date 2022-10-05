#include<stdio.h>
#include<string.h>

char x[50];

int main()
{
	int a,b,c;
	while(gets(x)!=NULL)
	{
		char *t1=strchr(x,'?');
		char *t2=strchr(x,'+');
		if(t1==NULL)
		{
			sscanf(x,"%d+%d=%d",&a,&b,&c);
			if(a+b==c)
			{
				printf("Right!\n");
			}
			else
			{
				printf("Error!\n");
			}
		}
		else if(t1==t2-1)
		{
			sscanf(x,"?+%d=%d",&b,&c);
			printf("%d\n",c-b);
		}
		else if(t1==t2+1)
		{
			sscanf(x,"%d+?=%d",&a,&c);
			printf("%d\n",c-a);
		}
		else
		{
			sscanf(x,"%d+%d",&a,&b);
			printf("%d\n",a+b);
		}
	}
	return 0;
}