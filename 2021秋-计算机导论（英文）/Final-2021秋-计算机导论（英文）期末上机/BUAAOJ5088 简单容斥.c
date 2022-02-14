#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
typedef struct rect { double xl, yl, xr, yr; } rect;
rect intersect(rect a, rect b)
{
    double x_min = max(a.xl, b.xl), x_max = min(a.xr, b.xr);
    double y_min = max(a.yl, b.yl), y_max = min(a.yr, b.yr);
    if (x_min >= x_max || y_min >= y_max)
        return (rect){0, 0, 0, 0};
    else
        return (rect){x_min, y_min, x_max, y_max};
}
double area(rect a)
{
    return (a.xr - a.xl) * (a.yr - a.yl);
}
rect a[3];
int main()
{
    for (int i = 0; i < 3; ++i)
        scanf("%lf%lf%lf%lf", &a[i].xl, &a[i].yl, &a[i].xr, &a[i].yr);
    printf("%.2f", area(a[0]) + area(a[1]) + area(a[2]) - area(intersect(a[0], a[1])) - area(intersect(a[1], a[2])) - area(intersect(a[0], a[2])) + area(intersect(intersect(a[0], a[1]), a[2])));
}