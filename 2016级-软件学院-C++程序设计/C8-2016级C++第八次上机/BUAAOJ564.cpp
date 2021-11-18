#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#define maxn 1000010
#define RADIX 10
using namespace std;
typedef long long ll;
int n, m; ll k; int cap;
int tmp;
ll sum[maxn];
inline ll read() {
    ll k = 0;
    char c = getchar();
    while (!isdigit(c))c = getchar();
    while (isdigit(c)) { k = (k << 1) + (k << 3) + c - 48; c = getchar(); }
    return k;
}
inline void write(ll a) {
    if (a >= RADIX)write(a / RADIX);
    putchar(a % RADIX + 48);
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            sum[i] = read();
        }
        while (m--) {
            k = read();
            if (sum[n - 1] < k) {
                write(sum[n - 1]);
                putchar('\n');
                continue;
            }
            if (sum[0] > k) {
                write(sum[0]);
                putchar('\n');
                continue;
            }
            ll* pos = lower_bound(sum, sum + n, k);
            if (sum[pos - sum] > k)pos--;
            if (pos == sum + n - 1) {
                write(sum[pos - sum]);
                putchar('\n');
            }
            else if (sum[pos - sum + 1] - k < k - sum[pos - sum]) {
                write(sum[pos - sum + 1]);
                putchar('\n');
            }
            else {
                write(sum[pos - sum]);
                putchar('\n');
            }
        }
    }
}
