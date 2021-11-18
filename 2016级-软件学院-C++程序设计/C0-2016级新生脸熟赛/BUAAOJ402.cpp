#include<stdio.h>
typedef long long ll;
typedef unsigned long long ull;
inline ull AmulBmodP(ull a, ull b, ull p) {
    ull c = (long double)a / p * b;
    ull ret = (ull)a * b - (ull)c * p;
    ret %= p;
    while(ret < 0) ret += p;
    return ret % p;
}
ull t,a,b,p;
int main() {
    scanf("%llu", &t);
    while (t--) {
        scanf("%llu%llu%llu", &a, &b, &p);
        printf("%llu\n", AmulBmodP(a, b, p));
    }
}
