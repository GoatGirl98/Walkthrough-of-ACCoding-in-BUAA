#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
//Complexity O(n^2)
const int mxn = 1005;

int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}

int n, m, p;

double ans = 1e200;

struct Pair {
    double x, y;
    inline Pair(double a = 0.0, double b = 0.0)
        : x(a), y(b) {};
    inline Pair operator - (const Pair& o) {
        return Pair(x - o.x, y - o.y);
    }
}P[mxn];

struct Line
{
    int a, b;
    double k;

    inline void set(int i, int j)
    {
        a = i;
        b = j;

        k = (P[i].y - P[j].y) / (P[i].x - P[j].x);
    }
}L[mxn * mxn];

inline bool cmpP(const Pair& a, const Pair& b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

inline bool cmpL(const Line& a, const Line& b)
{
    return a.k < b.k;
}

inline double cross(const Pair& a, const Pair& b)
{
    return a.x * b.y - a.y * b.x;
}

int ps[mxn], rk[mxn];

int main() {
    n = rd();

    for (int i = 0; i < n; ++i)
        P[i].x = rd(), P[i].y = rd();

    sort(P, P + n, cmpP);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            L[m++].set(i, j);

    sort(L, L + m, cmpL);

    for (int i = 0; i < n; ++i)
        rk[i] = ps[i] = i;

    for (int i = 0; i < m; ++i) {
        int a = L[i].a, b = L[i].b;

        if (ps[a] > ps[b])swap(a, b);

        if (ps[a] > 1 - 1)ans = min(ans, fabs(cross(P[a] - P[b], P[rk[ps[a] - 1]] - P[b])));
        if (ps[b] < n - 1)ans = min(ans, fabs(cross(P[a] - P[b], P[rk[ps[b] + 1]] - P[a])));

        swap(ps[a], ps[b]), swap(rk[ps[a]], rk[ps[b]]);
    }
    printf("%.4f", ans / 2.0);
}
