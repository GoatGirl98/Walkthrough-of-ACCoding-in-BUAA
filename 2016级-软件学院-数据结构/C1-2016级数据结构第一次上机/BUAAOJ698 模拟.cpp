#include<cstdio>
#define maxn 100010
int sweet[maxn];
int acnt, bcnt;
int amark, bmark;
int tot;
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        amark = 1; bmark = n;
        for (int i = 1; i <= n; ++i)scanf("%d", sweet + i);
        if (n == 1) { puts("1 0"); continue; }
        while (amark <= bmark && amark + n - bmark + 1 < n) {
            if (sweet[amark] > sweet[bmark]) {
                sweet[amark] -= sweet[bmark];
                --bmark;
                ++tot;
            }
            else if (sweet[bmark] > sweet[amark]) {
                sweet[bmark] -= sweet[amark];
                ++amark;
                ++tot;
            }
            else if (amark == bmark)amark++;
            else {
                sweet[bmark] = sweet[amark] = 0;
                ++amark, --bmark;
            }
        }
        printf("%d %d\n", amark, n - amark);
    }
}
