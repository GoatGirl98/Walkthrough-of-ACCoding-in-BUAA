#include<stdio.h>

int LINE;//当前行号

struct expr
{
	int valid;
	int isline;//是行号
	int value;//名字或行号
};

struct expr express();

struct expr func(char name,struct expr lhs)//传入函数名，已知的左值，默认左括号也被读了。左值仅当valid的时候才会输出
{
	struct expr mem[100];
	int top=0;
	char next=0;
	while(next!=')')//回退时并不改变next。执行函数的参数列表项 
	{
		mem[top]=express();
		top++;
		next=getchar();//右小括号或逗号
	}//结束的时候右小括号已经读过了 
	printf("%c",name);
	if(lhs.valid==1)
	{
		if(lhs.isline==1)//是行号
		{
			printf(" %d",lhs.value);
		}
		else
		{
			printf(" %c",(char)lhs.value);
		}
	}
	int i;
	for(i=0;i<top;i++)
	{
		if(mem[i].isline==1)//是行号
		{
			printf(" %d",mem[i].value);
		}
		else
		{
			printf(" %c",(char)mem[i].value);
		}
	}
	printf("\n");
	LINE++;
	struct expr temp;
	temp.valid=1;
	temp.isline=1;
	temp.value=LINE;
	return temp;
}

struct expr parse_primary()//处理常量、括号、普通函数。返回行号
{
	char next=getchar();
	if(next=='(')//左括号 
	{
		struct expr temp=express();
		next=getchar();//右括号
		return temp;//直接无脑弹出temp 
	}
	else//标识符。函数也在这部分
	{
		char temp=next;
		next=getchar();
		if(next=='(')//左括号 
		{
			struct expr nul;
			nul.valid=0;
			return func(temp,nul);
		}
		else//一个普通的标识符
		{
			ungetc(next,stdin);//退回左括号
			struct expr ans;
			ans.isline=0;
			ans.valid=1;
			ans.value=temp;
			return ans;
		}
	}
}

struct expr combine(struct expr lhs,char op,struct expr rhs)//处理加减乘除。输出语句，返回行号expr
{
	printf("%c ",op);
	if(lhs.isline==1)//是行号
	{
		printf("%d ",lhs.value);
	}
	else
	{
		printf("%c ",(char)lhs.value);
	}
	if(rhs.isline==1)//是行号
	{
		printf("%d\n",rhs.value);
	}
	else
	{
		printf("%c\n",(char)rhs.value);
	}
	LINE++;
	struct expr temp;
	temp.valid=1;
	temp.isline=1;
	temp.value=LINE;
	return temp;
}

int prec(char op)//返回指定算符的优先级
{
	if(op=='+'||op=='-')
	{
		return 1;
	}
	else if(op=='*'||op=='/')
	{
		return 2;
	}
}

int isop(char op)
{
	if(op=='+'||op=='-'||op=='*'||op=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct expr parse_opg(struct expr lhs,int cerp)//cerp是左部优先级。每次调用这个的时候，下一个总应该是运算符。点运算应该在这里特判。所有的lhs rhs代表行号
{
	char peek=getchar();//运算符1，prec是优先级
	while(peek=='.')//是个点运算
	{
		char temp=getchar();
		getchar();//左括号
		lhs=func(temp,lhs);
		peek=getchar();//再来
	}
	while(isop(peek)&&prec(peek)>=cerp)//peek是二元运算符，peek优先级大于等于左部旧优先级就要规约
	{
		char op=peek;
		struct expr rhs=parse_primary();//右部读一个并解析某个东西3
		peek=getchar();//再预读下一个运算符2。比较1和2两个运算符的优先级
		while(peek=='.')//是个点运算
		{
			char temp=getchar();
			getchar();//左括号
			rhs=func(temp,rhs);
			peek=getchar();//再来
		}
		while(isop(peek)&&prec(peek)>prec(op))//peek是二元运算符且peek优先级大于op优先级。因为赋值只能出现一次，且优先级最低，故无需考虑右结合
		{
			ungetc(peek,stdin);//这里必须退回运算符2
			rhs=parse_opg(rhs,prec(peek));//做右边
			peek=getchar();
			while(peek=='.')//是个点运算
			{
				char temp=getchar();
				getchar();//左括号
				rhs=func(temp,rhs);
				peek=getchar();//再来
			}
		}
		lhs=combine(lhs,op,rhs);//表示规约
	}
	ungetc(peek,stdin);//这里必须退一个后面的字符
	return lhs;
}

struct expr express()
{
	struct expr lhs=parse_primary();
	struct expr ans=parse_opg(lhs,0);
	return ans;
}

int main()
{
	express();
	return 0;
}