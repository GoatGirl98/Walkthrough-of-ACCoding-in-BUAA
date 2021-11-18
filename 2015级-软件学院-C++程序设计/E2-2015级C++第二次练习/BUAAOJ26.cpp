#include <cstdio>
#include <cmath>
int main(){
    int x,y,z,a,b,c;
    double max,t;int n,i,k,maxi;
    while(scanf("%d%d%d%d",&x,&y,&z,&n)==4){
        max=0;maxi=1;
        for(i=0;i<n;i++){
            scanf("%d%d%d",&a,&b,&c);
            t=(a-x)*(a-x)+(b-y)*(b-y)+(c-z)*(c-z);
            if(t>max){max=t;maxi=i+1;}
        }
        scanf("%d",&k);printf("%d %lf\n",maxi,k*2*sqrt(max));
    }
}
