#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define MOD 100000000
#define maxn 10010
#define debug 0
using namespace std;
/*****************************************************************
��ĳ��Ȳ���˵��
��Ҫ������������ο��Ƿ�����DP
��f[i][j]=k��ʱ���Ǿͼ���f[i-1][j]��f[i][j-1]���е�Ϊk�ķ�����
���A[i]==B[j]��f[i-1][j-1]=k-1�ķ�����ҲҪ����
���A[i]!=B[j]������f[i-1][j-1]=k����������ľͶ����
��ʱҪ����f[i-1][j-1]�ķ���
���⣬���ǵ��ַ������޻�ǳ��Ĵ�����һ��Ҫ�ù�������
*****************************************************************/
char A[maxn],B[maxn];
int f[2][maxn], g[2][maxn];
int now, pre;//����γ�ȱ��
int n, m;//
inline void eraseDP() {
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
}
inline void buildDP() {
	now = 1, pre = 0;//��ʼ�ȴ�1��ʼ���
	for (int i = 0; i <= m; ++i) g[0][i] = 1; g[1][0] = 1;//�Զ��׼�
	//Ԥ����ע��:j=1Ҫ��j=0�������������߽�����ҲҪ����!
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			f[now][j] = max(f[pre][j], f[now][j - 1]);
			g[now][j] = 0;//��������ע����ʱˢ��
			if(A[i]==B[j])f[now][j] = max(f[pre][j - 1] + 1, f[now][j]);
			if (A[i] == B[j] && f[now][j] == f[pre][j - 1] + 1)g[now][j] += g[pre][j - 1];
			if(f[now][j] == f[pre][j - 1])g[now][j] -= g[pre][j - 1];
			if (f[now][j - 1] == f[now][j])g[now][j] += g[now][j - 1];
			if(f[pre][j] == f[now][j])g[now][j] += g[pre][j];
			g[now][j] = (g[now][j] + MOD) % MOD;
			if (debug)cout << "Current DP " << i << " " << j << " " << g[now][j] << endl;
		}
		now = pre; pre = 1 - pre;//������!
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> A + 1 >> B + 1) {
		n = strlen(A + 1) - 1;
		m = strlen(B + 1) - 1;
		if (debug)cout << n << " " << m << endl;
		eraseDP(); buildDP();
		cout << f[pre][m] << endl << g[pre][m] << endl;
	}



}