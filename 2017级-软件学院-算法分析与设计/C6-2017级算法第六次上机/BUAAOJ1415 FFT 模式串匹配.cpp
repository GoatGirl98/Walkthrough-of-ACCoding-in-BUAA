#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 400100;
const double PI = acos(-1.0);
struct cp
{
    double r, i;
    cp() {}
    cp(double _r, double _i)
    {
        r = _r; i = _i;
    }
    cp operator +(const cp a)const
    {
        return cp(a.r + r, a.i + i);
    }
    cp operator -(const cp a)const
    {
        return cp(r - a.r, i - a.i);
    }
    cp operator *(const cp a)const
    {
        return cp(r * a.r - i * a.i, r * a.i + i * a.r);
    }
    cp conj()
    {
        return cp(r, -i);
    }
};

int n = 1, m;
cp f[N], g[N], omg[N], inv[N];
void FFT_init() {
    for (int i = 0; i < n; i++) {
        omg[i] = cp(cos(2 * PI * i / n), sin(2 * PI * i / n));
        inv[i] = omg[i].conj();
    }
}
void fft(cp* a, cp* omg) {
    int lim = 0;
    while ((1 << lim) < n) lim++;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < lim; j++)
            if (i >> j & 1) t |= 1 << (lim - j - 1);
        if (i < t) swap(a[i], a[t]);
    }
    for (int l = 2; l <= n; l *= 2) {
        int m = l / 2;
        for (cp* p = a; p != a + n; p += l) {
            for (int i = 0; i < m; i++) {
                cp t = omg[n / l * i] * p[m + i];
                p[m + i] = p[i] - t;
                p[i] = p[i] + t;
            }
        }
    }
}

int res[N], sum[N];
char a[N], b[N];
int lena, lenb;
void solve(char c)
{
    for (int i = 0; i < lena; i++) {
        if (a[i] == c)f[i].r = 1;
        else f[i].r = 0;
        f[i].i = 0;
    }
    for (int i = lena; i < n; i++) {
        f[i].r = 0; f[i].i = 0;
    }
    for (int i = 0; i < lenb; i++) {
        if (b[i] == c)g[i].r = 1;
        else g[i].r = 0;
        g[i].i = 0;
    }
    for (int i = lenb; i < n; i++) {
        g[i].r = 0; g[i].i = 0;
    }
    fft(f, omg), fft(g, omg);
    for (int i = 0; i < n; i++)f[i] = f[i] * g[i];
    fft(f, inv);
    for (int i = 0; i < n; i++) {
        sum[i] = (int)(f[i].r / n + 0.5);
    }
    for (int i = 0; i < n; i++) {
        res[i] += sum[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (scanf("%d%d", &lena, &lenb) != EOF) {
        scanf("%s%s", a, b);
        for (int i = 0; i < lena; i++) {
            if (a[i] == 'S')a[i] = 'R';
            else if (a[i] == 'R')a[i] = 'P';
            else if (a[i] == 'P')a[i] = 'S';
        }
        reverse(b, b + lenb);
        while (n < lena * 2 || n < lenb * 2)n <<= 1;
        FFT_init();
        solve('S');
        solve('R');
        solve('P');
        int ans = 0;
        for (int i = lenb - 1; i < lena + lenb - 1; i++) {
            ans = max(ans, res[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
