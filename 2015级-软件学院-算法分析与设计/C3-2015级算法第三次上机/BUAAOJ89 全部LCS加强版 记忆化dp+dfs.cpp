#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#define Max(a,b) (((a)>(b))?(a):(b))
#define maxn 110
using namespace std;
char A[maxn], B[maxn];
char tmp[maxn];
int n, m;
int dp[maxn][maxn];
int lasta[maxn][27];
int lastb[maxn][27];
int targetLen;
set<string> ans;
inline void init() {
    memset(dp, 0, sizeof(dp));
    memset(lasta, 0, sizeof(lasta));
    memset(lastb, 0, sizeof(lastb));
    memset(tmp, 0, sizeof(tmp));
    ans.clear();
}
inline void buildDP() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i] == B[j])
                dp[i][j] = Max(dp[i][j], dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    targetLen = dp[n][m];
}
inline void buildLast() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (A[i] == 'A' + j)lasta[i][j] = i;
            else lasta[i][j] = lasta[i - 1][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (B[i] == 'A' + j)lastb[i][j] = i;
            else lastb[i][j] = lastb[i - 1][j];
        }
    }
}
inline void dfs(int i, int j, int len) {
    if (len <= 0) { ans.insert(string(tmp + 1)); return; }
    if (i > 0 && j > 0) {
        for (int k = 0; k < 26; ++k) {
            int t1 = lasta[i][k];
            int t2 = lastb[j][k];
            if (dp[t1][t2] == len) {
                tmp[len] = 'A' + k;
                dfs(t1 - 1, t2 - 1, len - 1);
            }
        }
    }
}
inline void printAns() {
    for (set<string>::iterator it = ans.begin(); it != ans.end(); ++it)
        puts((*it).c_str());
}
int main() {
    while (scanf("%s%s", A + 1, B + 1) != EOF) {
        init();
        n = strlen(A + 1), m = strlen(B + 1);
        buildDP();
        buildLast();
        tmp[targetLen + 1] = '\0';
        dfs(n, m, targetLen);
        printAns();
    }
}
