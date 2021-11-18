#include<stdio.h>
#include<string.h>
#include<ctype.h>

int k[130];
int len;
char s[1005];

int cal(int u)
{
	int ret=1,x=1,v=0;
	for(; u!=len; u++)
	{
		if(islower(s[u]))
		{
			if(x==1)
			{
				ret=(ret&(k[s[u]]^v));
			}
			else if(x==0)
			{
				ret=(ret|(k[s[u]]^v));
			}
			v=0;
		}
		else
		{
			int num;
			switch(s[u])
			{
				case'&':
					x=1;
					break;
				case'|':
					x=0;
					break;
				case'~':
					v^=1;
					break;
				case')':
					return ret;
				case'(':
					if(x==1)
					{
						ret=(ret&(cal(u+1)^v));
					}
					else if(x==0)
					{
						ret=(ret|(cal(u+1)^v));
					}
					v=0;
					num=1;
					while(num!=0)
					{
						u++;
						if(s[u]=='(')
						{
							num++;
						}
						else if(s[u]==')')
						{
							num--;
						}
					}
			}
		}
	}
	return ret;
}

char q[15];
int output[15];

int main()
{
	gets(s);
	len=strlen(s);
	int n=-1;
	int i;
	for(i=0; i<len; i++)
	{
		if(islower(s[i])&&k[s[i]]==0)
		{
			k[s[i]]=1;
			q[++n]=s[i];
		}
	}
	scanf("%s",s);
	len=strlen(s);
	for(i=0; i<=n; i++)
	{
		printf("| %c ",q[i]);
	}
	printf("| R |\n");
	int f;
	for(f=(1<<(n+1))-1; f>=0; f--)
	{
		for(i=0; i<=n; i++)
		{
			if((f>>(n-i))&1)
			{
				k[q[i]]=0;
				output[i]=0;
			}
			else
			{
				k[q[i]]=1;
				output[i]=1;
			}
		}
		output[n+1]=cal(0);
		for(i=0; i<=n+1; i++)
		{
			if(output[i]==0)
			{
				printf("| F ");
			}
			else
			{
				printf("| T ");
			}
		}
		printf("|\n");
	}
}