#include <stdio.h>
unsigned seed;
long long a, b;
long long ans = 0;
long long n;
char i;
char op;
char scheme[35];
int main()
{
    scanf("%lld%u", &n, &seed);
    for (i = 0; i <= 31; ++i)
        scanf("%d", &scheme[i]);
    while (n--)
    {
        seed ^= seed << 13U;
        seed ^= seed >> 17U;
        seed ^= seed << 5U;
        op = scheme[seed & 31] & 31;
        a = n ^ 1145141919810ll;
        b = n ^ 1919810114514ll;
        switch (op)
        {
        case 0:
            ans += a + b;
            break;
        case 1:
            ans += a - b;
            break;
        case 2:
            ans += a * b;
            break;
        case 3:
            ans += a / b;
            break;
        case 4:
            ans += a % b;
            break;
        case 5:
            ans += a & b;
            break;
        case 6:
            ans += a | b;
            break;
        case 7:
            ans += a ^ b;
            break;
        case 8:
            ans -= a ^ b;
            break;
        case 9:
            ans -= a | b;
            break;
        case 10:
            ans -= a & b;
            break;
        case 11:
            ans -= a % b;
            break;
        case 12:
            ans -= a / b;
            break;
        case 13:
            ans -= a * b;
            break;
        case 14:
            ans -= a - b;
            break;
        case 15:
            ans -= a + b;
            break;
        case 16:
            ans &= a * b;
            break;
        case 17:
            ans &= a / b;
            break;
        case 18:
            ans &= a + b;
            break;
        case 19:
            ans &= a - b;
            break;
        case 20:
            ans &= a | b;
            break;
        case 21:
            ans &= a ^ b;
            break;
        case 22:
            ans &= a % b;
            break;
        case 23:
            ans &= a & b;
            break;
        case 24:
            ans ^= a / b;
            break;
        case 25:
            ans ^= a * b;
            break;
        case 26:
            ans ^= a - b;
            break;
        case 27:
            ans ^= a + b;
            break;
        case 28:
            ans ^= a ^ b;
            break;
        case 29:
            ans ^= a | b;
            break;
        case 30:
            ans ^= a & b;
            break;
        case 31:
            ans ^= a % b;
            break;
        }
    }
    printf("%lld", ans);
    return 0;
}