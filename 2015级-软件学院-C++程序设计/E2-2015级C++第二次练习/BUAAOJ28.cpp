#include <cstdio>
int main(){
    int i,t,a,b,cnt,pi,ans[4]={153,370,371,407};scanf("%d",&t);
    for(i=0;i<t;i++){
        cnt=0;
        scanf("%d%d",&a,&b);
        for(pi=0;pi<4;pi++){if(a<=ans[pi]&&ans[pi]<=b)printf("%d ",ans[pi]),cnt++;}
        if(!cnt)printf("-1");
        printf("\n");
    }
}
