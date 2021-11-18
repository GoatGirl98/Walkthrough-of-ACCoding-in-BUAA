#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define maxn 510
#define INF 2147483647
using namespace std;
/****************************************************************
floyd������Ŀ:

��β�ѯ���Ǿ�һ�����꣬�ռ�o(n^2)ʱ��o(n^3)

(����㷨������Ҳ��DP˼�룬3άת2ά)
���·״̬ת�Ʒ���Ϊ
floyd[i][j] = min{floyd[i][k]+floyd[k][j],floyd[i][j]}
��Ȩ���Դ�����������-1Ҫ���INF�����Ǹ�������
�������ⶵȦ�Ŀ�����ֻ���Լ����Լ�
****************************************************************/
unsigned int floyd[maxn][maxn];
int n, q;
int start, finish;
inline void eraseMap() {
	memset(floyd, 0, sizeof(floyd));
}
inline void buildMap() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> q) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> floyd[i][j];
				if (floyd[i][j] == -1)floyd[i][j] = INF;
			}
		}
		buildMap();
		while (q--) {
			cin >> start >> finish;
			if (start == finish || floyd[start][finish] >= INF)
				cout << "jujue" << endl;
			else cout << floyd[start][finish] << endl;
		}

	}
}