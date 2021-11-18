#include <cstdio>
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(!(m&1&&n&1)||(m==1&&n==1)||(m+n)&1)printf("ore\n");
        else printf("watashi\n");
    }
}
