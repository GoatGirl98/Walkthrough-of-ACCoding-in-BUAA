#include<cstdio>
#include<cmath>
double x, y, a, b, c;
int main() {
    scanf("%lf%lf%lf%lf%lf", &x, &y, &a, &b, &c);
    printf("%.3f", fabs(x * a + y * b + c) / sqrt(a * a + b * b));
}
