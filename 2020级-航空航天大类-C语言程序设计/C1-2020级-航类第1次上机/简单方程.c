#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, r1, r2, delta, min, max;
    scanf("%lf%lf%lf", &a, &b, &c);

    delta = b * b - 4.0 * a * c;
    if (delta < 0)
    {
        printf("no real roots");
    }
    else
    {
        r1 = (-b + sqrt(delta)) / (2.0 * a);
        r2 = (-b - sqrt(delta)) / (2.0 * a);
        if (r1 < r2)
        {
            min = r1;
            max = r2;
        }
        else
        {
            min = r2;
            max = r1;
        }

        printf("%.6f %.6f", min, max);
    }

    return 0;
}