#include<cstdio>
int n,m,k;
int main(){
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        printf("%lld\n",((long long)n*2+(long long)(k)*m)*((long long)k+1)/2);
    }
    
}
