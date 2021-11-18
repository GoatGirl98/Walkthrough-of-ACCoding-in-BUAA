#include<cstdio>
#include<algorithm>
#define maxn 10010
using namespace std;
int a[maxn], b[maxn];
int m, n;
int remain;
int ans, cnt;
/*****************************************
��Ŀ����˼��ʵ����һ����m��
һ������n����(�ƵĴ�С��1��n*m)
����֪���Լ����ƣ���֪��ʣ�µ���
����Ҫ�ҳ���С��Ļ�����Ҫ�������ñ���Ӯ
�ǿ��԰ѱ��˵����ƺ���һ��
ÿ�γ��Լ����������ƣ�����ʣ�µĸ������
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