#include<cstdio>
#include<cctype>
long long gcd(long long a, long long b) {
    int r = 0;
    while (!((a & 1) || (b & 1))) {
        a >>= 1; b >>= 1; r++;
    }
    
    while (1) {
        while (!(a & 1))a >>= 1;
        while (!(b & 1))b >>= 1;
        (a > b) ? a = a - b : b = b - a;
        if (0 == a) return b << r;
        if (0 == b) return a << r;
    }
}

int main() {
    long long a,b;
    long long gcd1;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        printf("%lld\n",a*b/gcd(a,b));
    }
    
    return 0;
}
