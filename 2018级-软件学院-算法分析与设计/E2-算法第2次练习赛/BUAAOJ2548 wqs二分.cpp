#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
typedef long long ll;
using namespace std;

ll maxProfit(int k, const vector<ll> &prices)
{
    if (prices.empty())
        return 0;

    int n = prices.size();
    // 二分查找的上下界
    ll left = 1, right = *max_element(prices.begin(), prices.end());
    // 存储答案，如果值为 -1 表示二分查找失败
    ll ans = -1;
    while (left <= right)
    {
        // 二分得到当前的斜率（手续费）
        ll c = (left + right) >> 1;
        ll buyCount = 0, sellCount = 0;
        ll buy = -prices[0], sell = 0;

        for (int i = 1; i < n; ++i)
        {
            if (sell - prices[i] >= buy)
            {
                buy = sell - prices[i];
                buyCount = sellCount;
            }
            if (buy + prices[i] - c >= sell)
            {
                sell = buy + prices[i] - c;
                sellCount = buyCount + 1;
            }
        }
        // 如果交易次数大于等于 k，那么可以更新答案
        // 这里即使交易次数严格大于 k，更新答案也没有关系，因为总能二分到等于 k 的
        if (sellCount >= k)
            // 别忘了加上 kc
            ans = sell + k * c, left = c + 1;
        else
            right = c - 1;
    }

    // 如果二分查找失败，说明交易次数的限制不是瓶颈
    // 可以看作交易次数无限，直接使用贪心方法得到答案
    if (ans == -1)
    {
        ans = 0;
        for (int i = 1; i < n; ++i)
            ans += max(prices[i] - prices[i - 1], 0ll);
    }
    return ans;
}

vector<ll> a;
int n, k;
char eof_flag;
char rd(int *s)
{
    if (eof_flag)
        return 0;
    int k = 0, f = 1;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
    {
        if (c == EOF)
        {
            eof_flag = 1;
            return 0;
        }
        c = getchar();
    }
    f = (c == '-') ? -1 : 1;
    k = (c == '-') ? 0 : (c ^ 48);
    c = getchar();
    while (c >= '0' && c <= '9')
        k = (k << 1) + (k << 3) + (c ^ 48), c = getchar();
    if (c == EOF)
        eof_flag = 1;
    (*s) = f > 0 ? k : -k;
    return 1;
}
void wr(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
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
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
int main()
{
    while (rd(&n) && rd(&k))
    {
        a.resize(n);
        for (int i = 0; i < n; ++i)
            a[i] = rd();
        wr(maxProfit(k, a)), putchar('\n');
    }
}
