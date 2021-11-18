#include<stdio.h>
#include<math.h>
double X1, Y1, X2, Y2;
int main() {
    scanf("%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2);
    printf("%.2lf", sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1)));
}
