#include <stdio.h>
double f(int n)
{
    if (n <= 150)
        return n * 0.4463;
    else if (n <= 400)
        return 150 * 0.4463 + (n - 150) * 0.4663;
    else
        return 150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663;
}
int n;
int main()
{
    scanf("%d", &n);
    printf("%.3f", f(n));
}