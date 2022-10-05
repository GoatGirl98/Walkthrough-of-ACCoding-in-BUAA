#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char s[50];
char card[50];
int cnt;

int cmp(const void* p1, const void* p2)
{
	char *a = (char *)p1;
	char *b = (char *)p2;
	if(*a<*b)
	{
		return -1;
	}
	else if(*a>*b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void print(char *color)
{
	memset(card, 0, sizeof(card));
	cnt = 0;
	char *start=s;
	char *pos;
	while((pos = strstr(start, color)) != NULL)
	{
		char *ptr = pos;
		pos--;
		for(; pos - s >= 0 && isdigit(*pos); --pos)
		{
			card[cnt] = *pos;
			cnt++;
		}
		start = ptr + 1;
	}
	if(cnt == 0)
	{
		return;
	}
	qsort(card, cnt, sizeof(card[0]), cmp);
	printf("%s%s", card, color);
}

int main()
{
	while(scanf("%s", s) != EOF)
	{
		print("m");
		print("p");
		print("s");
		print("z");
		putchar('\n');
	}
}