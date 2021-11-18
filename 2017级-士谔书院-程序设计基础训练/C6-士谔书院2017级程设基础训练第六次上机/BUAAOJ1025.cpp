#include<cstdio>
#define N 10
int main() {
    double a[N],sum=0,ave;
    int i,n=0;
    for(i=0;i<N;i++)
        scanf("%lf",&a[i]);
    for(i=0;i<N;i++)
        sum+=a[i];
    ave=sum/10.0;
    for(i=0;i<N;i++)
        if(a[i]>ave)
            n++;
    printf("%.3lf\n",ave);
    printf("%d\n",n);
    return 0;
}
