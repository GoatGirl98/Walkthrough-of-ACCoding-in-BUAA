#include<cstdio>
#include<algorithm>
#define maxn 25
using namespace std;
int dp[maxn];
int fibo[10] = { 1,1,2,3,5,8,13,21 };
/***********************************
感觉这道题还是斐波那契的变种

在n=1,2,3的时候ans=0
n=4的时候拿走4
n=5的时候拿走4，1,2,3,5 
看到这里我觉得就基本没问题了...
***********************************/
inline void buildDP() {
	dp[0] = dp[1] = dp[2] = dp[3] = 0;
	for (int i = 4; i < maxn; ++i) {
		int* pos = lower_bound(fibo, fibo + 8, i);
		int offset = pos - fibo;
		if (fibo[offset] == i)dp[i] = i - offset;
		else dp[i] = i - offset + 1;
	}
}
int n;
int main() {
	buildDP();
	while (scanf("%d", &n) != EOF)printf("%d\n", dp[n]);
}