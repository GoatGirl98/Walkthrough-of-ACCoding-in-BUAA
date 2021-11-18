#include<stdio.h>
typedef long long ll;
ll gcd(ll a, ll b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",a*b/gcd(a,b));
}
