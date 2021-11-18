#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 200010
#define INF 0x3f3f3f3f
using namespace std;
int n, k;
int f[maxn];
int cnt;
int ans;
inline void init() {
    for (int i = 1; i <= n; ++i)
        f[i] = i;
}
int getFather(int x, int& cnt) {
    cnt++;
    return f[x] == x ? x : getFather(f[x], cnt);
}
int main() {
    while (scanf("%d", &n) != EOF) {
        ans = INF;
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &k);
            cnt = 0;
            if (getFather(k, cnt) == i) {
                //将两者并起来，如果两者相等了就意味着有环路
                ans = min(ans, cnt);
            }
            else f[i] = k;
        }
        printf("%d\n", ans);
    }
}
