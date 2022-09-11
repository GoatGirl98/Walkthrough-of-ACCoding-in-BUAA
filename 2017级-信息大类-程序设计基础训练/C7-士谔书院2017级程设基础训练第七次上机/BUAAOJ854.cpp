#include<cstdio>
#define MAXN (110)
int n, m;
int mat[MAXN][MAXN];
int vis[MAXN][MAXN];
int main(){
    int test;
    scanf("%d", &test);
    while(test --){
        int i, j;
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; ++ i){
            for(j = 1; j <= n; ++ j){
                scanf("%d", mat[i] + j);
                vis[i][j] = 0;
            }
        }
        char opt[20];
        while(m --){
            int x1, y1, x2, y2, t;
            scanf("%s%d%d%d%d", opt, &x1, &y1, &x2, &y2);
            if(x1 > x2) t = x1, x1 = x2, x2 = t;
            if(y1 > y2) t = y1, y1 = y2, y2 = t;
            if(opt[0] == 'g'){
                for(i = x1; i <= x2; ++ i){
                    for(j = y1; j <= y2; ++ j){
                        if(vis[i][j]) continue;
                        vis[i][j] = 1;
                        mat[i][j] = (mat[i][j] * mat[i][j] + 233) % 1773;
                    }
                }
            }
            else if(opt[0] == 'n'){
                for(i = x1; i <= x2; ++ i){
                    for(j = y1; j <= y2; ++ j){
                        if(!vis[i][j]) continue;
                        mat[i][j] = (mat[i][j] != 0);
                    }
                }
            }
            else{
                for(i = x1; i <= x2; ++ i){
                    for(j = y1; j <= y2; ++ j){
                        printf("#%06X  ", mat[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        for(i = 1; i <= n; ++ i){
            for(j = 1; j <= n; ++ j){
                printf("%04d  ", mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
