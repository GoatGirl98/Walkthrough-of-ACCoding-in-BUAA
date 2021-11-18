#include<cstdio>
#define maxn 5000010
int tmpint;
int n;
int ans;
int main() {
    while (scanf("%d", &n) != EOF) {
        ans = 0;
        for(int i = 0; i < 2*n-1; ++i) {
            scanf("%d", &tmpint);
            ans ^= tmpint;
        }
        printf("%d\n", ans);
    }
}
