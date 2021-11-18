#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int i,n,h,us,ds,g,t,sum,d;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        sum=0;t=0;
        scanf("%d%d%d%d",&h,&us,&ds,&g);
        if(us<min(h,min(ds,g)))printf("fail\n");
        else{
            while(sum<h){
                t++;
                sum+=us;
                d=sum%g;
                if(sum>=h)break;
                if(d<ds)sum-=d;
                else sum-=ds;
            }
            printf("%d\n",t);
        }
    }
}
