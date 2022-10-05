#include<stdio.h>
#include<ctype.h>

int main()
{
	char c;
	int d=0;
	while((c=getchar())!=EOF)
	{
		if(d==0&&islower(c))
		{
			putchar(toupper(c));
			d=1;
		}
		else if((isupper(c)||c=='"'||isdigit(c)))
		{
			putchar(c);
			d=1;
		}
		else if(c=='?'||c=='.'||c=='!')
		{
			d=0;
			putchar(c);
		}
		else
		{
			putchar(c);
		}
	}
	return 0;
}