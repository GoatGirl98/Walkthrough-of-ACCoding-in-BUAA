#include <stdio.h>
#include <math.h>
double a, b, x, y;
// T(n) = aT(n/b)+n^xlog^y(n)
void solve(double a, double b, double x, double y)
{
    double standard = log(a) / log(b), ex = y;
    if (fabs(x - standard) < 1e-9)
        ex += 1.0;
    else if (x > standard)
        standard = x;
    else
        ex = 0;
    if (fabs(standard) < 1e-9 && fabs(ex) < 1e-9)
        puts("1");
    else if (fabs(standard) < 1e-9)
    {
        if (fabs(ex - 1.0) < 1e-9)
            puts("log(n)");
        else
            printf("log^%.3f(n)\n", ex);
    }   
    else if(fabs(ex) < 1e-9)
    {
        if (fabs(standard - 1.0) < 1e-9)
            puts("n");
        else
            printf("n^%.3f\n", standard);
    }
    else 
    {
        if (fabs(standard - 1.0) < 1e-9)
            printf("n");
        else
            printf("n^%.3f", standard);

        if (fabs(ex - 1.0) < 1e-9)
            printf("log(n)");
        else
            printf("log^%.3f(n)", ex);
        putchar('\n');
    }
}
int main()
{
    while (scanf("%lf%lf%lf%lf", &a, &b, &x, &y) != EOF)
        solve(a, b, x, y);
}