#include <cstdio>
int main()
{
    int h,t,u,i;
    for (i = 100; i < 1000; ++i)
    {
        h = i / 100;
        t = i / 10 % 10;
        u = i % 10;
        if (i == h * h * h + t * t * t + u * u * u)
        {
            printf("%d\n", i);
        }
    }
}
