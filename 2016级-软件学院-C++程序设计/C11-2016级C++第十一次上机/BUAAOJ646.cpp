#include<cstdio>
typedef unsigned long long ull;
int main()
{
    int n, i, j, ans = 0;
    ull a[20001];
    scanf("%d", &n);
    for(i = 0; i < n; i++)scanf("%llu", &a[i]);
    ull maybe;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(j == i) continue;
            else
            {
                maybe = a[i] + a[j];
                if((maybe & (maybe - 1)) == 0)
                    ans++;
            }
        }
    }
    printf("%d", ans);
}
