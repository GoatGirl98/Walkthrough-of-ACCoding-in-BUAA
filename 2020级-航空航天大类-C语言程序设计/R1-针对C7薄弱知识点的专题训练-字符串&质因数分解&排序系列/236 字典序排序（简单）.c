#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int comp(const void*p1,const void*p2)
{
	if(*(char*)p1>*(char*)p2)
	{
		return 1;
	}
	else if(*(char*)p1<*(char*)p2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

char s[1000];

int main()
{
	while(gets(s))
	{
		int n=strlen(s);
		qsort(s,n,sizeof(char),comp);
		puts(s);
	}
}