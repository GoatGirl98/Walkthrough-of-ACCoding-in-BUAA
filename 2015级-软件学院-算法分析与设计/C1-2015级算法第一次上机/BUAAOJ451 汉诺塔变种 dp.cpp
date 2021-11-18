#include<cstdio>
#include<algorithm>
typedef unsigned long long ull;
const int maxn = 65;
int n;
int start[maxn], finish[maxn];
ull dp(int* p, int i, int goal) {
    if (i == 0)return 0;
    if (p[i] == goal)return dp(p, i - 1, goal);
    else return dp(p, i - 1, 6 - p[i] - goal) + (1ll << (i - 1));
}
ull ans;
int t;
int main() {
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 1; i <= n; ++i)scanf("%d", start + i);
        for (int i = 1; i <= n; ++i)scanf("%d", finish + i);
        int k = n;
        while (k && start[k] == finish[k])k--;
        ans = 0;
        if (k >= 1) {
            int other = 6 - start[k] - finish[k];
            ans = dp(start, k - 1, other) + dp(finish, k - 1, other) + 1;
        }
        //printf("Case %d: ", ++t);
        printf("%llu\n", ans);
    }
}
