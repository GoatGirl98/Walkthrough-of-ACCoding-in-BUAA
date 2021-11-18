#include <cstdio>
#define MAXN 105
int mat[MAXN][MAXN];
void solve(){
    //now 记录下一个未填写的数字
    int k, i, j, now = 1;
    //从小到大枚举每条副对角线的编号k
    for(k = 0; k < 100; ++ k){
        if(k & 1){
            //如果是奇数编号，那么从左下到右上
            for(i = k, j = 0; i >= 0; -- i, ++ j){
                mat[i][j] = now ++;
            }
        }
        else{
            //如果是偶数编号，那么从右上到左下
            for(i = 0, j = k; j >= 0; ++ i, -- j){
                mat[i][j] = now ++;
            }
        }
    }
}
int main(){
    //预处理n = 100 的答案
    solve();
    int test;
    scanf("%d", &test);
    while(test --){
        int n;
        scanf("%d", &n);
        int i, j;
        //输出大小为n 的子三角形
        for(i = 0; i < n; ++ i){
            for(j = 0; i + j < n; ++ j){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
