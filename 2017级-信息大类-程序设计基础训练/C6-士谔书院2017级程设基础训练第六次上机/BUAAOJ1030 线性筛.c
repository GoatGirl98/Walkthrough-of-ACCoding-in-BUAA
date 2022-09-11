#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define maxn 10000010
unsigned n;
unsigned prime[maxn], cnt;
bool vis[maxn];
unsigned out;
unsigned i, j;
//欧拉筛
void get_prime(unsigned n) {
	vis[1] = 1;
	for (i = 2; i <= n; ++i) {
		if (!vis[i])prime[++cnt] = i;
		for (j = 1; j <= cnt && prime[j] * i <= n; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}
int main() {
	scanf("%u", &n);
	get_prime(n);
	printf("%u", cnt);
}
