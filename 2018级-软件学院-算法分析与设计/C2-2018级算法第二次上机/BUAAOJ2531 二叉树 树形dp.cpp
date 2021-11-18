#include<cstdio>
typedef long long ll;
const int maxn = 114514;
const ll MOD = 1000000007;
inline int read() {
    int k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
int n;
int ch[maxn][2];
//保证根节点是1,则省去了记录入度的需求
int status[maxn];//具体好坏情况
//dp[i][j][k]在i这里理论值j,实际值k的可能个数,显然j!=k是题目所求的错误解
ll dp[maxn][2][2];
//dp[i][j][k] = \sum dp[lchild][a][b] * dp[rchild][c][d]
//(a nand b) = j (c nand d) = k
//递归基为外部节点0 dp[0][a][a] = 1, dp[0][a][~a] = 0(a = 0, 1)
void dfs(int i) {
    if(ch[i][0]) dfs(ch[i][0]);
    if(ch[i][1]) dfs(ch[i][1]);
    //为了方便,将4个值压缩在1个值内枚举
    for(int x = 0; x <= 15; ++x) {
        int a = (x & 8) >> 3, b = (x & 4) >> 2;
        int c = (x & 2) >> 1, d = x & 1;
        //printf("%d %d %d %d %d\n", i, a, b, c, d);
        int j = !(a & c);
        int k = status[i] == -1 ? !(b & d) : status[i];
        dp[i][j][k] += (dp[ch[i][0]][a][b] * dp[ch[i][1]][c][d]);
        dp[i][j][k] %= MOD;
    }
    //printf("%d : %lld %lld %lld %lld\n", i, dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]);
}
int main() {
    n = read();
    for(int i = 1; i <= n; ++i)
        ch[i][0] = read(), ch[i][1] = read(), status[i] = read();
    dp[0][0][0] = dp[0][1][1] = 1;
    dfs(1);
    printf("%lld\n", (dp[1][0][1] + dp[1][1][0]) % MOD);
}
