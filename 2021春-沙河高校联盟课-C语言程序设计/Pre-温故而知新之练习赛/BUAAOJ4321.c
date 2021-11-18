#include <stdio.h>
int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}
int main(void)
{
    int a,b;
    int lcm;
    scanf("%d%d",&a,&b);
    printf("%d\n",a*b/gcd(a,b));
    return 0;
}