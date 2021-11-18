#include<cstdio>
#define maxn 5000010
int tmpint;
int n;
int ans;
int main() {
    while (scanf("%d", &n) != EOF) {
        n = 2 * n - 1;
        ans = 0;
        while(n--) {
            scanf("%d", &tmpint);
            ans ^= tmpint;
        }
        printf("%d\n", ans);
    }
}
