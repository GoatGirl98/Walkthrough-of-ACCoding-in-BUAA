#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100010;
const ll INF = 1145141919810114514ll;
ll a[maxn], max_num;
ll ans;
int buycnt, sellcnt;
ll buy, sell;
int n, k;
inline void write(ll x)
{
    if (x < 0)
        putchar_unlocked('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline ll read()
{
    int k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
inline bool solve(ll c)
{
    buycnt = 0, sellcnt = 0;
    buy = -a[1], sell = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (sell - a[i] >= buy)
        {
            buy = sell - a[i];
            buycnt = sellcnt;
        }
        if (buy + a[i] - c >= sell)
        {
            sell = buy + a[i] - c;
            sellcnt = buycnt + 1;
        }
    }
    return sellcnt >= k;
}
ll solve_greedy()
{
    ll ret = 0;
    for (int i = 2; i <= n; ++i)
        ret += max(a[i] - a[i - 1], 0ll);
    return ret;
}
int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
    {
        ans = -INF, max_num = -INF;
        for (int i = 1; i <= n; ++i)
            scanf("%lld", a + i), max_num = max(a[i], max_num);
        ll lo = 1, mi = 1, hi = max_num;
        //选取至多k的时候,下界为1,上界为最大值进行wqs二分
        while (lo <= hi)
        {
            mi = (lo + hi) >> 1;
            if (solve(mi))
                ans = sell + k * mi, lo = mi + 1;
            else
                hi = mi - 1;
        }
        //二分查找失败,则说明不在上凸壳的右半部分,而在左半部分,直接视作交易次数无限,贪心解决
        if (ans == -INF)
            ans = solve_greedy();
        write(ans), putchar_unlocked('\n');
    }
}