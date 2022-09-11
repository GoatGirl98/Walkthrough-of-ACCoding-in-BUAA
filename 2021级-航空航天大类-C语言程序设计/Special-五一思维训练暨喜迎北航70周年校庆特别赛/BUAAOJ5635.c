#include <stdio.h>
#include <math.h>
double x, y, a, b;
int main()
{
    while (scanf("%lf%lf%lf%lf", &x, &y, &a, &b) != EOF)
        printf("%.15f\n", x + (1 - sqrt(2) / 2) * a);
}