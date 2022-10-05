#include<stdio.h>

int Parenthesis()
{
	char c=getchar();
	if(c==')'||c==']'||c=='}'||c==EOF)
	{
		ungetc(c,stdin);//与getchar相反，向读入中退回一个字符
		return 1;
	}
	else if(c=='(')
	{
		int temp=Parenthesis();
		if(temp==0)//调用匹配失败
		{
			return 0;
		}
		c=getchar();
		if(c!=')')
		{
			return 0;
		}
		temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		return 1;
	}
	else if(c=='[')
	{
		int temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		c=getchar();
		if(c!=']')
		{
			return 0;
		}
		temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		return 1;
	}
	else if(c=='{')
	{
		int temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		c=getchar();
		if(c!='}')
		{
			return 0;
		}
		temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		return 1;
	}
}

int Matching()
{
	int ans=Parenthesis();//括号匹配
	if(ans==0)
	{
		return 0;
	}
	char c=getchar();//匹配完应该读完
	if(c!=EOF)
	{
		return 0;
	}
	return 1;
}

int main()
{
	int ans=Matching();
	if(ans==1)
	{
		printf("AC\n");
	}
	else
	{
		printf("CE\n");
	}
}

