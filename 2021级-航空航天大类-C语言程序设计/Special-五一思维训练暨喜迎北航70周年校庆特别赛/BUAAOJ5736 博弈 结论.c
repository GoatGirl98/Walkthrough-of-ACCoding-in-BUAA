#include <stdio.h>
int x[4];
int main()
{
    scanf("%d%d%d", &x[1], &x[2], &x[3]);
    puts(x[1] + x[2] == x[3] ? "L0SE" : "W1N");
}