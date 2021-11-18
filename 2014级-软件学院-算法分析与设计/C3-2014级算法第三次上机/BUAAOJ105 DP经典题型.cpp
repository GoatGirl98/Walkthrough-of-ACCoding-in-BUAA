#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#define maxn 510
using namespace std;

/**********************************************
最优二叉搜索树的搜索期望
n个关键字的搜索概率为p1到pn
叶子节点n+1个，概率p0到pn

每个节点的期望是(搜索深度+1)*概率

最优子结构
设dp[i][j]为包含ki...kj关键字树的搜索代价
设这几个关键字组成的树以kr为根，则左右子树为
ki,ki+1,...,kr-1和kr+1...kj
对应叶子分别为di-1...dr-1和dr...dj
1，只有一个叶子组成的子树j=i-1只有di-1
则e[i][j]=qi-1 
这个子树为一个叶节点，不再划分左右树
还有关键字的话就接着划分左右子树i<=j
e[i][j]=min{e[i][r-1]+e[r+1][j]+w[i][j]}
**********************************************/
int n;
double p[maxn], q[maxn];//关键字搜索概率和叶子节点概率
double e[maxn][maxn];//ki...kj的搜索概率 答案也是这个
double w[maxn][maxn];//ki...kj的搜索总和
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
		//1到k有k个关键字参与构造树
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
