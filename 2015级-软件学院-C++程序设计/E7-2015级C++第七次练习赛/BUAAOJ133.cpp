#include <cstdio>
int main(){
    int n,cnt;
    while(scanf("%d",&n)!=EOF){
        cnt=0;
       for(int i = 0; i < n; ++i) {
            if(i&1){
                cnt+=n;
                for(int i = 0; i < n; ++i)printf("%4d",cnt--);
                cnt+=n;
            }
            else for(int i = 0; i < n; ++i)printf("%4d",++cnt);
            putchar('\n');
        }
        putchar('\n');
    }
}
