#include <cstdio>
bool vis[10];
int main(){
    int step, now = 9;
    for(step = 1; step <= 1000; ++ step){
        now = (now + step) % 10;
        vis[now] = true;
    }
    int i;
    for(i = 0; i < 10; ++ i){
        if(!vis[i]){
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    return 0;
}
