#include<cstdio>
#define maxn 15
int t, n;
int k, cnt;
int a[maxn];
bool occur[maxn];
inline void dfs(int x) {
    if (x == n) {
        ++cnt;
        if (cnt == k) {
            for (int i = 0; i < n; ++i)printf("%d ", a[i] + 1);
            putchar('\n');
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!occur[i] && i != x) {
            occur[i] = true;
            a[x] = i;
            dfs(x + 1);
            occur[i] = false;
        }
    }
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        cnt = 0;
        dfs(0);
    }
}
