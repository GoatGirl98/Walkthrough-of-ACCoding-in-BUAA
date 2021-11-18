#include<cstdio>
double a,b;
int n;
int main(){scanf("%d",&n);while(n--){scanf("%lf%lf",&a,&b);if(b!=0.0)printf("%.2lf\n",a/b);else printf("Error!\n");}}
