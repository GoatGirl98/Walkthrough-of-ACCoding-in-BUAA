#include <stdio.h>
int n;
int main()
{
    scanf("%d", &n);
    while (n ^ 1)
        n = (n & 1) ? (3 * n + 1) : (n >> 1), printf("%d\n", n);
}