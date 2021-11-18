#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define input_radix 10
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
using namespace std;
const int multi_case = true;
char s[100010];
namespace util
{
    int rd()
    {
        int k = 0, f = 1;
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
    int trans_num(const char& c)
    {
        if (c >= '0' && c <= '9')
            return c - '0';
        else if (c >= 'A' && c <= 'Z')
            return c - 'A' + 10;
        else if (c >= 'a' && c <= 'z')
            return c - 'a' + 36;
        else
            return -1;
    }
    char trans_char(const int& num)
    {
        return num + 'A' - 1;
        /*
        if (num >= 0 && num <= 9)
            return num + '0';
        else if (num >= 10 && num <= 35)
            return num - 10 + 'A';
        else if (num >= 36 && num <= 61)
            return num - 36 + 'a';
        else
            return -1;
        */
    }
}
using namespace util;
namespace Trans_Solver
{
    int output_radix;

    const double pi = acos(-1.0);
    struct comp
    {
        double r, i;
        comp(double rr = 0, double ii = 0) : r(rr), i(ii) {}
        comp operator+(const comp& o) { return comp(r + o.r, i + o.i); }
        comp operator-(const comp& o) { return comp(r - o.r, i - o.i); }
        comp operator*(const comp& o) { return comp(r * o.r - i * o.i, r * o.i + i * o.r); }
        comp operator/(const double& y) { return comp(r / y, i / y); }
    };
    //A[1 << 20], B[1 << 20], C[1 << 20], Zero;
    vector<comp> A, B, C;
    comp Zero;
    struct node
    {
        int len1, len2;
        node(int a = 0, int b = 0) : len1(a), len2(b) {}
    };
    int n, a[100010], s1[1 << 20], s2[1 << 20];


    void DFT(vector<comp>& a, int n, int op)
    {
        for (int i = 1, p, q, t; i < n; i++)
        {
            for (p = i, q = 0, t = 1; t < n; q <<= 1, q |= p & 1, p >>= 1, t <<= 1)
                ;
            if (i < q)
                swap(a[i], a[q]);
        }
        for (int len = 2, i, j; len <= n; len <<= 1)
        {
            comp w = comp(cos(2.0 * op * pi / len), sin(2.0 * op * pi / len));
            for (i = 0; i < n; i += len)
            {
                comp W = comp(1, 0);
                for (j = 0; j < (len >> 1); j++)
                {
                    comp u = a[i + j], v = a[i + j + (len >> 1)] * W;
                    a[i + j] = u + v, a[i + j + (len >> 1)] = u - v, W = W * w;
                }
            }
        }
        if (op == -1)
            for (int i = 0; i < n; i++)
                a[i] = a[i] / n;
    }

    node solve(int l, int r)
    {
        int L = 7 * l, R = 7 * r;
        A.resize(R), B.resize(R), C.resize(R);
        if (r - l <= 500)
        {
            int len1 = 1, len2 = 1;
            s2[L] = 1;
            for (int i = r - 1, j; i >= l; i--)
            {
                s1[L] += a[i];
                for (j = L; s1[j] >= output_radix; s1[j + 1] += s1[j] / output_radix, s1[j] %= output_radix, j++)
                    ;
                if (j - L >= len1)
                    len1 = j - L + 1;
                if (i != l)
                {
                    for (j = 0; j < len1; j++)
                        s1[j + L] *= input_radix;
                    for (j = L; s1[j] || j - L < len1; s1[j + 1] += s1[j] / output_radix, s1[j] %= output_radix, j++)
                        ;
                    len1 = j - L;
                }
                for (j = 0; j < len2; j++)
                    s2[j + L] *= input_radix;
                for (j = L; s2[j] || j - L < len2; s2[j + 1] += s2[j] / output_radix, s2[j] %= output_radix, j++)
                    ;
                len2 = j - L;
            }
            return node(len1, len2);
        }
        int mid = (l + r) >> 1, Mid = 7 * mid, N = 1, len1, len2;
        node x = solve(l, mid), y = solve(mid, r);
        while ((N < x.len2 + y.len1 - 1) || (N < x.len2 + y.len2 - 1))
            N <<= 1;

        for (int i = 0; i < x.len2; i++)
            A[i] = comp((double)s2[i + L], 0);
        for (int i = x.len2; i < N; i++)
            A[i] = Zero;
        for (int i = 0; i < y.len1; i++)
            B[i] = comp((double)s1[i + Mid], 0);
        for (int i = y.len1; i < N; i++)
            B[i] = Zero;
        for (int i = 0; i < y.len2; i++)
            C[i] = comp((double)s2[i + Mid], 0);
        for (int i = y.len2; i < N; i++)
            C[i] = Zero;
        DFT(A, N, 1), DFT(B, N, 1), DFT(C, N, 1);
        for (int i = 0; i < N; i++)
        {
            B[i] = A[i] * B[i];
            C[i] = A[i] * C[i];
        }
        DFT(B, N, -1), DFT(C, N, -1);
        for (int i = L; i < Mid; i++)
            s1[i] += int(B[i - L].r + 0.5), B[i - L + 1].r += s1[i] / output_radix, s1[i] %= output_radix;
        for (int i = Mid; i - L < N; i++)
            s1[i] = int(B[i - L].r + 0.5), B[i - L + 1].r += s1[i] / output_radix, s1[i] %= output_radix;
        for (int i = N + L; i < R; i++)
            s1[i] = 0;
        for (int i = L; i - L < N; i++)
            s2[i] = int(C[i - L].r + 0.5), C[i - L + 1].r += s2[i] / output_radix, s2[i] %= output_radix;
        for (int i = N + L; i < R; i++)
            s2[i] = 0;
        for (len1 = R - 1; !s1[len1] && len1 > L; len1--)
            ;
        for (len2 = R - 1; !s2[len2] && len2 > L; len2--)
            ;
        return node(len1 - L + 1, len2 - L + 1);
    }

    void solve(char* s, int ori_radix, int trans_radix)
    {
        output_radix = trans_radix;
        n = strlen(s);
        for (int i = 0; i < n; i++)
            a[n - i - 1] = trans_num(s[i]);
        node x = solve(0, n);
        for (int i = 0; i < x.len1 - 1; ++i)
            if(s1[i] <= 0)
                s1[i] += 26, --s1[i + 1];
        if(!s1[x.len1 - 1])
            --x.len1;
        for (int i = x.len1 - 1; i >= 0; i--)
            putchar(trans_char(s1[i]));
        putchar('\n');
        if (multi_case)
        {
            memset(s1, 0, sizeof(int) * x.len1);
            memset(s2, 0, sizeof(int) * x.len2);
        }
    }
}
int main()
{
    while(scanf("%s", s) != EOF)
        Trans_Solver::solve(s, 10, 26);
}