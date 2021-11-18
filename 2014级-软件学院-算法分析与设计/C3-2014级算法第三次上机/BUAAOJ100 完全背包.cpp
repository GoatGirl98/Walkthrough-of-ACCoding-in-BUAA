#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define maxn 20010
using namespace std;

/*****************************************************
完全背包板子题目:

f[i][v]为前i件物品放入一个容量j的背包最大权值
f[i][v]=max{f[i-1][v-k*c[i]]+k*w[i]|0<=k*c[i]<=v}
但是这个算法复杂度太高了，要往下降

优化点1:c[i]<=v[j]&&w[i]>=w[j]的话，j可以直接舍去
但是这个并不必要，使用非插值排序的话反而更慢
优化点2:转化成01背包来解决
考虑到第i种物品最多V/c[i]件，所以将第i种物品转化为
V/c[i]件费用价值均不变的物品，或者转成2^k种物品
最快的板子是O(vn)，把1维01背包改个顺序就都对了

i 1->n v 0->v  f[v]=max{f[v],f[v-c[i]]+w[i]}
因为完全背包的特点恰好是无限制，所以加选的时候却可能
正好要用一个可能已经选入第i种物品的子结果
*****************************************************/

int dp[maxn];
int inputTime, inputValue;
int maxPack, videoCount;
inline void eraseDP() {
    memset(dp, 0, sizeof(dp));
}

inline void buildDP() {
    for (int i = 0; i <= maxPack; ++i) {
        dp[i] = (i >= inputTime) ? max(dp[i - inputTime] + inputValue, dp[i]) : dp[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> maxPack >> videoCount) {
        eraseDP();
        for(int i = 0; i < videoCount; ++i) {
            cin >> inputValue >> inputTime;
            buildDP();
        }
        cout << dp[maxPack] << endl;
    }
}
