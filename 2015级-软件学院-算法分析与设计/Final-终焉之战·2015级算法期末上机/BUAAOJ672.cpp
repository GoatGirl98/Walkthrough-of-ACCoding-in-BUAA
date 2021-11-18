#include<cstdio>
long long gcdCN(long long a, long long b) {
    int r = 0;//a和b的2^r形式的公因子
    while (!((a & 1) || (b & 1))) {
        //a和b都是偶数的时候
        a >>= 1; b >>= 1; r++;
    }
    
    while (1) {//首次到这里时，至少一奇
        while (!(a & 1))a >>= 1;//剔除a中的因子2
        while (!(b & 1))b >>= 1;//剔除b中的因子2
        (a > b) ? a = a - b : b = b - a;//简化为gcd(max(a,b)-min(a,b),min(a,b)) 可以证明这步的正确性
        if (0 == a) return b << r;//最后这步倒是和欧几里得做法类似
        if (0 == b) return a << r;
    }
}
long long a,b;
int main(){
    while(scanf("%lld%lld",&a,&b)!=EOF){
        printf("%lld\n",gcdCN(a,b));
    }
}
