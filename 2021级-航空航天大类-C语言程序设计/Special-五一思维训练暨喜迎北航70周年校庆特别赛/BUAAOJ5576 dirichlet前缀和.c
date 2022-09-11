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
long long ans;
unsigned prime[1000010], cnt;
unsigned dirichlet[1000010];
char vis[1000010];
void get_prime(unsigned n)
{
    vis[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && prime[j] * i <= n; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void get_dirichlet(unsigned n)
{
    for (int i = 1; i <= n; ++i)
        dirichlet[i] = i;
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j * prime[i] <= n; j++)
            dirichlet[prime[i] * j] += dirichlet[j];
}
int main()
{
    get_prime(1000000);
    get_dirichlet(1000000);
    int n = rd();
    while (n--)
        ans += dirichlet[rd()];
    printf("%lld", ans);
}