#include<stdio.h>
#include<string.h>
int s[400010];
int m;
int p, q;
int a, b;
int i;
int main() {
    while(scanf("%d%d%d", &m, &p, &q) != EOF) {
        memset(s, 0, sizeof(s));
        while(m--) {
            scanf("%d%d", &a, &b);
            s[a]++, s[b+1]--;
        }
        for(i = p; i <= q; ++i) {
            s[i] += s[i - 1];
            if(!s[i]) {
                printf("%d\n", i);
                break;
            }
        }
        if(i > q) puts("War,war never changes.");
    }
}
