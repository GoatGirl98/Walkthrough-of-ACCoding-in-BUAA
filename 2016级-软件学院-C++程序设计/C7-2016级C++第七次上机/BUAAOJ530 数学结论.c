#include <stdio.h>
int n, k;
double a[7];
double b[7];
void process(int n, int k)
{
    if (k >= 14)
        return (void) puts("16.67% 16.67% 16.67% 16.67% 16.67% 16.67%");
    for (int i = 1; i <= 6; ++i)
        a[i] = (i == n) ? 1.0 : 0.0;
    while (k--)
    {
        for (int i = 1; i <= 6; ++i)
            b[i] = 0.0;
        for (int i = 1; i <= 6; ++i)
            for (int j = 1; j <= 6; ++j)
                b[j] += (i == j || i + j == 7) ? 0.0 : 0.25 * a[i];
        for (int i = 1; i <= 6; ++i)
            a[i] = b[i];
    }
    for (int i = 1; i <= 6; ++i)
        printf("%.2f%%%c", a[i] * 100.0, i == 6 ? '\n' : ' ');
}
int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
        process(n, k);
}