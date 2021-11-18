#include<stdio.h>
int main() {
    int a, b;
    scanf("%d%d", &a,&b);
    if (b == 0)puts("ERROR. The divisor is ZERO.");
    else printf("%d div %d = %d ... %d", a, b, a / b, a % b);
}
