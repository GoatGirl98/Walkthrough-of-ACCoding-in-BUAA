#include <cstdio>
#include <cmath>
int main(){
    int n=1,x,l,ll=0,flag=1;
    scanf("%d",&x);
    while(~scanf("%d",&l)){
        if(x-l<=0){
            flag=0;
            if(x>l-x)printf("%d",n+1);
            else printf("%d",n);
            break;
        }
        ll=l;n++;x-=l;
    }
    if(flag)printf("%d",n);
}
