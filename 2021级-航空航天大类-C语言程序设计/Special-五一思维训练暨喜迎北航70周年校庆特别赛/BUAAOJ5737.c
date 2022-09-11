#include <stdio.h>
#include <math.h>
const double eps = 1e-8;
int t, n;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if (n % 2)
            puts("NO");
        else
        {
            int len = (int)(sqrt(n / 2) + eps);
            int len2 = (int)(sqrt(n / 4) + eps);
            puts((len * len == n / 2 || (n % 4 == 0 && len2 * len2 == n / 4)) ? "YES" : "NO");
        }
    }
}