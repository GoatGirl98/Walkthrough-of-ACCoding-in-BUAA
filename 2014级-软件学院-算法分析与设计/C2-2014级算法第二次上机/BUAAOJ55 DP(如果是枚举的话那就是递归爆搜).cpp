#include<cstdio>

long long ans[25];

inline void init() {
	ans[0] = ans[1] = 0;
	ans[2] = 1;

	for (int i = 3; i < 21; ++i) {
		ans[i] = (i - 1) * (ans[i - 1] + ans[i - 2]);
	}

}
int n;
int main() {
	init();
	while (scanf("%d", &n) != EOF)printf("%lld\n", ans[n]);
}