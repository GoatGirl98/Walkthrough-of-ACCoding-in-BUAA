#include<cstdio>
#include<cstring>
#include<cmath>
#define RADIX 2
typedef long long ll;
/**************************************************************
仔细看了一下，这题其实就是一个二进制计数器的势能法摊还分析

但是这个题其实是每一步的摊还分析
如果翻转到全部为0的话，摊还代价就是0 其他情况都是1
这些在树上都是有的
所以只要判断是输出0还是2即可
**************************************************************/
int k;
int N;
int start_num;
int radix;
int tmp;
int main() {
	while (scanf("%d", &k) != EOF) {
		radix = 1 << k;
		start_num = 0;
		for (int i = 1; i <= k; ++i) {
			scanf("%d", &tmp);
			start_num = (start_num << 1) + tmp;
		}
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			start_num = (start_num + 1) % radix;
			if (!start_num)printf("0 ");
			else printf("2 ");
		}
		putchar('\n');
	}
}