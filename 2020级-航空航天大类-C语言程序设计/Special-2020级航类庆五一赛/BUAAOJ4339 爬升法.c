#include<stdio.h>
#include<string.h>

char SYM[25];
int TOP;

struct expr
{
	char status[1030];
};

struct expr express();

struct expr parse_primary()
{
	struct expr temp;
	char next=getchar();
	int loc;
	int i;
	switch(next)
	{
		case'(':
			temp=express();
			next=getchar();
			break;
		case'~':
			temp=parse_primary();
			for(i=0; i<1026; i++)
			{
				temp.status[i]^=1;
			}
			break;
		default:
			for(i=0; i<TOP; i++)
			{
				if(SYM[i]==next)
				{
					loc=i;
					break;
				}
			}
			loc=1<<(TOP-loc-1);
			for(i=0; i<1026; i++)
			{
				temp.status[i]=((i&loc)!=0)?1:0;
			}
	}
	return temp;
}

struct expr express()
{
	struct expr lhs=parse_primary();
	char peek;
	for(peek=getchar(); peek=='&'||peek=='|'; peek=getchar())
	{
		struct expr rhs=parse_primary();
		if(peek=='&')
		{
			int i;
			for(i=0; i<1026; i++)
			{
				lhs.status[i]=lhs.status[i]&rhs.status[i];
			}
		}
		else if(peek=='|')
		{
			int i;
			for(i=0; i<1026; i++)
			{
				lhs.status[i]=lhs.status[i]|rhs.status[i];
			}
		}
	}
	ungetc(peek,stdin);
	return lhs;
}

int main()
{
	TOP=0;
	char c;
	while((c=getchar())!='\n')
	{
		if(c!=' '&&c!='\r')
		{
			SYM[TOP]=c;
			TOP++;
		}
	}
	struct expr ans=express();
	printf("|");
	int i;
	for(i=0; i<TOP; i++)
	{
		printf(" %c |",SYM[i]);
	}
	printf(" R |\n");
	int line=1<<TOP;
	for(i=0; i<line; i++)
	{
		printf("|");
		int j;
		for(j=TOP-1; j>=0; j--)
		{
			((i>>j)&1)?printf(" T |"):printf(" F |");
		}
		(ans.status[i]!=0)?printf(" T |\n"):printf(" F |\n");
	}
	return 0;
}