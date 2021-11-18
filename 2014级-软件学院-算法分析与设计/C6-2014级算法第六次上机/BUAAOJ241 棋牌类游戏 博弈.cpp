#include<cstdio>
#include<algorithm>
#define maxn 10010
using namespace std;
int a[maxn], b[maxn];
int m, n;
int remain;
int ans, cnt;
/*****************************************
题目的意思其实就是一共有m人
一人手里n张牌(牌的大小从1到n*m)
首先知道自己的牌，又知道剩下的牌
所以要找出最小解的话，就要尽可能让别人赢
那可以把别人的手牌合在一起
每次出自己手里最大的牌，对面剩下的更大就输
*****************************************/
int main() {
	while (scanf("%d%d", &m, &n) != EOF) {
		remain = n;
		ans = cnt = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= m * n; ++i) {
			b[i] = i;
		}
		sort(a + 1, a + n + 1);

		for (int i = m * n; i > 0 && remain > 0; --i) {
			if (a[remain] != b[i])cnt++;
			else {
				if (cnt == 0)ans++;
				else cnt--;
				remain--;
			}
		}
		printf("%d\n", ans);
	}
}