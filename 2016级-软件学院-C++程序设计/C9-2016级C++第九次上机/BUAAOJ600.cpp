#include<cstdio>
#define RADIX 256
typedef unsigned long long ull;
inline void write(ull x) {
    if (x >= RADIX)write(x / RADIX);
    putchar(x % RADIX);
}
int main() {
    ull n; scanf("%llu", &n); write(n);
}
