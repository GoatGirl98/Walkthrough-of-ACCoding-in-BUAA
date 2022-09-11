#include <cstdio>
#include <cmath>
int main()
{
    int n;
    scanf("%d",&n);
    double x;
    while (n--)
    {
        scanf("%lf",&x);
        printf("%.2lf\n",asin(x / (1 + x)) * 2.33 +pow((x + 2), 3));
    }
}
