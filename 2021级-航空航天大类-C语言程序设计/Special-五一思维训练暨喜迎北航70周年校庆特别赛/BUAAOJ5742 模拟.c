#include <stdio.h>
#include <stdlib.h>
typedef __int128 lll;
#define N 9
#define M ((1 << 7) - 1)
int test_prime[N + 7] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23};
lll _abs(lll x) { return x < 0 ? -x : x; }
lll qpow(lll a, lll b, lll m)
{
    a %= m;
    lll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int millerRabin(lll n)
{
    if (n < 3 || n % 2 == 0)
        return n == 2;
    lll a = n - 1, b = 0;
    while (!(a & 1))
        a >>= 1, ++b;
    lll i, j;
    for (i = 1; i <= 12; ++i)
    {
        lll x = rand() % (n - 2) + 2;
        lll v = qpow(x, a, n);
        if (v == 1)
            continue;
        for (j = 0; j < b; ++j)
        {
            if (v == n - 1)
                break;
            v = v * v % n;
        }
        if (j >= b)
            return 0;
    }
    return 1;
}
lll floyd(lll a, lll b, lll p)
{
    return (a * a % p + b) % p;
}

lll gcd(lll a, lll b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int r = 0;
    while (!((a & 1) || (b & 1)))
        a >>= 1, b >>= 1, r++;

    lll ret = 0;
    while (1)
    {
        while (!(a & 1))
            a >>= 1;
        while (!(b & 1))
            b >>= 1;
        if (a > b)
            a = a - b;
        else
            b = b - a;
        if (0 == a)
        {
            ret = b << r;
            break;
        }
        if (0 == b)
        {
            ret = a << r;
            break;
        }
    }
    return ret;
}

lll pollard_pho(lll n)
{
    lll x = 0, c = rand() % (n - 1) + 1;
    for (register int i = 1;; i <<= 1)
    {
        lll y = 1, z = x, ans;
        for (register int j = 1; j <= i; j++)
        {
            x = floyd(x, c, n);
            y = y * _abs(x - z) % n;
            if (j % M == 0)
            {
                ans = gcd(n, y);
                if (ans > 1)
                    return ans;
            }
        }
        ans = gcd(n, y);
        if (ans > 1)
            return ans;
    }
}

void min_factor(lll n, lll *ans)
{
    if (n < 2)
        return;
    if (millerRabin(n))
    {
        if ((*ans) > n)
            (*ans) = n;
        return;
    }
    lll factor = 0;
    do
        factor = pollard_pho(n);
    while (factor == n);
    while (n % factor == 0)
    {
        n /= factor;
    }
    min_factor(n, ans);
    min_factor(factor, ans);
}
int n, m;
int a[55][55];
int x[10], y[10], prime_cnt, x_line, y_line;
int key_word_step1;
int b[55][55];
int arr[55];
int key_word_step4;
void step_1()
{
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (millerRabin(a[i][j]))
                x[++prime_cnt] = i, y[prime_cnt] = j;
    for (int i = 1; i <= prime_cnt; ++i)
        for (int j = i + 1; j <= prime_cnt; ++j)
        {
            if (x[i] == x[j])
                x_line = x[i];
            else if (y[i] == y[j])
                y_line = y[i];
        }
    key_word_step1 = x_line + y_line + a[x_line][y_line];
}
void step_2()
{
    lll factor = (lll)10000000000 * 10000000000;
    lll tmp = key_word_step1;
    min_factor(tmp, &factor);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = a[i][j] % (key_word_step1 + i - factor);
}
void step_3()
{
    for (int j = 0; j < n; ++j)
    {
        lll tmp = b[m - 1][j];
        for (int i = m - 2; i >= 0; --i)
            tmp = _abs(b[i][j] - tmp) << 1;
        arr[j] = tmp;
    }
}
void step_4()
{
    for (int i = 0; i < n; ++i)
        key_word_step4 ^= arr[i];
    int key_m = key_word_step4 % m, key_n = key_word_step4 % n;
    printf("%d", a[(key_m + x_line + 1) >> 1][(key_n + y_line) >> 1]);
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = m - 1; i >= 0; --i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    step_1();
    step_2();
    step_3();
    step_4();
}