#include<cstdio>
int a[40];
inline void init(){
    a[0]=0;a[1]=1;a[2]=2;a[3]=4;
    for(int i = 4;i<=36;i++)a[i]=a[i-1]+a[i-2]+a[i-3];
}
int T,n;
int main(){
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
}
