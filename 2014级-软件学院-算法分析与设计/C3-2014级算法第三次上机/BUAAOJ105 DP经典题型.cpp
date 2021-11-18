#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#define maxn 510
using namespace std;

/**********************************************
���Ŷ�������������������
n���ؼ��ֵ���������Ϊp1��pn
Ҷ�ӽڵ�n+1��������p0��pn

ÿ���ڵ��������(�������+1)*����

�����ӽṹ
��dp[i][j]Ϊ����ki...kj�ؼ���������������
���⼸���ؼ�����ɵ�����krΪ��������������Ϊ
ki,ki+1,...,kr-1��kr+1...kj
��ӦҶ�ӷֱ�Ϊdi-1...dr-1��dr...dj
1��ֻ��һ��Ҷ����ɵ�����j=i-1ֻ��di-1
��e[i][j]=qi-1 
�������Ϊһ��Ҷ�ڵ㣬���ٻ���������
���йؼ��ֵĻ��ͽ��Ż�����������i<=j
e[i][j]=min{e[i][r-1]+e[r+1][j]+w[i][j]}
**********************************************/
int n;
double p[maxn], q[maxn];//�ؼ����������ʺ�Ҷ�ӽڵ����
double e[maxn][maxn];//ki...kj���������� ��Ҳ�����
double w[maxn][maxn];//ki...kj�������ܺ�
inline void eraseDP() {
	for (int i = 0; i < maxn; ++i) { 
		p[i] = q[i] = 0.0; 
		for (int j = 0; j < maxn; ++j) {
			e[i][j] = w[i][j] = 0.0;
		}
	}
}
inline void buildDP() {
	for (int i = 1; i <= n + 1; ++i) {
		e[i][i - 1] = w[i][i - 1] = q[i - 1];
	}
	for (int k = 1; k <= n; ++k) {
		//1��k��k���ؼ��ֲ��빹����
		for (int i = 1; i <= n - k + 1; ++i) {
			int j = i + k - 1;
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j - 1] + p[j] + q[j];

			for (int r = i; r <= j; ++r) {
				double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if (t < e[i][j])e[i][j] = t;
			}
			
		}
	}
	printf("%.3lf\n", e[1][n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n) {
		eraseDP();
		for (int i = 1; i <= n; ++i)cin >> p[i];
		for (int i = 0; i <= n; ++i)cin >> q[i];
		buildDP();
	}
}
