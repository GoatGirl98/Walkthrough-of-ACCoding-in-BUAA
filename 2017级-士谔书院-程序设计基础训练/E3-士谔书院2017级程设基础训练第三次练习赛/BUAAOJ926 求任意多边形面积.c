#include<stdio.h>
#include<math.h>
int n;
double b, stx, sty, lstx, lsty, nowx, nowy, s;

int main() {
    scanf("%d", &n);
    scanf("%lf %lf", &lstx, &lsty);
    stx = lstx, sty = lsty;
    for (int i = 2; i <= n; ++i) {
        scanf("%lf%lf", &nowx, &nowy);
        s += (lstx * nowy - nowx * lsty);
        lstx = nowx, lsty = nowy;
    }
    nowx = stx, nowy = sty;
    s += (lstx * nowy - nowx * lsty);
    printf("%.3f\n", fabs(0.5 * s));
    return 0;
}
