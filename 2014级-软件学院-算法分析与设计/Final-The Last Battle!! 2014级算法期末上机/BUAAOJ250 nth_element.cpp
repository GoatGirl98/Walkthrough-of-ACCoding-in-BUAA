#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#define maxn 1000010
#define RADIX 10
using namespace std;
struct map {
	int num;
	int size;
}maps[maxn];
inline bool cmp(map a, map b) {
	return a.size > b.size;
}
int n, k;
bool isEnd;
inline void init() {
	for (int i = 0; i < n; ++i)maps[i].num = i + 1;
}
inline int read() {
	int k = 0;
	char c = getchar();
	while (!isdigit(c))c = getchar();
	while (isdigit(c)) { k = (k << 1) + (k << 3) + c - 48; c = getchar(); }
	if (c == EOF)isEnd = true;
	return k;
}
inline void write(int a) {
	if (a >= RADIX)write(a / RADIX);
	putchar(a % RADIX + 48);
}
inline void print(int a, int b) {
	putchar('m'), putchar('a'), putchar('p');
	write(a);
	putchar(' '), putchar(':'), putchar(' ');
	write(b);
	putchar('\n');
}
int main() {
	while (scanf("%d%d",&n,&k)!=EOF) {
		init();
		for (int i = 0; i < n; ++i)maps[i].size = read();
		nth_element(maps, maps + k, maps + n, cmp);
		print(maps[k - 1].num, maps[k - 1].size);
	}
}
