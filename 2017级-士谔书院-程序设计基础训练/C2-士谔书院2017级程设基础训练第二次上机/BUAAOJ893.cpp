#include <cstdio>
int main()
{
    long long x;
    scanf("%lld",&x);
    if(x<1)
    {
        printf("%lld\n",x);
    }
    else if(x<10)
    {
        printf("%lld\n",2 * x - 3);
    }
    else
    {
        printf("%d\n",3 * x - 5);
    }
    return 0;
}
