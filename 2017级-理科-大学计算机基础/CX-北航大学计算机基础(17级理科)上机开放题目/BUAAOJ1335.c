#include <stdio.h>
int a[40];
int n;
int main()
{
    scanf("%d", &n);
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= n; i++)
        a[i] = a[i - 1] + a[i - 2];
    printf("%d\n", a[n]);
}