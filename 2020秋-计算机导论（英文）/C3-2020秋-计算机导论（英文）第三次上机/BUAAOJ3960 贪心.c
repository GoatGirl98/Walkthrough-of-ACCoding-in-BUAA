#include<stdio.h>
int T, n;
double x;
double sum, max;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        sum = max = 0.0;
        while(n--) {
            scanf("%lf", &x);
            sum += x;
            if(x > max) max = x;
        }
        if(sum - max < max) printf("%.1f\n", sum - max);
        else printf("%.1f\n", sum / 2);
    }
}
