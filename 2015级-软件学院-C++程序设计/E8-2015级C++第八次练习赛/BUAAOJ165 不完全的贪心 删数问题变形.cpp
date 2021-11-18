#include<cstdio>
#include<cstring>
#define maxn 10010
char num[maxn];
int n, s;
int remain;
int main() {
	while (scanf("%d%d%s", &n, &s, num) != EOF) {
		int mi = 0;
		remain = n - s;
		for (int i = 0; i <= s; ++i) {
			if (num[i] < num[mi] && num[i] != '0') {
				mi = i;
			}
		}
		s -= mi;
		for (int i = mi + 1; i < n; ++i) {
			int j = i - 1;
			while (s > 0 && j > mi&& num[j] > num[i]) {
				if (num[j] != ':')s--, num[j] = ':';
				j--;
			}
			if(s == 0)break;
		}

		for (int i = mi, j = 0; i < n && j < remain; ++i) {
			if (num[i] != ':')putchar(num[i]), ++j;
		}
		putchar('\n');
	}
}