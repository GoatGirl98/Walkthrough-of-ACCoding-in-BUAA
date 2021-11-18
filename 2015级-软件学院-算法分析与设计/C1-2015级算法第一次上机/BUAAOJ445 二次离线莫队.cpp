#include<stdio.h>
#include<vector>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
typedef long long ll;
const int maxn = 10005;

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
void wr(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}

int n, m, uni, a[maxn], block, A[maxn], L = 1, R;
ll _l[maxn], _r[maxn], b[maxn], ec[maxn], cnt[maxn];

inline int getposition(register int i) { return (i - 1) / block + 1; } // 所在的块

struct Node {
    int l, r, id;
    bool operator<(const Node& o) const {
        if (l / block == o.l / block) {
            return r < o.r;
        }
        return l < o.l;
    }
} nodes[maxn];

struct vnode {
    int l, r, id, x;
    vnode(int _l = 0, int _r = 0, int _id = 0, int _x = 0) :l(_l), r(_r), id(_id), x(_x) {}
};
vector<vnode> __l[maxn], __r[maxn];

struct BIT {
    int a[maxn];
    int n;
    inline int lowbit(int x) { return (x & (-x)); }

    inline void add(int x) { // 加
        while (x <= n) {
            a[x]++;
            x += lowbit(x);
        }
    }

    inline int sum(int x) {
        int ans = 0;
        while (x) {
            ans += a[x];
            x -= lowbit(x);
        }
        return ans;
    }

    inline void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; ++i)a[i] = 0;
    }
} bit;

inline void addL(int a) {
    for (int i = a; i >= (getposition(a) - 1) * block + 1; --i) {
        cnt[i]++;
    }
    for (int i = getposition(a) - 1; i; --i) {
        ec[i]++;
    }
}

inline void addR(int a, int uni) {
    for (int i = a; i <= (getposition(a) - 1) * block + block; ++i) {
        cnt[i]++;
    }
    for (int i = getposition(a) + 1; i <= getposition(uni); ++i) {
        ec[i]++;
    }
}

inline int calc(int a) {
    register int ans = cnt[a];
    ans += ec[getposition(a)];
    return ans;
}

inline void solve() {
    L = 1, R = 0;
    bit.init(n);
    sort(nodes + 1, nodes + m + 1);
    for (int i = 1; i <= n; ++i) {
        _l[i] = _l[i - 1] + bit.sum(n) - bit.sum(a[i]);
        bit.add(a[i]);
    }
    bit.init(n);
    for (int i = n; i; --i) {
        _r[i] = _r[i + 1] + bit.sum(a[i] - 1);
        bit.add(a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int l = nodes[i].l, r = nodes[i].r, id = nodes[i].id;
        if (R < r) {
            __l[L - 1].push_back(vnode(R + 1, r, id, 0));
            b[id] += _l[r] - _l[R];
        }
        if (R > r) {
            __l[L - 1].push_back(vnode(r + 1, R, id, 1));
            b[id] -= _l[R] - _l[r];
        }
        if (L > l) {
            __r[r + 1].push_back(vnode(l, L - 1, id, 0));
            b[id] += _r[l] - _r[L];
        }
        if (L < l) {
            __r[r + 1].push_back(vnode(L, l - 1, id, 1));
            b[id] -= _r[L] - _r[l];
        }
        L = l, R = r;
    }
    for (int i = 1; i <= n; ++i) {
        addL(a[i] - 1);
        for (vnode& x : __l[i]) {
            int l = x.l, r = x.r, id = x.id, _x = x.x;
            ll tmp = 0;
            for (int j = l; j <= r; ++j) tmp += calc(a[j]);
            if (_x) b[id] += tmp;
            else b[id] -= tmp;
        }
    }
    memset(ec, 0, sizeof(ec));
    memset(cnt, 0, sizeof(cnt));
    for (int i = n; i; --i) {
        addR(a[i] + 1, uni);
        for (vnode& x : __r[i]) {
            register int l = x.l, r = x.r, id = x.id, _x = x.x;
            register ll tmp = 0;
            for (register int j = l; j <= r; ++j)  tmp += calc(a[j]);
            if (_x)  b[id] += tmp;
            else b[id] -= tmp;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int id = nodes[i].id;
        b[id] += b[nodes[i - 1].id];
    }
}

inline void init() {
    memset(a, 0, sizeof(a)), memset(A, 0, sizeof(A));
    memset(_l, 0, sizeof(_l)), memset(_r, 0, sizeof(_r));
    memset(b, 0, sizeof(b)), memset(ec, 0, sizeof(ec)), memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i <= n; ++i)__l[i].clear(), __r[i].clear();
}

int main() {
    while (scanf("%d", &n) != EOF) {
        init();
        block = sqrt(n);
        for (int i = 1; i <= n; ++i)
            A[i] = a[i] = rd();
        sort(A + 1, A + n + 1);
        uni = unique(A + 1, A + n + 1) - A - 1;
        m = rd();
        for (int i = 1; i <= n; ++i)
            a[i] = lower_bound(A + 1, A + uni + 1, a[i]) - A;

        for (int i = 1; i <= m; ++i)
            nodes[i].l = rd() + 1, nodes[i].r = rd() + 1, nodes[i].id = i;
        solve();
        for (int i = 1; i <= m; ++i)
            wr(b[i]), putchar('\n');
    }
}
