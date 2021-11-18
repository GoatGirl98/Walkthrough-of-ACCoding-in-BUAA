#include <cstdio>
#define MAXN 5010
int a[MAXN], cnt;
void dfs(int n, int k){
    a[cnt ++] = n;
    if(!k) return;
    dfs(2 * n, k - 1);
    dfs(3 * n + 1, k - 1);
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    dfs(2 * n, k - 1);
    dfs(3 * n + 1, k - 1);
    int i, j;
    //冒泡排序
    for(i = 0; i < cnt -1; ++ i){
        for(j = i + 1; j < cnt; ++ j){
            if(a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    //去重输出
    printf("%d ", a[0]);
    for(i = 1; i < cnt; ++ i){
        if(a[i] != a[i - 1]){
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    return 0;
}
