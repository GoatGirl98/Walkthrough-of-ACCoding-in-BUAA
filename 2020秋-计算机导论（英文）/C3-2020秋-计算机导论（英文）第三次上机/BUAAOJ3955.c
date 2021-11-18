#include<stdio.h>
int m, b, h;
int ans;
int x;
int main() {
    scanf("%d%d%d", &m, &b, &h);
    b += h;
    while(m--) {
        scanf("%d", &x);
        if(x <= b)++ans;
    }
    printf("%d", ans);
}
