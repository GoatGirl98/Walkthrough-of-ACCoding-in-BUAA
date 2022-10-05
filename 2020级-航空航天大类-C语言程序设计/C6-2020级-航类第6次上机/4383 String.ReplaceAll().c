#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 此函数用来去除字符串结尾的\r
int TrimEndR(char *base)
{
	while (base[strlen(base) - 1] == '\r')
	{
		base[strlen(base) - 1] = '\0';
	}
	return strlen(base);
}

char str[3015], old[30], news[30], newstr[3015];
char laji[5];

int main()
{
	int n;
	scanf("%d", &n), gets(laji); // scanf之后记得gets
	for (int i = 0; i < n; i++)
	{
		gets(str), gets(old), gets(news);
		TrimEndR(str), TrimEndR(old), TrimEndR(news);
		int strL = strlen(str), oldL = strlen(old), newL = strlen(news), cnt = 0;
		for (char *p = str; p < str + strL; p += oldL) // 每次找到旧串后将p跳过旧串的长度。
		{
			char *n = strstr(p, old);
			if (n == NULL)
			{
				for (; p < str + strL; p++, cnt++)
				{
					newstr[cnt] = *p;
				}
				break;
			}
			for (; p < n; p++, cnt++)
			{
				newstr[cnt] = *p;
			}
			for (int i = 0; i < newL; i++, cnt++)
			{
				newstr[cnt] = news[i];
			}
		}
		newstr[cnt] = '\0';
		puts(newstr);
	}
}

