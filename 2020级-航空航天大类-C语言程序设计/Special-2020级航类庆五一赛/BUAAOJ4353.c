#include<stdio.h>
int cnt[114514];
int win(char from, char to) {
	return (from == 'A' && to == 'C') || (from == 'B' && to == 'A') || (from == 'C' && to == 'B');
}
int tot, cur;
char A[20], B[20];
int main() {
	scanf("%d", &tot);
	while (scanf("%d%s%s", &cur, A, B) != EOF) {
		++cnt[tot], ++cnt[cur];
		if (!win(A[0], B[0])) tot = cur;
	}
	printf("%04d %d\n", tot, cnt[tot]);
}