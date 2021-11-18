#include<stdio.h>
#include<ctype.h>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn = 1010;
ll rd() {
    ll k = 0, f = 1;
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
void wr(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
bitset<maxn> a[maxn];
ll n, m, u, v;
ll closure_cnt;
void floyd() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[j][i])//如果j能到i 则j可以接受i原有的偏序关系
                a[j] |= a[i];
}
int main() {
    n = rd();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = rd();
    floyd();
    for (int i = 1; i <= n; ++i, putchar('\n'))
        for (int j = 1; j <= n; ++j)
            wr(a[i][j]), putchar(' ');
}
