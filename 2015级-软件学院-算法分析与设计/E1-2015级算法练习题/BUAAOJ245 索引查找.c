#include<stdio.h>
#include<string.h>
#define maxn 1000010
int number[maxn];
int from[402], to[402];
int n, k;
int i;
int GPA, curGPA;
int readNum() {
	int k = 0;// int f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		//if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;//*f
}
int readGPA() {
	int k = 0;// int f = 1;
	int count = 0;
	char c = getchar();
	while (c < '0' || c>'9') {
		//if (c == '-')f = -1;
		c = getchar();
	}
	while ((c >= '0' && c <= '9') || c == '.') {
		if (c != '.') { 
			k = (k << 1) + (k << 3) + c - 48;
			++count;
		}
		c = getchar();
	}
	for(;count < 3; ++count) k = (k << 1) + (k << 3);
	return k;//*f
}
void write(int x) {
	//if(x < 0)putchar('-'),x=-x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
int main() {
	while (scanf("%d", &n) != EOF) {
		k = readNum();
		memset(from, -1, sizeof(from));
		memset(from, -1, sizeof(to));
		number[0] = readNum();
		curGPA = readGPA();
		from[curGPA] = 0;
		for (i = 1; i < n; i++) {
			number[i] = readNum();
			GPA = readGPA();
			if (GPA != curGPA) {
				to[curGPA] = i - 1;
				curGPA = GPA;
				from[GPA] = i;
			}
		}
		to[curGPA] = i - 1;
		while (k--) {
			GPA = readGPA();
			if (from[GPA] < 0) {
				puts("No solution!");
			}
			else {
				for (i = from[GPA]; i <= to[GPA]; i++) {
					write(number[i]); putchar(' ');
				}
				putchar('\n');
			}
		}
	}
}