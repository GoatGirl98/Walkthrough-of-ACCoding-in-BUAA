#include <cstdio>
#define MAXN 30
int n;
int mat[MAXN][MAXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main(){
    scanf("%d", &n);
    int i, j;
    int x = 0, y = n - 1, dir = 0;
    for(i = 1; i <= n * n; ++ i){
        mat[x][y] = i;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(!(0 <= nx && nx < n && 0 <= ny && ny < n) || mat[nx][ny]){
            
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
    }
    for(i = 0; i < n; ++ i){
        for(j = 0; j < n; ++ j){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
