#include<stdio.h>
char s[110];
int main() {
	fgets(s, 110, stdin), puts(s + 3);
}