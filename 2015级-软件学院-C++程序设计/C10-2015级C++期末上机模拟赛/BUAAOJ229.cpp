#include <cstdio>
#define maxn 15

int ans[maxn];
bool occupied[maxn];
int n;
void dfs(int i) {
    if (i > n) {
        for (int j = 1; j <= n; ++j)printf("%d", ans[j]);
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
    while (scanf("%d", &n) && n) {
        dfs(1);
        putchar('\n');
    }
}
