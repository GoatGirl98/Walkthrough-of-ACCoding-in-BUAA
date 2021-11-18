#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
FILE* in;
/***************************************
�������ڶ��ִ𰸵��У�Ѱ�ҺϷ�����Сֵ
���ڵ�Ҳ���Ϸ���С�ڵľ��Բ��Ϸ�

�ڼ����һ����i��ʼ������֮��
��������Ҫ��lower_bound
���ҵ�һ�����ڵ���i+size��1
ʵ��֤��������ȫû�б�Ҫ...
ֱ������ʵʵ���������
***************************************/
int n, m;
const int maxn = 1000000 + 10;
char instr[maxn];
int Onesize;
//int oneplace[maxn];
int lo, hi, mi;
int t;
int main() {
	//in = freopen("testfile for BUAAOJ447.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		scanf("%s", instr);
		Onesize = 0;
		for (int i = 0; i < n; ++i) {
			if (instr[i] == '1') {
				Onesize++;
			}
		}
		if (m == 0) {
			printf("Case %d: 0\n", ++t);
			continue;
		}
		if (Onesize <= 1) {
			printf("Case %d: %d\n", ++t, Onesize);
			continue;
		}
		lo = 1, hi = n / m + 1;
		while (hi > lo) {
			mi = (hi + lo) >> 1;
			int needK = 0;
			int cur = 0;
			for (int i = 0; i < n; ) {
				if (instr[i] == '1' && cur <= i) {
					i += mi, cur = i;
					if (++needK > m)break;
				}
				else ++i;
			}
			if (needK <= m)hi = mi;
			else lo = mi + 1;
		}
		printf("Case %d: %d\n", ++t, lo);
	}
}