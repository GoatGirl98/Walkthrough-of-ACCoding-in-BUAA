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
最长的长度不再说了
主要的问题在于如何考虑方案的DP
当f[i][j]=k的时候，那就加上f[i-1][j]与f[i][j-1]当中的为k的方案数
如果A[i]==B[j]那f[i-1][j-1]=k-1的方案数也要加上
如果A[i]!=B[j]，而且f[i-1][j-1]=k，那最上面的就多加了
此时要减个f[i-1][j-1]的方法
另外，考虑到字符串上限会非常的大，所以一定要用滚动数组
*****************************************************************/
char A[maxn],B[maxn];
int f[2][maxn], g[2][maxn];
int now, pre;//滚动纬度标记
int n, m;//
inline void eraseDP() {
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
}
inline void buildDP() {
	now = 1, pre = 0;//初始先从1开始打表
	for (int i = 0; i <= m; ++i) g[0][i] = 1; g[1][0] = 1;//显而易见
	//预处理注意:j=1要从j=0处衍生过来，边界条件也要加上!
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			f[now][j] = max(f[pre][j], f[now][j - 1]);
			g[now][j] = 0;//滚动数组注意随时刷新
			if(A[i]==B[j])f[now][j] = max(f[pre][j - 1] + 1, f[now][j]);
			if (A[i] == B[j] && f[now][j] == f[pre][j - 1] + 1)g[now][j] += g[pre][j - 1];
			if(f[now][j] == f[pre][j - 1])g[now][j] -= g[pre][j - 1];
			if (f[now][j - 1] == f[now][j])g[now][j] += g[now][j - 1];
			if(f[pre][j] == f[now][j])g[now][j] += g[pre][j];
			g[now][j] = (g[now][j] + MOD) % MOD;
			if (debug)cout << "Current DP " << i << " " << j << " " << g[now][j] << endl;
		}
		now = pre; pre = 1 - pre;//滚起来!
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