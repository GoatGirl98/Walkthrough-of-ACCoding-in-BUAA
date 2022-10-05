#include <stdio.h>

struct SPNUM
{
    unsigned long long son, mum;
};

struct SPNUM sum(struct SPNUM a, struct SPNUM b)
{
    struct SPNUM ans;
    ans.son = a.son * b.mum + a.mum * b.son;
    ans.mum = a.mum * b.mum;
    return ans;
}

struct SPNUM simple(struct SPNUM a)
{
    unsigned long long m = a.mum, n = a.son, r = 0;
    if (n > m)
    {
        r = m;
        m = n;
        n = r;
    }
    // printf("sim\n");
    do
    {
        // printf("%d %d", m, n);
        r = m % n;
        m = n;
        n = r;
    } while (n != 0);
    a.mum /= m;
    a.son /= m;
    return a;
}

int numLen(unsigned long long a)
{
    int ans = 0;
    while (a != 0)
    {
        a /= 10;
        ans++;
    }
    return ans;
}

int main()
{
    int n, i, lFront, lSon, lMum;
    unsigned long long front;
    struct SPNUM tmp, ans;
    while (scanf("%d", &n) != EOF)
    {

        ans.son = 0, ans.mum = 1;
        for (i = 1; i <= n; ++i)
        {
            tmp.son = n, tmp.mum = i;
            ans = sum(ans, tmp);
            ans = simple(ans);
        }

        // printf("%d %d\n", ans.son, ans.mum);

        front = ans.son / ans.mum;
        // printf("%d\n", front);
        ans.son %= ans.mum;
        if (ans.son == 0)
        {
            printf("%d\n", front);
        }
        else
        {
            ans = simple(ans);
            lFront = numLen(front);
            lSon = numLen(ans.son);
            lMum = numLen(ans.mum);
            for (i = 0; i < lFront; ++i)
            {
                putchar(' ');
            }
            printf("%llu\n", ans.son);
            printf("%llu", front);
            for (i = 0; i < lMum || i < lSon; ++i)
            {
                printf("-");
            }
            printf("\n");
            for (i = 0; i < lFront; ++i)
            {
                putchar(' ');
            }
            printf("%llu\n", ans.mum);
        }
        putchar('\n');
    }
}