#include<stdio.h>
int num[1010];
int cnt[4];
int a[4];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", num + i), cnt[num[i]]++;
	for (int i = 1; i <= cnt[1] + cnt[2]; ++i) {
		if (num[i] == 3)++a[3];
		else if (num[i] == 2 && i <= cnt[1])++a[1];
		else if (num[i] == 1 && i > cnt[1])++a[2];
	}
	printf("%d\n", a[3] + (a[1] > a[2] ? a[1] : a[2]));
}