#include<cstdio>
long long ack(long long m, long long n){
    if(m==0)return (n+1);
    else if (n==0)return ack(m-1,1);
    else return ack(m-1,ack(m,n-1));
}
long long a,b;
int main(){
    while(scanf("%lld%lld",&a,&b)!=EOF)
        printf("%lld\n",ack(a,b));
}
