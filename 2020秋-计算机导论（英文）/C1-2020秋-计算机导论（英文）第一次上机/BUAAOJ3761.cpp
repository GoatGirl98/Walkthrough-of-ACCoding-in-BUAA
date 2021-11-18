#include<cstdio>
int tmpint;
int n;
int ans;
int main() {
    n = 5;
    ans = 0;
    while(n--) {
        scanf("%d", &tmpint);
        ans ^= tmpint;
    }
    printf("%d\n", ans);
    
}
