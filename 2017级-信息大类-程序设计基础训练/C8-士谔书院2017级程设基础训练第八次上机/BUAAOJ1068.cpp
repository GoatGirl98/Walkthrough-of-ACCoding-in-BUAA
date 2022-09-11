#include <cstdio>
const int mod = 1e7 + 7;
int main()
{
    int t,n;
    scanf("%d",&t);
    long long ans ;
    while (t--)
    {
        ans = 1;
        scanf("%d",&n);
        if (n % 2 == 0)
        {
            for (int i = 2; i <= n; i = i + 2)
            {
                ans = (ans % mod * i % mod) % mod;
            }
        }
        else
        {
            for (int i = 1; i <= n; i = i + 2)
            {
                ans = (ans % mod * i % mod) % mod;
            }
        }
        printf("%lld\n",ans);
    }
}
