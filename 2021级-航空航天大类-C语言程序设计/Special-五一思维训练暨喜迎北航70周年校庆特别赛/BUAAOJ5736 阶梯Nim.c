#include <stdio.h>
#define N 1010
int T;
int n;
int a[N], b[N];
int main()
{
    T = 1;
    while (T--)
    {
        n = 3;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            b[n - i + 1] = a[i] - a[i - 1] - 1;
        for (int i = 1; i <= n; i += 2)
            ans ^= b[i];
        long long step = (ans ? 1 : 0) + ((1ll * n * (n + 1)) >> 1);
        
        puts((step & 1) ? "W1N" : "L0SE");
    }
}
