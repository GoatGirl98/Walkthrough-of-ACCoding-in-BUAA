#include<stdio.h>
#include<string.h>
#include<ctype.h>

char str[114514];

int issub(int l,int r)
{
	int i,in=0;
	if(str[l]!='('||str[r]!=')')
	{
		return 0;
	}
	for(i=l; i<r; i++)
	{
		in+=str[i]=='(';
		in-=str[i]==')';
		if(in==0)
		{
			return 0;
		}
	}
	return 1;
}

int isfun(int l,int r)
{
	int ret=0,in=0;
	if(islower(str[l])&&str[l+1]=='('&&str[r]==')')
	{
		ret=1;
	}
	int i;
	for(i=l+1; i<r; i++)
	{
		in+=str[i]=='(';
		in-=str[i]==')';
		if(in==0)
		{
			return 0;
		}
	}
	return ret;
}

int getlst(int L,int R)
{
	int i,ret=-1;
	int in=0;
	for (i=R; i>=L; i--)
	{
		in+=str[i]=='(';
		in-=str[i]==')';
		if(in!=0)
		{
			continue;
		}
		if(str[i]=='+'||str[i]=='-')
		{
			return i;
		}
		if((str[i]=='*'||str[i]=='/')&&ret==-1)
		{
			ret=i;
		}
	}
	if(ret!=-1)
	{
		return ret;
	}
	for (i=R; i>=L; i--)
	{
		in+=str[i]=='(';
		in-=str[i]==')';
		if(in!=0)
		{
			continue;
		}
		if(str[i]=='.')
		{
			return i;
		}
	}
	return ret;
}

int q[100005];
int t;
int cnt;

int c(int L,int R)
{
	int x,y;
	if(L>R)
	{
		return 0;
	}
	if(L==R&&islower(str[L]))
	{
		return -str[L];
	}
	if(issub(L,R))
	{
		return c(L+1,R-1);
	}
	if(isfun(L,R))
	{
		int num=0,las=L+2,in=0;
		int i;
		for(i=las; i<=R-1; i++)
		{
			if(str[i]=='(')
			{
				in++;
			}
			if(str[i]==')')
			{
				in--;
			}
			if(in!=0)
			{
				continue;
			}
			if(str[i]==',')
			{
				q[++t]=c(las,i-1);
				las=i+1;
				num++;
			}
		}
		q[++t]=c(las,R-1);
		num++;
		printf("%c ",str[L]);
		for(i=t-num+1; i<=t; i++)
		{
			if(q[i]<0)
			{
				printf("%c ",-q[i]);
			}
			else
			{
				printf("%d ",q[i]);
			}
		}
		printf("\n");
		while(num--)
		{
			q[t]=0;
			t--;
		}
		return ++cnt;
	}
	int mid=getlst(L,R);
	if(str[mid]=='.')
	{
		q[++t]=c(L,mid-1);
		int num=1,las=mid+3,in=0;
		int i;
		for(i=las; i<=R-1; i++)
		{
			if(str[i]=='(')
			{
				in++;
			}
			if(str[i]==')')
			{
				in--;
			}
			if(in!=0)
			{
				continue;
			}
			if(str[i]==',')
			{
				q[++t]=c(las,i-1);
				las=i+1;
				num++;
			}
		}
		q[++t]=c(las,R-1);
		num++;
		printf("%c ",str[mid+1]);
		for(i=t-num+1; i<=t; i++)
		{
			if(q[i]<0)
			{
				printf("%c ",-q[i]);
			}
			else
			{
				printf("%d ",q[i]);
			}
		}
		printf("\n");
		while(num--)
		{
			q[t]=0;
			t--;
		}
		return ++cnt;
	}
	q[++t]=c(L,mid-1);
	q[++t]=(y=c(mid+1,R));
	printf("%c ",str[mid]);
	if(q[t-1]<0)
	{
		printf("%c ",-q[t-1]);
	}
	else
	{
		printf("%d ",q[t-1]);
	}
	if(q[t]<0)
	{
		printf("%c ",-q[t]);
	}
	else
	{
		printf("%d ",q[t]);
	}
	q[t]=0;
	t--;
	q[t]=0;
	t--;
	printf("\n");
	return ++cnt;
}

int main()
{
	scanf("%s",str+1);
	int len;
	len=strlen(str+1);
	c(1,len);
}