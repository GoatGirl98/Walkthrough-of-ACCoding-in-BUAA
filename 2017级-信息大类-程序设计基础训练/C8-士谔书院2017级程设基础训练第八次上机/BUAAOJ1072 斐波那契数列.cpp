#include <cstdio>
#define MAXN 45
int n;
int f[MAXN];
int main(){
    scanf("%d", &n);
    f[1] = 1;f[2] = 1;f[3] = 2;f[4] = 3;f[5] = 5;f[6] = 8;
    int i;
    for(i = 7; i <= n; ++ i){
        f[i] = f[i - 1] + f[i - 2] - f[i - 7];
    }
    printf("%d", f[n]);
    return 0;
}
