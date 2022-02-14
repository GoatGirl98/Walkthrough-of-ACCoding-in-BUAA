#include<iostream>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll rd()
{
    ll k = 0, f = 1;
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
void wr(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}

// 2D Fenwick Range Tree from Nyaan
// bit ... data_structure_type
// S ... size_type
// T ... value_type
template <typename S, typename T>
struct FenwickRangeTree {
    struct BIT {
        int N;
        vector<T> data;

        BIT() = default;
        BIT(int size) { init(size); }

        void init(int size) {
            N = size;
            data.assign(N + 1, 0);
        }

        // data[k] += x
        void add(int k, T x) {
            for (++k; k <= N; k += k & -k) data[k] += x;
        }

        T sum(int k) const {
            if (k <= 0) return T();
            T ret = T();
            for (; k; k -= k & -k) ret += data[k];
            return ret;
        }

        inline T sum(int l, int r) const { return sum(r) - sum(l); }
    };

    using P = pair<S, S>;
    S N, M;
    vector<BIT> bit;
    vector<vector<S>> ys;
    vector<P> ps;

    FenwickRangeTree() = default;

    void add_point(S x, S y) { ps.push_back(make_pair(x, y)); }

    void build() {
        sort(begin(ps), end(ps));
        ps.erase(unique(begin(ps), end(ps)), end(ps));
        N = ps.size();
        bit.resize(N + 1);
        ys.resize(N + 1);
        for (int i = 0; i <= N; ++i) {
            for (int j = i + 1; j <= N; j += j & -j) ys[j].push_back(ps[i].second);
            sort(begin(ys[i]), end(ys[i]));
            ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));
            bit[i].init(ys[i].size());
        }
    }

    int id(S x) const {
        return lower_bound(
            begin(ps), end(ps), make_pair(x, S()),
            [](const P& a, const P& b) { return a.first < b.first; }) -
            begin(ps);
    }

    int id(int i, S y) const {
        return lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);
    }

    void add(S x, S y, T a) {
        int i = lower_bound(begin(ps), end(ps), make_pair(x, y)) - begin(ps);
        assert(ps[i] == make_pair(x, y));
        for (++i; i <= N; i += i & -i) bit[i].add(id(i, y), a);
    }

    T sum(S x, S y) const {
        T ret = T();
        for (int a = id(x); a; a -= a & -a) ret += bit[a].sum(id(a, y));
        return ret;
    }

    T sum(S xl, S yl, S xr, S yr) const {
        return sum(xr, yr) - sum(xl, yr) - sum(xr, yl) + sum(xl, yl);
        /*
        T ret = T();
        int a = id(xl), b = id(xr);
        while (a != b) {
          if (a < b) {
            ret += bit[b].sum(id(b, yl), id(b, yr));
            b -= b & -b;
          } else {
            ret -= bit[a].sum(id(a, yl), id(a, yr));
            a -= a & -a;
          }
        }
        return ret;
        */
    }
};
struct Event
{
    bool flag; // 0 : add 1 : query
    int xl, yl, xr, yr;
    ll w;
};
vector<Event> events;
unordered_map<string, int> mp;
int mp_sz;
string news, occur_time, time_l, time_r;
int str_to_time(const string& s)
{
    int a = s.find(":"), sz = s.size();
    string h = s.substr(0, a), m = s.substr(a + 1, sz - a - 1);
    return stoi(h) * 60 + stoi(m);
}
int n, q, x, y;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    FenwickRangeTree<int, ll> bit;
    cin >> n >> q;
    events.resize(n + q);
    for (int i = 0; i < n; ++i)
    {
        events[i].flag = 0;
        cin >> news >> occur_time;
        if (!mp.count(news))
            mp[news] = ++mp_sz, x = mp_sz;
        else
            x = mp[news];
        y = str_to_time(occur_time);
        events[i].xl = x, events[i].yl = y, events[i].w = 1;
        bit.add_point(events[i].xl, events[i].yl);
    }
    for (int i = n; i < n + q; ++i)
    {
        events[i].flag = 1;
        cin >> news >> time_l >> time_r;
        x = mp[news];
        /*
        if (!events[i].flag)
        {
            events[i].xl = rd(), events[i].yl = rd(), events[i].w = rd();
            bit.add_point(events[i].xl, events[i].yl);
        }
        else
        */
        events[i].xl = x, events[i].yl = str_to_time(time_l), events[i].xr = x + 1, events[i].yr = str_to_time(time_r) + 1;
    }
    bit.build();
    for (int i = 0; i < n + q; ++i)
    {
        if (!events[i].flag)
            bit.add(events[i].xl, events[i].yl, events[i].w);
        else
            wr(bit.sum(events[i].xl, events[i].yl, events[i].xr, events[i].yr)), putchar('\n');
    }
}