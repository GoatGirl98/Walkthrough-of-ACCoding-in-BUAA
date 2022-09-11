#include<cstdio>
int a[110];
inline void init(){
    a[0]=a[1]=a[2]=a[3]=a[4]=1;
    for(int i = 5;i<101;++i)
        a[i]=(a[i-1]+a[i-4])%10000007;
    
}
int n;
int main(){
    init();
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",a[n]);
}
