#include<stdio.h>
long long a, b;
int main() {
    scanf("%lld%lld", &a, &b);
    printf("%lld", a + b + a * b);
}