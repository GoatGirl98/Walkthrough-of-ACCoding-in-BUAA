#include <cstdio>
#define maxn 15

int ans[maxn];
bool occupied[maxn];
int n, m;
void dfs(int i) {
    if (i > m) {
        for (int j = 1; j <= m; ++j)printf("%d ", ans[j]);
        printf("\n"); return;
    }
    for (int j = 1; j <= n; j++) {
        if (!occupied[j]) {
            ans[i] = j;
            occupied[j] = true;
            dfs(i + 1);
            occupied[j] = false;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    dfs(1);
}
