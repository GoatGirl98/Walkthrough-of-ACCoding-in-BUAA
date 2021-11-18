#include<stdio.h>
int n;
int ans;
int main() {
    while (scanf("%d", &n)!=EOF) {
        ans = 0;
        while (n)n >>= 1, ans++;
        printf("%d\n", ans);
    }
}
