#include <stdio.h>
typedef long long ll;
ll l, r, m;
int T;
// ans[i] : \sum_{x=1}^n f(x, i), f(x, i) = ((x & (1 << (i - 1))) > 0)
void count_of_one(ll n, ll ans[])
{
    for (int i = 1; i < 63; ++i)
        ans[i] = 0;
    for (ll i = 1, f = 2, b = 1; b <= n; ++i, f <<= 1, b <<= 1)
    {
        ans[i] = (n / f) * (f >> 1);
        if (n % f >= b)
            ans[i] += (n % f - b + 1);
    }
}
ll a_one[64], b_one[64], c_one[64], d_one[64];
ll a_to_b[2][64], c_to_d[2][64];
// time complexity : O(log n)
// \sum_{i=a}^b \sum_{j=c}^d i\xor j
ll solve(ll a, ll b, ll c, ll d)
{
    ll ret = 0;
    count_of_one(a - 1, a_one), count_of_one(b, b_one);
    count_of_one(c - 1, c_one), count_of_one(d, d_one);
    for (int i = 1; i < 63; ++i)
        a_to_b[1][i] = b_one[i] - a_one[i], c_to_d[1][i] = d_one[i] - c_one[i];
    for (int i = 1; i < 63; ++i)
        a_to_b[0][i] = (b - a + 1) - a_to_b[1][i], c_to_d[0][i] = (d - c + 1) - c_to_d[1][i];
    for (int i = 1; i < 63; ++i)
        ret += (a_to_b[1][i] * c_to_d[0][i] + a_to_b[0][i] * c_to_d[1][i]) * (1ll << (i - 1));
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &l, &r, &m);
        printf("%lld\n", solve(l, r, m, m));
    }
}