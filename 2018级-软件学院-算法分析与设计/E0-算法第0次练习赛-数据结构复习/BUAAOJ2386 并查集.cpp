#pragma G++ optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<climits>
#define RADIX 10
#define maxn 100010

using namespace std;
typedef long long ll;

int f[maxn];
int s[maxn];//以i为偏序关系顶端的集合的个数，用于逆向推导
int t;
int n;
inline void init() {
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        s[i] = 1;
    }
}
inline int getFather(int x) {
    return f[x] == x ? x : f[x] = getFather(f[x]);
}
inline int read() {
    int k = 0;
    char c = getchar();
    while (!isdigit(c))c = getchar();
    while (isdigit(c)) { k = (k << 1) + (k << 3) + c - 48; c = getchar(); }
    return k;
}
inline void write(ll a) {
    if (a >= RADIX)write(a / RADIX);
    putchar(a % RADIX + 48);
}
struct edge {
    int u, v;
    int w;
    bool operator < (const edge& a) {
        return w < a.w;
    }
}mstEdge[maxn];

ll res;
int p, q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    t = read();
    while(t--){
        n = read();
        res = 0;
        init();
        for (int i = 0; i < n - 1; ++i) {
            mstEdge[i].u = read();
            mstEdge[i].v = read();
            mstEdge[i].w = read();
            res += mstEdge[i].w;
        }
        sort(mstEdge, mstEdge + n - 1);
        for (int i = 0; i < n - 1; ++i) {
            p = getFather(mstEdge[i].u);
            q = getFather(mstEdge[i].v);
            if (p != q) {
                f[p] = f[q];
                res += (1ll * mstEdge[i].w + 1ll) * (1ll * s[p] * s[q] - 1ll);
                s[q] += s[p];
                s[p] = 0;
            }
        }
        write(res); putchar('\n');
    }
}
