#include<cstdio>
#include<cstring>
#include<cctype>
#define maxn 1010
int n, m;
inline int trans(char c) {
	return (isdigit(c) ? (c - '0') : (c - 'a' + 10));
}
inline bool read() {
	int i, j, k;
	char c = getchar();
	while (!isalnum(c)) {
		c = getchar();
	}
	i = trans(c), c = getchar(), i = (i << 4) + trans(c), c = getchar();
	j = trans(c), c = getchar(), j = (j << 4) + trans(c), c = getchar();
	k = trans(c), c = getchar(), k = (k << 4) + trans(c), c = getchar();
	return (i + j + k) < m;
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		m += (m << 1);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				putchar(read() + 48); putchar(' ');
			}
			putchar('\n');
		}
		putchar('\n');
	}
}
