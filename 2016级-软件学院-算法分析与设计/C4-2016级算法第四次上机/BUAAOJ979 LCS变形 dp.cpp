#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 110
using namespace std;
char A[maxn],B[maxn];//两个字符串
int dp[maxn][maxn];
int n, m;//A,B的长度
int targetLen;
inline void buildDP() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if ((B[j]!='#')&&(A[i]!='#')&&(A[i] == B[j]||A[i]=='?'||B[j]=='?'))
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
}
int main() {
    while (scanf("%s%s", A + 1, B + 1) != EOF) {
        n = strlen(A+1);
        m = strlen(B+1);
        memset(dp, 0, sizeof(dp));
        buildDP();
        printf("%d\n", dp[n][m]);
    }
}
