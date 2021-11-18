#include<cstdio>
#include<cstring>
int main()
{
    int n, a[101], b[101], ans = 0;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    for(i = 0; i < n; i++)
    {
        int x = a[i] ^ b[i];
        while(x != 0)
        {
            if(x % 2 != 0)
                ans++;
            x /= 2;
        }
    }
    printf("%d", ans);
}
