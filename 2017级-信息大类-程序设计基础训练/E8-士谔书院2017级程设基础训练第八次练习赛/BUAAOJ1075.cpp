#include <stdio.h>
#define mod 1000000007
typedef long long ll;
int main(){
    int test;
    scanf("%d", &test);
    while(test --){
        int n;
        scanf("%d", &n);
        ll ret = 0, now = 1;
        int i;
        for(i = 1; i <= n; ++ i){
            now = now * i % mod;
            ret += now;
            if(ret >= mod){
                ret -= mod;
            }
        }
        printf("%lld\n", ret);
    }
    return 0;
}
