#include <stdio.h>
int rd()
{
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f > 0 ? k : -k;
}
int a[1000010];
int main()
{
    int n = rd();
    for (int i = 1; i <= n; ++i)
        ++a[rd()];
    long long res = 1ll * n;
    for (int i = 2; i <= 1000000; ++i)
        for (int j = i; j <= 1000000; j += i)
            res += 1ll * a[j] * i;
    printf("%lld", res);
}