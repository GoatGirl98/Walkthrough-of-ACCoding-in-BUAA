#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define maxn 100010
using namespace std;
int dp[maxn];
int cost[maxn], value[maxn], remain[maxn];
int n, V;
inline void buildDP_multiPack() {
    for (int i = 1; i <= n; ++i) {
        int num = min(remain[i], V / cost[i]);
        for (int k = 1; num > 0; k <<= 1) {
            if (k > num)k = num;
            num -= k;
            for (int j = V; j >= cost[i] * k && j; --j) {
                dp[j] = max(dp[j], dp[j - cost[i] * k] + value[i] * k);
            }
        }
    }
}
int main() {
    while (~scanf("%d%d", &n, &V)) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &remain[i], &cost[i], &value[i]);
        }
        buildDP_multiPack();
        printf("%d\n", dp[V]);
    }
} 
