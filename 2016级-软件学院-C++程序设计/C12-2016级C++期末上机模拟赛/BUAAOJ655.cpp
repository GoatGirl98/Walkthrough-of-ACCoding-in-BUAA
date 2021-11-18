#include<cstdio>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define maxn 105
typedef unsigned long long ull;
inline ull solve(ull x) {
    ull lo = 0, hi = 1073741824, mi;
    x <<= 1;
    hi <<= 1;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (mi * mi + mi < x) { if (mi == lo)return lo; lo = mi;}
        else if (mi * mi + mi > x)hi = mi;
        else return mi - 1;
    }
    return lo;
}
int main() {
    ull x, n, m;
    scanf("%llu", &x);
    n = solve(x);
    if (n % 2) {
        m = x - n * ((n + 1) >> 1);
        printf("%llu/%llu", m, n + 2 - m);
    }
    else {
        m = x - (n >> 1) * (n + 1);
        printf("%llu/%llu", n + 2 - m, m);
    }
}
