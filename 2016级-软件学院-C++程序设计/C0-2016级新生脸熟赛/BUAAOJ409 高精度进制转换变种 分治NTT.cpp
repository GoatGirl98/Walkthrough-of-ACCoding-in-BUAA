#include<stdio.h>
#include<string.h>
#include<vector>

#define ll long long
#define INF 2147483647
#define poly vector<int>
using namespace std;

inline int read() {
    int f = 1, x = 0;
    char s = getchar();

    while (s < '0' || s > '9') {
        if (s == '-')
            f = -1;

        s = getchar();
    }

    while (s >= '0' && s <= '9') {
        x = x * 10 + s - 48;
        s = getchar();
    }

    return f * x;
}



const int p = 998244353, G = 3;
const int N = 8e5 + 5;
poly f, pw[30];
int a[200];
char s[N], b[200], c[200];

inline int add(int a, int b) {
    return a + b >= p ? a + b - p : a + b;
}

inline int sub(int a, int b) {
    return a - b < 0 ? a - b + p : a - b;
}

inline int ksm(int a, int b) {
    int ans = 1;

    for (; b; b >>= 1, a = 1ll * a * a % p)
        if (b & 1)
            ans = 1ll * ans * a % p;

    return ans;
}

const int inv2 = ksm(2, p - 2), invG = ksm(G, p - 2);
int rev[N << 2], rev_len;

inline void getrev(int n) {
    if (n == rev_len)
        return;

    rev_len = n;

    for (int i = 0; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
}

int w[N];
inline void NTT(poly &f, bool flag) {
    int n = f.size();
    getrev(n);

    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(f[i], f[rev[i]]);

    w[0] = 1;

    for (int len = 2, o = 1; len <= n; len <<= 1, o <<= 1) {
        int w1 = ksm((flag ? G : invG), (p - 1) / len);

        for (int i = 1; i < o; i++)
            w[i] = 1ll * w[i - 1] * w1 % p;

        for (int k = 0; k < n; k += len)
            for (int i = 0; i < o; i++) {
                int tmp = 1ll * w[i] * f[i + k + o] % p;
                f[i + k + o] = sub(f[i + k], tmp);
                f[i + k] = add(f[i + k], tmp);
            }
    }

    if (flag)
        return;

    int invn = ksm(n, p - 2);

    for (int i = 0; i < n; i++)
        f[i] = 1ll * f[i] * invn % p;
}

poly operator + (poly a, int b) {
    a[0] = add(a[0], b);
    return a;
}

poly operator - (poly a, int b) {
    a[0] = sub(a[0], b);
    return a;
}

poly operator * (poly a, int b) {
    for (int i = 0; i < a.size(); i++)
        a[i] = 1ll * a[i] * b % p;

    return a;
}

poly operator + (poly a, poly b) {
    poly c = a;
    c.resize(max(a.size(), b.size()));

    for (int i = 0; i < b.size(); i++)
        c[i] = add(c[i], b[i]);

    return c;
}

poly operator - (poly a, poly b) {
    poly c = a;
    c.resize(max(a.size(), b.size()));

    for (int i = 0; i < b.size(); i++)
        c[i] = sub(a[i], b[i]);

    return c;
}

poly operator * (poly a, poly b) {
    int lim = 1, len = a.size() + b.size() - 1;

    if (len <= 200) {
        poly c;
        c.resize(len);

        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++)
                c[i + j] = add(c[i + j], 1ll * a[i] * b[j] % p);

        return c;
    }

    for (; lim < len; lim <<= 1);

    a.resize(lim), b.resize(lim);
    NTT(a, 1), NTT(b, 1);

    for (int i = 0; i < lim; i++)
        a[i] = 1ll * a[i] * b[i] % p;

    NTT(a, 0);
    a.resize(len);
    return a;
}

inline void calc(poly &f, int p) {
    for (int i = 0; i < (int)f.size() - 1; i++) {
        f[i + 1] += f[i] / p;
        f[i] %= p;
    }

    while (f.back() >= p) {
        int v = f.back();
        f[(int)f.size() - 1] %= p;
        f.push_back(v / p);
    }

    while (f.size() >= 2 && f.back() == 0)
        f.pop_back();
}

void print(poly f) {
    //  calc(f);
    for (int i = (int)f.size() - 1; i >= 0; i--)
        putchar(b[f[i]]);

    puts("");
}

void testprint(poly f) {
    for (int i = (int)f.size() - 1; i >= 0; i--)
        printf("%d", f[i]), putchar(' ');

    puts("");
}

poly solve(poly f, int d, int b) {
    int n = f.size();

    if (n == 1) {
        calc(f, b);
        return f;
    }

    n >>= 1;
    poly lf, rf;
    lf.resize(n), rf.resize(n);

    for (int i = 0; i < n; i++)
        lf[i] = f[i], rf[i] = f[i + n];

    lf = solve(lf, d - 1, b), rf = solve(rf, d - 1, b);
    f = pw[d] * rf;
    calc(f, b);
    f = f + lf;
    calc(f, b);
    return f;
}

int main() {
    for (int i = 0; i < 10; i++)
        b[i] = '0' + i;

    for (int i = 1; i <= 26; i++)
        a['A' + i - 1] = i;

    //  putchar(b[24]);
    //  for(int i=0;i<62;i++) putchar(b[i]);
    int x = 26, y = 10;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    f.resize(n);

    for (int i = 1; i <= n; i++)
        f[n - i] = a[s[i]];

    int len = 1, k = 0;

    while (len < n)
        len <<= 1, k++;

    f.resize(len);
    pw[0].push_back(x);
    calc(pw[0], y);

    for (int i = 1; i <= k; i++) {
        pw[i] = pw[i - 1] * pw[i - 1];
        calc(pw[i], y);
    }

    f = solve(f, k - 1, y);
    print(f);
    return 0;
}