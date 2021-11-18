#include<cstdio>
#include<cmath>
typedef long long ll;
int main()
{
    int n, k, bar;
    int a[100001], b[100001];
    while((scanf("%d%d", &n, &k)) != EOF)
    {
        ll ans = 1;
        ll full = pow(10, k);
        int t;
        bar = n / k;
        for(int i = 0; i < bar; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < bar; i++)
            scanf("%d", &b[i]);
        for(int i = 0; i < bar ; i++)
        {
            bool flag = false;
            ll same;
            if(full % a[i] == 0)
                t = full / a[i];
            else
                t = full / a[i] + 1;
            for(ll j = b[i] * full / 10; j * 10 / full == b[i]; j++)
            {
                if(j % a[i] == 0)
                {
                    flag = true;
                    same = j;
                    break;
                }
            }
            ll end = (b[i] + 1) * full / 10 - 1;
            if(flag)
            {
                ll x = end - same;
                t -= (x / a[i] + 1);
            }
            ans = (ans * t) % 1000000007;
        }
        printf("%d\n", ans);
    }
    return 0;
}
