#include <stdio.h>
#include <string.h>
#include <math.h>
const double pi = acos(-1.0);
const double e = exp(1.0);
typedef long long ll;
#define maxn 1010
char s[maxn];
int a[maxn], real_a;
const int mod[20] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2};
ll factorial_digit(int n)
{
    if (n == 1)
        return 1ll * 1;
    return (ll)((1ll * log10(2 * pi * n) * 0.5 + 1ll * n * log10(n / e)) + 1ll * 1);
}

int last_digit_of_factorial(char *buf)
{
    int len = strlen(buf), ret = 1, i = 0, j = 0;

    for (i = 0; i < len; i++)
        a[i] = buf[len - 1 - i] - '0';

    a[len] = '\0';

    while (len)
    {
        len -= !a[len - 1];
        ret = ret * mod[a[1] % 2 * 10 + a[0]] % 10;

        for (j = 0, i = len - 1; i >= 0; i--)
            j = j * 10 + a[i], a[i] = j / 5, j %= 5;
    }

    return ret;
}
int main()
{
    while (scanf("%s", s) != EOF)
        sscanf(s, "%d", &real_a), printf("%d %d\n", factorial_digit(real_a), last_digit_of_factorial(s));
}