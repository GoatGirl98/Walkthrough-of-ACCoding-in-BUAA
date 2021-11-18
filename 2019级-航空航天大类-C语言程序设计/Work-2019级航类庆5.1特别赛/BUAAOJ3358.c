#include<stdio.h>
char s[15][15];
int i, j, k, l;
int main() {
	for (i = 1; i <= 10; ++i)scanf("%s", s[i] + 1);
	for (i = 1; i <= 10; ++i) {
		for (j = 1; j <= 10; ++j) {
			if (s[i][j] == 'X') {
				for (k = i - 1; k <= i + 1; ++k)
					for (l = j - 1; l <= j + 1; ++l)
						if ((!(k == i && l == j)) && s[k][l] != 'X')
							++s[k][l];
			}
		}
	}
	for (i = 1; i <= 10; ++i, putchar('\n'))
		for (j = 1; j <= 10; ++j) 
			putchar(s[i][j] == '0' ? ' ' : s[i][j]);
		
			
}