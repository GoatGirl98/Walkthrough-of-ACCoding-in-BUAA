#include<stdio.h>

int num[1000005]={0};

int main(){
    int i,j,n,m,t,L,R,mid;
    scanf("%d %d",&n,&m);
    

    for(i=0;i<n;++i){
        scanf("%d",&num[i]);
    }

    while(m--){
        scanf("%d",&t);

        L=0,R=n-1;

        while (R>L)
        {
            mid=(L+R)/2;
            if(num[mid]>t){
                R=mid-1;
            }else if(num[mid]<t){
                L=mid+1;
            }else{
                R=mid;
            }
        }

        if(num[L]==t){
            printf("%d\n",L+1);
        }else{
            printf("-1\n");
        }
        
    }

}