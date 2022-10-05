#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define maxf 204799910
char wbuf[maxf];
int len;
char* p_now;
void read_in() {
	len = fread(wbuf, 1, maxf, stdin);
	wbuf[len] = '\0';
	p_now = wbuf;
}
char* read_str() {
	while (isspace(*p_now))
		++p_now;
	char* begin = p_now;
	while (!isspace(*p_now))
		++p_now;
	*p_now = '\0';
	return begin;
}
int read_int() {
	int ret = 0;
	int k = 1;
	while (!isdigit(*p_now)) {
		if (*p_now == '-')k = -1, *p_now = '\0';
		++p_now;
	}
	do { ret = (ret << 1) + (ret << 3) + (*p_now ^ '0'), * p_now = '\0', ++p_now; } while (isdigit(*p_now));
	return ret * k;
}

typedef struct info {
	char* name;
	int num, _index;
}info;
info a[200010];
int cmp(const void* p1, const void* p2) {
	info* x = (info*)p1, * y = (info*)p2;
	if (x->num != y->num)return x->num - y->num;
	else return x->_index - y->_index;
}

void wr(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}

int n, nn, m, mm, i;
int main() {
	//freopen("in.txt", "r", stdin);
	read_in();
	n = read_int(), m = read_int();
	//printf("n is %d m is %d\n", n, m);
	nn = n, mm = m;
	for (i = 1; i <= nn; ++i) a[i]._index = i, a[i].num = read_int(), a[i].name = read_str();
	qsort(a + 1, nn, sizeof(a[0]), cmp);
	while (mm--) {
		i = read_int();
		wr(a[i].num), putchar(' '), puts(a[i].name);
	}
	
}