#include<stdio.h>
unsigned x;
int main() {
    while (scanf("%u", &x) != EOF)
        printf("%u\n", ((x & 0x0000ffff) << 16) | ((x & 0xffff0000) >> 16));
}