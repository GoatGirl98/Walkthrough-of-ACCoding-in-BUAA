#include <cstdio>
int check(int x, int a, int b){
    return x % a == b;
}
int main(){
    int a, b, c, x, y, z;
    scanf("%d%d%d%d%d%d", &a, &x, &b, &y, &c, &z);
    int i;
    for(i = 2; ; ++ i){
        if(check(i, a, x) && check(i, b, y) && check(i, c, z)){
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
