#include<algorithm>
#include<set>
#include<cstring>
#include<iostream>
#include<string>
#define maxn 110
using namespace std;
/***************************************************************
这题只有前面的DP是个板子，而且并不难
这题没有同时出长度和序列的方法
只能出完长度之后回溯
第一部分是DP
f[i][j]=max{f(i-1,j),f(i,j-1),f(i-1,j-1)+1(if a[i] == b[j])}
这里在应对最长可能到10000的数据的时候，会被炸空间
所以可能要降维用滚动数组不可避（小技巧get√）
第二部分是所有方案
由于要求不重不漏，所以本身可以DP现在却不行了
那就利用暴力搜索
***************************************************************/
char A[maxn],B[maxn];//两个字符串
int dp[maxn][maxn];//dp长度的时候采用滚动数组防止MLE
//int preMark, nowMark;//判断滚动数组的状态，哪一行是之前的状态，哪一行是现在的
int n, m;//A,B的长度
int targetLen;
set<string>ans;//默认的按照字典序进行排序
inline void eraseDP() {
    memset(dp, 0, sizeof(dp));
    ans.clear();
}
inline void buildDP() {
    //preMark = 0; nowMark = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i] == B[j]) {
                
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            //nowMark = preMark; preMark = 1 - preMark;
            //更新，当然了，最后结果是dp[preMark][m]
        }
    }
    targetLen = dp[n][m];
    
}

inline void dfs(int i, int j, string s) {
    //按照长度找串，逆向找，stl复杂度精简
    if (i <= 0 || j <= 0)return;
    if (A[i] == B[j]) {
        s.push_back(A[i]);
        if (s.length() == targetLen) {
            reverse(s.begin(), s.end());
            ans.insert(s);
        }
        else dfs(i - 1, j - 1, s);
    }
    else {
        if (dp[i - 1][j] >= dp[i][j - 1])dfs(i - 1, j, s);
        if (dp[i - 1][j] <= dp[i][j - 1])dfs(i, j - 1, s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (scanf("%s%s", A + 1, B + 1) != EOF) {
        n = strlen(A+1);
        m = strlen(B+1);
        eraseDP();
        buildDP();
        dfs(n, m, "");
        for (string s : ans)cout << s << endl;
    }
}
