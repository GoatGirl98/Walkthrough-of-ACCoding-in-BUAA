#include <stdio.h>
#define MAXN 205
int a[MAXN];
int main(){
    int test;
    scanf("%d", &test);
    while(test --){
        int n, i, j;
        scanf("%d", &n);
        for(i = 0; i < n; ++ i){
            scanf("%d", &a[i]);
        }
        for(i = 0; i < n - 1; ++ i){
            for(j = 0; j < n - i - 1; ++ j){
                if(a[j] > a[j + 1]){
                    int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                }
            }
        }
        int x = a[n / 2];
        int ret = 0;
        for(i = 0; i < n; ++ i){
            int lalala = a[i] - x;
            ret += lalala > 0 ? lalala : - lalala;
        }
        printf("%d\n", ret);
    }
    return 0;
}
