#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
typedef long long i64;
namespace FastIO
{
    const int BUFF_SZ = 1 << 20;
    char buf[BUFF_SZ], *p1 = buf, *p2 = buf;
    inline char nc() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUFF_SZ, stdin), p1 == p2) ? EOF : *p1++; }
    int rd()
    {
        int ret = 0, f = 1;
        char ch = nc();

        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                f = -1;
            ch = nc();
        }
        while (ch >= '0' && ch <= '9')
        {
            ret = (ret << 1) + (ret << 3) + (ch ^ 48);
            ch = nc();
        }

        return f == 1 ? ret : -ret;
    }
    char Buf[BUFF_SZ], out[20];
    int P, out_size;
    void flush() { Buf[out_size] = '\0', fwrite(Buf, 1, out_size, stdout), out_size = 0; }
    void wr(i64 x, char ch = '\n')
    {
        if (out_size >= (BUFF_SZ >> 1))
            flush();

        if (x < 0)
            Buf[out_size++] = 45, x = -x;

        do
            out[++P] = (x % 10) ^ 48;
        while (x /= 10);

        do
            Buf[out_size++] = out[P];
        while (--P);
        Buf[out_size++] = ch;
    }
    struct IOFlush
    {
        ~IOFlush() { flush(); }
    } tail;
}
// 1-indexed
template <typename T, typename F>
struct rmq
{
    static const int b = 4, all_mask = 65535, B = 16;
    int n; // size of array
    std::vector<T>& a; // origin array
    std::vector<int> _log_2; // record of log_2(i)
    std::vector<std::vector<int>> st; // sparse table
    std::vector<int> masks; // optimize inside block
    F f;

    int op(int x, int y) { return f(a[x], a[y]) ? x : (a[x] == a[y]) ? std::min(x, y) : y; }
    // least significant set bit
    int lsb(int x) { return x & (-x); }
    int msb_index(int x) { return 31 ^ __builtin_clz(x); }

    rmq(F _f, std::vector<T>& _a) : f(_f), n(_a.size() - 1), a(_a),masks(_a.size()) { build(); }

    void build()
    {
        if (!n)
            return;
        int lim = n >> b;
        _log_2.resize(lim + 2);
        for (int i = 2; i < _log_2.size(); ++i)
            _log_2[i] = _log_2[i >> 1] + 1;

        // optimize : O(1) query inside block, use it when block_size <= bit_length (int : 32 long long : 64)
        int cur_mask = 0;
        for (int i = 1; i <= n; ++i)
        {
            // preserve B bits
            cur_mask = (cur_mask << 1) & all_mask; 
            while (cur_mask > 0 && op(i, i - msb_index(lsb(cur_mask))) == i)
                cur_mask ^= lsb(cur_mask);
            cur_mask |= 1;
            masks[i] = cur_mask;
        }

        // sparse table of target element in each block
        st.resize(_log_2[lim] + 1);
        st[0].resize(lim + 1);
        for (int i = 1; i <= lim; ++i)
            st[0][i] = query_small(i << b, (i << b) | (B - 1));
        for (int k = 1, pw = 1; (pw << 1) <= lim; pw <<= 1, ++k)
        {
            st[k].resize(lim - (pw << 1) + 2);
            for (int j = 1; j < st[k].size(); ++j)
                st[k][j] = op(st[k - 1][j], st[k - 1][j + pw]);
        }
    }
    // O(1) optimize
    int query_small(int l, int r)
    {
        int dist_from_r = msb_index(masks[r] & ((1 << (r - l + 1)) - 1));
        return r - dist_from_r;
    }

    // query after static rmq is built
    int query(int l, int r)
    {
        if (r - l + 1 <= B)
            return query_small(l, r);
        int ret = op(query_small(l, l + B - 1), query_small(r - B + 1, r));
        int belong_l = (l >> b) + 1, belong_r = (r >> b);
        if (belong_l < belong_r)
        {
            int dep = msb_index(belong_r - belong_l);
            ret = op(ret, op(st[dep][belong_l], st[dep][belong_r - (1 << dep)]));
        }
        return ret;
    }
};
// 1-indexed
template <typename T, typename F>
struct nearest_bound
{
    int n;
    std::vector<T>& a;
    std::vector<int> pre, suf;
    F f;
    bool op(int x, int y) { return f(a[x], a[y]); }
    // pre[i] = 0 or suf[i] = 0 means pre/suf nearest bound do not exist.
    nearest_bound(F _f, std::vector<T>& _a) : f(_f), n(_a.size() - 1), a(_a), pre(_a.size()), suf(_a.size())
    {
        std::vector<int> s;
        for (int i = 1; i <= n; ++i)
        {
            while (s.size() && !op(s.back(), i))
                s.pop_back();
            if (s.size())
                pre[i] = s.back();
            s.push_back(i);
        }
        s.clear();
        for (int i = n; i; --i)
        {
            while (s.size() && !op(s.back(), i))
                s.pop_back();
            if (s.size())
                suf[i] = s.back();
            s.push_back(i);            
        }
    }
};

int main()
{
    int n = FastIO::rd() - 1, q = FastIO::rd();
    std::vector<int> a(n + 1);

    int last = FastIO::rd(), cur = 0;

    for (int i = 1; i <= n; ++i)
        cur = FastIO::rd(), a[i] = std::abs(cur - last), last = cur;
    auto f = [](int a, int b) { return a > b; };
    nearest_bound<int, decltype(f)> near_upper_bound(f, a);
    rmq<int, decltype(f)> max_query(f, a); 

    // pre / suf[i] : sum of interval which i is tail / head
    // s_pre / s_suf[i] : sum of interval \in [1, i] / [i, n]
    std::vector<i64> pre(n + 1), s_pre(n + 1), suf(n + 1), s_suf(n + 1);

    for (int i = 1; i <= n; ++i)
        pre[i] = pre[near_upper_bound.pre[i]] + 1ll * a[i] * (i - near_upper_bound.pre[i]), s_pre[i] = s_pre[i - 1] + pre[i];
    for (int i = n; i; --i)
        suf[i] = suf[near_upper_bound.suf[i]] + 1ll * a[i] * (near_upper_bound.suf[i] - i), s_suf[i] = s_suf[i + 1] + suf[i];
    
    std::function<i64(int, int)> solve = [&](int l, int r)
    {
        int pivot = max_query.query(l, r);
        // interval which covers pivot
        i64 cover_pivot = 1ll * (pivot - l + 1) * (r - pivot + 1) * a[pivot];
        // interval \in [l, pivot - 1]
        i64 pivot_left = (s_suf[l] - s_suf[pivot] - 1ll * (pivot - l) * suf[pivot]);
        // interval \in [pivot + 1, r]
        i64 pivot_right = (s_pre[r] - s_pre[pivot] - 1ll * (r - pivot) * pre[pivot]);
        return cover_pivot + pivot_left + pivot_right;
    };
    while (q--)
    {
        int l = FastIO::rd(), r = FastIO::rd() - 1;
        FastIO::wr(solve(l, r));
    }
}