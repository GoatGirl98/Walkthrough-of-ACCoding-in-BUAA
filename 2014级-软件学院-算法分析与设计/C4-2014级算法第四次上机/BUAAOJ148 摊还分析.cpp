#include<cstdio>
#include<cstring>
#include<cmath>
#define RADIX 2
typedef long long ll;
/**************************************************************
��ϸ����һ�£�������ʵ����һ�������Ƽ����������ܷ�̯������

�����������ʵ��ÿһ����̯������
�����ת��ȫ��Ϊ0�Ļ���̯�����۾���0 �����������1
��Щ�����϶����е�
����ֻҪ�ж������0����2����
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