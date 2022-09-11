#include <stdio.h>
typedef long long ll;
ll rd()
{
    ll k = 0, f = 1;
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
ll ans_sum, ans_cnt;
ll a[100010];
int n;
int main()
{
    n = rd();
    for (int i = 1; i <= n; ++i)
        a[i] = a[i - 1] + rd();
    ans_sum = 0, ans_cnt = 1;
    for (int i = 2; i <= n; ++i)
    {
        ll tmp_sum = a[i] - a[i - 2], tmp_cnt = 2;
        if (ans_sum * tmp_cnt < tmp_sum * ans_cnt)
            ans_sum = tmp_sum, ans_cnt = tmp_cnt;
    }
    for (int i = 3; i <= n; ++i)
    {
        ll tmp_sum = a[i] - a[i - 3], tmp_cnt = 3;
        if (ans_sum * tmp_cnt < tmp_sum * ans_cnt)
            ans_sum = tmp_sum, ans_cnt = tmp_cnt;
    }
    printf("%.4f", (double)ans_sum / (double)ans_cnt);
}