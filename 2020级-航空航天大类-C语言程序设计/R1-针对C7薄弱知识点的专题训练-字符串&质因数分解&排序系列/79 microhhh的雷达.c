#include<stdio.h>

int main()
{
	char ch;
	while(~scanf("%c",&ch))
	{
		getchar();
		if(ch=='A')
		{
			int base=0;
			int sum=0;
			while((ch=getchar())!='\n')
			{
				sum=sum*2+(ch-'0');
				base++;
				if(base==8)
				{
					base=0;
					printf("%c",sum);
					sum=0;
				}
			}
		}
		else if (ch=='B')
		{
			long long wait1=0,wait2=0;
			long long tem=0;
			long long x,y;
			char old='1';
			int firstPersonCord=0; 
			int secondPersonCord=0;
			int flag=1;
			int getnum=0;
			while((ch=getchar())!='\n')
			{
				wait2=(wait1*1000+ch)%1000000000000000000;
				wait1=wait2%1000000000000000;
				if(wait1==106104108106120)
				{
					firstPersonCord=1;
					secondPersonCord=0;
					x=-1;
					y=-1;
				}
				if(wait2==120105104097110103)
				{
					firstPersonCord=0;
					secondPersonCord=1;
					x=-1;
					y=-1;
				}
				if(getnum&&(firstPersonCord||secondPersonCord))
				{
					if(ch=='#')
					{
						if(x==-1)
						{
							x=tem;
						}
						else
						{
							y=tem;
						}
						getnum=0;
					}
					if('0'<=ch&&ch<='9')
					{
						tem=tem*16+ch-'0';
					}
					else if('a'<=ch&&ch<='f')
					{
						tem=tem*16+ch-'a'+10;
					}
					else
					{
						tem=0;
						getnum=0;
					}
				}
				if((x!=-1)&&(y!=-1)&&(firstPersonCord||secondPersonCord))
				{
					if(firstPersonCord)
					{
						printf("jhljx(%lld,%lld)",x,y);
					}
					else
					{
						printf("xihang(%lld,%lld)",x,y);
					}
					if(flag)
					{
						printf(" ");
					}
					flag=0;
					x=-1; 
					y=-1;
				}
				if(old=='0'&&ch=='x')
				{
					getnum=1;
				}
				old=ch;
			}
			if(flag)
			{
				printf("nothing found!");
			}
		}
		printf("\n");
	}
}

