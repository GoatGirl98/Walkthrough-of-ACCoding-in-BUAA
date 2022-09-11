#include <stdio.h>
#define MAXN 100010
int n, m;
int a[MAXN], b[MAXN];
int main(){
    scanf("%d%d", &n, &m);
    int i, j;
    for(i = 0; i < n; ++ i){
        scanf("%d", a + i);
    }
    for(i = 0; i < m; ++ i){
        scanf("%d", b + i);
    }
    for(i = 0, j = 0; i < n && j < m; ++ i, ++ j){
        while(i < n && a[i] != b[j]){
            ++ i;
        }
        if(i == n){
            break;
        }
    }
    puts(j == m ? "TAK" : "NIE");
    return 0;
}
