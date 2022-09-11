#include <stdio.h>
typedef long long ll;
typedef __int128 lll;

namespace Fac
{

    lll add(lll a, lll b, lll p) { return a + b >= p ? a + b - p : a + b; }
    lll mul(lll a, lll b, lll p) { return a * b % p; }
    lll qpow(lll x, lll n, lll p)
    {
        lll r = 1;
        while (n)
        {
            if (n & 1)
                r = mul(r, x, p);
            x = mul(x, x, p);
            n >>= 1;
        }
        return r;
    }

    lll mod;
    lll add(lll a, lll b) { return a + b >= mod ? a + b - mod : a + b; }
    lll mul(lll a, lll b) { return a * b % mod; }
    lll qpow(lll x, lll n)
    {
        lll r = 1;
        while (n)
        {
            if (n & 1)
                r = mul(r, x);
            x = mul(x, x);
            n /= 2;
        }
        return r;
    }

    lll s1[110][110];
    void init()
    {
        s1[0][0] = 1;
        for (int i = 1; i <= 50; i++)
            for (int j = 1; j <= i; j++)
                s1[i][j] = add(s1[i - 1][j - 1], mul(i - 1, s1[i - 1][j]));
    }
    lll sum[110];
    void get(lll n, lll k)
    {
        sum[0] = n % mod;
        sum[1] = n * (n + 1) / 2 % mod;
        for (int i = 2; i <= k; i++)
        {
            sum[i] = 1;
            for (int j = 0; j < i + 1; j++)
            {
                if ((n - j + 1) % (i + 1) == 0)
                    sum[i] = mul(sum[i], (n - j + 1) / (i + 1));
                else
                    sum[i] = mul(sum[i], n - j + 1);
            }
            for (int j = 1; j < i; j++)
            {
                if ((i - j) % 2 == 0)
                    sum[i] = add(sum[i], mod - mul(s1[i][j], sum[j]));
                else
                    sum[i] = add(sum[i], mul(s1[i][j], sum[j]));
            }
        }
    }
    void exgcd(lll a, lll b, lll &x, lll &y, lll &d)
    {
        if (b == 0)
            x = 1, y = 0, d = a;
        else
        {
            exgcd(b, a % b, y, x, d);
            y -= a / b * x;
        }
    }
    lll rev(lll a, lll p)
    {
        lll b, c, d;
        exgcd(a, p, b, c, d);
        return d == 1 ? (b + p) % p : -1;
    }
    lll g(lll t, lll d, lll p, lll k)
    {
        if (t <= k)
        {
            lll res = 1;
            for (int i = 0; i <= t; i++)
                res = mul(res, add(mul(i, p), d));
            return res;
        }
        else
        {
            static lll dp[110], cd[110], cp[110], cnt[110];
            cd[k - 1] = qpow(d, t - k + 2);
            for (int i = k - 2; i >= 0; i--)
                cd[i] = mul(d, cd[i + 1]);
            get(t, k);
            sum[0] = 1;
            cp[0] = 1;
            for (int i = 1; i < k; i++)
                cp[i] = mul(cp[i - 1], p);
            cnt[0] = 0;
            dp[0] = 1;
            lll ma = 0;
            for (int i = 1; i < k; i++)
            {
                dp[i] = 0;
                for (int j = 1, f = 1; j <= i; j++, f = -f)
                {
                    lll r = mul(sum[j], mul(dp[i - j], cp[ma - cnt[i - j]]));
                    if (f > 0)
                        dp[i] = add(dp[i], r);
                    else
                        dp[i] = add(dp[i], mod - r);
                }
                lll x = i;
                cnt[i] = ma;
                while (x % p == 0)
                    x /= p, cnt[i]++, ma++;
                dp[i] = mul(dp[i], rev(x, mod));
            }
            lll res = 0;
            for (int i = 0; i < k; i++)
                res = add(res, mul(cp[i - cnt[i]], mul(cd[i], dp[i])));
            return res;
        }
    }
    lll f(lll n, lll p, lll k)
    {
        if (n < p)
        {
            lll res = 1;
            for (int i = 2; i <= n; i++)
                res = mul(res, i);
            return res;
        }
        else
        {
            lll res = f(n / p, p, k);
            for (int i = 1; i < p; i++)
                res = mul(res, g(n / p + (n % p >= i ? 0 : -1), i, p, k));
            return res;
        }
    }

    void solve(lll n, lll p, lll k, lll _mod, lll &res, lll &cnt)
    {
        mod = _mod;
        init();
        res = f(n, p, k);
        cnt = 0;
        while (n > 0)
            cnt += n / p, n /= p;
    }

    // factorial(n) % 10^k
    ll last_non_zero_digit_of_factorial(ll n, int k)
    {
        lll last_digit_cnt = k, last_digit_radix = 1, base_radix = 10;
        while (k)
        {
            if (k & 1)
                last_digit_radix *= base_radix;
            base_radix *= base_radix;
            k >>= 1;
        }
        ll n5 = qpow(5, last_digit_cnt, last_digit_radix), n2 = qpow(2, last_digit_cnt, last_digit_radix), nn = n2 * n5;
        lll r2, c2, r5, c5;
        solve(n, 2, last_digit_cnt, n2, r2, c2);
        solve(n, 5, last_digit_cnt, n5, r5, c5);
        r2 = mul(r2, qpow(rev(5, n2), c5, n2), n2);
        r5 = mul(r5, qpow(rev(2, n5), c2, n5), n5);
        lll t5 = mul(mul(rev(n2, n5), n2, nn), r5, nn);
        lll t2 = mul(mul(rev(n5, n2), n5, nn), r2, nn);
        ll r = add(t2, t5, nn);
        r = mul(r, qpow(2, c2 - c5, nn), nn);
        return r;
    }
}
int t;
ll n;
int main()
{
    scanf("%d", &t);
    while (t--)
        scanf("%lld", &n), printf("%0*lld\n", 10, Fac::last_non_zero_digit_of_factorial(n, 10));
    return 0;
}