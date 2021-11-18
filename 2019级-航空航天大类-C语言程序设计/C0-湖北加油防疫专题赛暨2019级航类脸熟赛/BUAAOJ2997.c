#include<stdio.h>
#include<string.h>
int t;
char s[101];
int main() {
	scanf("%d", &t);
	while (t--) { 
		scanf("%s", s); 
		if (strstr(s, "xxgzbd"))puts(s);
	}
}