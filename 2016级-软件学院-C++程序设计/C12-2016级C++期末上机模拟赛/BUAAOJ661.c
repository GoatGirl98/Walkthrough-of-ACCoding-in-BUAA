#include <stdio.h>
#include <math.h>
int s, t, a, b;
// s *(1 - a%) ^ T1 * (1 - b%) = t
// s *(1 - a %) ^ T2 = t (when T1 < 0) 
double calc(int s, int t, int a, int b)
{
    double T1 = log((1.0 * t) / ((1.0 - b / 100.0) * s)) / log(1.0 - a / 100.0);
    double T2 = log((1.0 * t) / s) / log(1.0 - a / 100.0);
    return T1 < 0 ? T2 : T1;
}
int main()
{
    scanf("%d%d%d%d", &s, &t, &a, &b);
    printf("%.1f", calc(s, t, a, b));
}