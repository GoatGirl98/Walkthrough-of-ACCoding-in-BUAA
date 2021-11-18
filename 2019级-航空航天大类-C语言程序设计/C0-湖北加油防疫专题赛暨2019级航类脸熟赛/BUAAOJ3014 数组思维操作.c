#include<stdio.h>
#define maxn 200010
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
int n;
int i;
int f[maxn];
int ans;
char judge(int a, int b, int c) {
    char abc = f[a] <= f[b] && f[b] <= f[c];
    char bca = f[b] <= f[c] && f[c] <= f[a];
    char cab = f[c] <= f[a] && f[a] <= f[b];
    return abc || bca || cab;
}
int main() {
    n = rd();
    for(i = 1; i <= n; ++i)
        f[rd()] = i;
    int moved = 0, pre = 0, pi = -1;
    for(int i = n - 1; i; i = pre - 1) {
        pre = i;
        if(!moved) {
            while(f[pre] <= f[pre + 1] && pre) --pre;
            if(!pre)break;
            moved = 1, ++ans, pi = pre + 1;
        }
        else {
            if(!judge(pi, i, i + 1)) ++ans, pi = i + 1;
        }
    }
    printf("%d", ans);
}