#include<cstdio>
#include<cctype>
long long step(long long n) {
    long long res = 0;
    while (1 != n) {
        (n & 1) ? n = 3 * n + 1 : n /= 2;
        ++res;
    }
    return res;
}
int main() {
    long long n;
    
    while (scanf("%lld", &n) != EOF) {
        printf("%lld\n", step(n));
    }
    return 0;
}
