#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define maxn 1000010
using namespace std;
typedef long long ll;
ll map[maxn];
vector<ll> counter[maxn], a[maxn];
inline void write(ll x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline ll read() {
    ll k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}
ll n, m, t, tmpint;
ll x_1, y_1, x_2, y_2, v;
int main() {
    n = read(), m = read(), t = read();
    for (int i = 0; i <= n + 1; ++i) {
        a[i].resize(m + 2), counter[i].resize(m + 2);
    }
    srand(time(0));
    for (int i = n * m; i > 0; --i) {
        map[i] = (rand() * 1ll << 24ll) ^ (rand() << 8ll) ^ (rand() % (1ll << 8));
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            tmpint = read();
            a[i][j] = map[tmpint];
        }
    }
    while (t--) {
        x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read(), v = read();
        ++x_2, ++y_2;
        ll w = map[v];
        counter[x_1][y_1] += w;
        counter[x_1][y_2] -= w;
        counter[x_2][y_1] -= w;
        counter[x_2][y_2] += w;
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            counter[i][j] += counter[i - 1][j] + counter[i][j - 1] - counter[i - 1][j - 1];
            res += (counter[i][j] % a[i][j]) != 0;
        }
    }
    write(res);
}
