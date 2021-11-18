#include <cstdio>
int main(){
    int i,n,t,a,b,c;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(!a&&!b&&!c)printf("0\n");
        else if(b<=c)printf("fail\n");
        else {
            t=1;
            while(a>b){
                a=a-b+c;
                t++;
            }
            printf("%d\n",t);
        }
    }
}
