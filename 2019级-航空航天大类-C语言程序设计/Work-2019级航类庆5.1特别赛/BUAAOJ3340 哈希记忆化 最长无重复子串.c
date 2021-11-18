#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 10010
char s[maxn];
int visit[256];
int ans;
int cur;
int endIndex, lastIndex;
int len;
int from, to;
int main() {
	while (scanf("%s", s) != EOF) {
		len = strlen(s);
		memset(visit, 0xff, sizeof(visit));
		visit[s[0]] = 0; ans = 0, cur = 1;
		endIndex = lastIndex = 0;//最长的结尾和当前的结尾
		for (int i = 1; i < len; ++i) {
			if (visit[s[i]] == -1)
				cur++, visit[s[i]] = i;
			else {
				if (lastIndex > visit[s[i]])
					cur++;
				else cur = i - visit[s[i]], lastIndex = visit[s[i]] + 1;
				visit[s[i]] = i;
			}
			if (cur > ans)ans = cur, endIndex = i;
		}
		printf("%d\n", ans);

	}
}