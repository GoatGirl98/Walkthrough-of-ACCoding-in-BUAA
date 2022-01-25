#include <stdio.h>
int main()
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    if (a >= 0 && b >= 0)
    {
        unsigned long long int sum = a + b; // a+b可能超过long long最大值 故用必正的unsigned long long
        printf("%llu\n", sum);
    }
    else if (((a > 0 && b <= 0)) || ((a <= 0) && (b > 0)))
    {
        long long int sum = a + b; //因为一正一非正 故相加不会超过long long范围正常输出即可
        printf("%lld\n", sum);
    }
    else if (a == -9223372036854775808ll && b == -9223372036854775808ll)
    {
        printf("-18446744073709551616\n"); //特判 理由见上
    }
    else if (a <= 0 && b <= 0)
    { //因为特殊情况已经在上面被讨论 故剩下的可以放开手脚取相反数相加
        a = -a, b = -b;
        unsigned long long int sum = a + b;
        printf("-%llu\n", sum);
    }
    return 0;
}