#include <stdio.h>
int main()
{
    unsigned long long a, b, c, d;
    int i, j, r, flag;
    //x,y,sum用来储存128位数据的每一位，以0位为最低位
    int x[128] = {0}, y[128] = {0}, sum[129] = {0}, num[50] = {0};
    scanf("%llu%llu%llu%llu", &a, &b, &c, &d);
    for (i = 0; i < 64; i++)
    {
        //把 x 转化成 2 进制数
        x[i+64] = a % 2;
        a /= 2;
        x[ i] = b % 2;
        b /= 2;
        //把 y 转化成 2 进制数
        y[i+64] = c % 2;
        c /= 2;
        y[ i] = d % 2;
        d /= 2;
    }
    // 将两个数求和（以三位二进制数为例，111+111=1110，所以和比加数最多多一位）
    // 为了防止数组溢出，我们将sum定义为长度129，但是sum[128]其实不存在，它溢出了。
    for (i = 0; i <= 127; i++)
    {
        sum[i] += x[i] + y[i]; // sum的第k位等于xy第k位的和
        // printf("%d:", sum[i]);
        sum[i + 1] += sum[i] / 2; // sum是二进制数，所以如果某一位大于等于二，需要进位
        sum[i] %= 2;
        // printf("%d ", sum[i]);
    }
    sum[128] = 0; // 将溢出的位去掉

    if (sum[127] == 1) //如果是负数，要将补码变为相反数（正数）（-a=~a+1）
    {
        putchar('-');
        // 先取反
        for (i = 0; i <= 127; i++)
        {
            sum[i] = 1 - sum[i];
        }
        sum[0]++; //再加一
        // 进位
        for (i = 0; i <= 127; i++)
        {
            sum[i + 1] += sum[i] / 2;
            sum[i] %= 2;
        }
    }
    // 使用秦九韶算法将二进制
    for (i = 128; i >= 0; i--)
    {
        for (j = 0; j <= 49; ++j)
        {
            num[j] *= 2;
        }
        num[0] += sum[i];
        for (j = 0; j <= 49; j++)
        {
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
        }
    }

    // 找出该从哪位开始输出，如果是0或个位数，都是从第0位开始输出
    for (j = 49; j >= 1; j--)
    {
        if (num[j] != 0)
        {
            break;
        }
    }
    // 输出
    for (i = j; i >= 0; i--)
    {
        printf("%d", num[i]);
    }
}
