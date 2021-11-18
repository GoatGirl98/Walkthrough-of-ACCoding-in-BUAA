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
    long long t;
    long long a,b,c,d;
    long long child, mother;
    long long gcd1;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        mother = b * d;
        child = a * d + b * c;
        gcd1 = gcd(mother, child);
        printf("%lld %lld\n",child/gcd1,mother/gcd1);
    }
    
    return 0;
}
