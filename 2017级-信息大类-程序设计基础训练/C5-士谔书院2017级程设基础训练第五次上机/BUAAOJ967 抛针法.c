#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-8
#define maxn 1e8
double n;
long long cnt1, cnt2;
int main() {
    srand(NULL);
    scanf("%lf", &n);
    double x, y;
    for(int i = 0; i < maxn; ++i) {
        x = eps + (double)(n * rand() / RAND_MAX);
        y = (double) rand() / RAND_MAX;
        if(y <= sin(x)/ x)++cnt1;
        ++cnt2;
    }
    printf("%.3lf\n",cnt1 * n / cnt2);
}
