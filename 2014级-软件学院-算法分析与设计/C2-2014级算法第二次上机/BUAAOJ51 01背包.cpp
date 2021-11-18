#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define maxn 20010
using namespace std;

/********************************************
01背包板子题目:

f[i][v]为前i件物品放入一个容量j的背包最大权值
f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}

然后日常地二维压缩一维
i 1->n v V->0  f[v]=max{f[v],f[v-c[i]]+w[i]}
********************************************/

int dp[maxn];
int inputTime, inputValue;
int maxPack, videoCount;
inline void eraseDP() {
	memset(dp, 0, sizeof(dp));
}

inline void buildDP() {
	for (int i = maxPack; i >= 0; --i) {
		dp[i] = (i >= inputTime) ? max(dp[i - inputTime] + inputValue, dp[i]) : dp[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> maxPack >> videoCount) {
		eraseDP();
		while (videoCount--) {
			cin >> inputValue >> inputTime;
			buildDP();
		}
		cout << dp[maxPack] << endl;
	}
}
