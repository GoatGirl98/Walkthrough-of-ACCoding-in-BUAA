#include <cstdio>
#define MAXN 310
int n;
int mat[MAXN][MAXN];
inline bool check(int x, int y){
    int i;
    for(i = 0; i < n; ++ i){
        //检验是否为行严格最小
        if(i != y && mat[x][i] <= mat[x][y]){
            return 0;
        }
        //检验是否为列严格最大
        if(i != x && mat[i][y] >= mat[x][y]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i){
        for(j = 0; j < n; ++ j){
            scanf("%d", mat[i] + j);
        }
    }
    for(i = 0; i < n; ++ i){
        for(j = 0; j < n; ++ j){
            if(check(i, j)){
                printf("%d %d %d\n", i + 1, j + 1, mat[i][j]);
                return 0;
            }
        }
    }
    puts("NIE");
    return 0;
}
