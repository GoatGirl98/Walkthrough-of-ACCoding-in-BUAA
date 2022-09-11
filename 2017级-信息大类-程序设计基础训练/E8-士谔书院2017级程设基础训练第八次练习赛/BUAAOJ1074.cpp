#include <stdio.h>
int abs(int a){
    return a > 0 ? a : -a;
}
int main(){
    int test;
    scanf("%d", &test);
    while(test --){
        int n, i, ret;
        scanf("%d", &n);
        scanf("%d", &ret);
        for(i = 1; i < n; ++ i){
            int x;
            scanf("%d", &x);
            if(abs(x - 233) < abs(ret - 233) || (abs(x - 233) == abs(ret - 233) && x < ret)){
                ret = x;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
