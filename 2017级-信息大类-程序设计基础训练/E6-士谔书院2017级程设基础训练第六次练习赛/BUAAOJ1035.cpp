#include <cstdio>
#define MAXN 3010
int n, s, m;
int vis[MAXN];
//找到下一个人
int go(int x) {
    x = (x + 1) % n;
    //如果当前的这个人已经出队，那么继续寻找
    while (vis[x]) {
        x = (x + 1) % n;
    }
    return x;
}
int main() {
    scanf("%d%d%d", &n,&s, &m);
    --s;
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 1; j < m; ++j) {
            s = go(s);
        }
        printf("%d\n", s + 1);
        vis[s] = 1;
        s = go(s);
    }
    printf("%d\n", go(s) + 1);
    return 0;
}
