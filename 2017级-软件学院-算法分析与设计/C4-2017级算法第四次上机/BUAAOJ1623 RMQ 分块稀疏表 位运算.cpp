#include <stdio.h>
#include <vector>
#include <algorithm>
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
    void wr(int x, char ch = '\n')
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
std::vector<int> a;
// 1-indexed
template <typename T, typename F>
struct rmq
{
    static const int b = 4, mask = 15, B = 16;
    int n; // size of array
    std::vector<T>& a; // origin array
    std::vector<int> pre, suf; // prefix_f and suffix_f's index, record with unit B.

    std::vector<int> _log_2; // record of log_2(i)

    std::vector<std::vector<int>> st; // sparse table

    std::vector<int> masks;

    F f;

    int op(int x, int y) { return f(a[x], a[y]) ? x : (a[x] == a[y]) ? std::min(x, y) : y; }
    // least significant set bit
    int lsb(int x) { return x & (-x); }
    int msb_index(int x) { return __builtin_clz(1) - __builtin_clz(x); }

    rmq(F _f, int _n, std::vector<T>& _a) : f(_f), n(_n), a(_a), pre(_n + 1), suf(_n + 1), masks(_n + 1) { build(); }

    void build()
    {
        if (!n)
            return;
        int lim = n >> b;
        _log_2.resize(lim + 2);
        for (int i = 2; i < _log_2.size(); ++i)
            _log_2[i] = _log_2[i >> 1] + 1;

        st.resize(_log_2[lim] + 1);
        for (int i = 0; i < st.size(); ++i)
            st[i].resize(lim + 1);

        // optimize : O(1) query inside block, use it when block_size <= bit_length (int : 32 long long : 64)
        int cur_mask = 0;
        for (int i = 1; i <= n; ++i)
        {
            // preserve B bits
            cur_mask = (cur_mask << 1) & ((1 << B) - 1); 
            while (cur_mask > 0 && op(i, i - msb_index(lsb(cur_mask))) == i)
                cur_mask ^= lsb(cur_mask);
            cur_mask |= 1;
            masks[i] = cur_mask;
        }

        pre[1] = 1, suf[n] = n;
        for (int i = 2; i <= n; ++i)
            pre[i] = (i & mask) ? op(pre[i - 1], i) : i; // pre[i] = op(((i >> b) << b), ..., i)
        for (int i = n - 1; i; --i)
            suf[i] = ((~i) & mask) ? op(suf[i + 1], i) : i; // suf[i] = op(i, ..., (((i >> b) + 1) << b - 1))
        // sparse table of target element in each block
        
        for (int i = 1; i <= lim; ++i)
            st[0][i] = suf[i << b];
        for (int k = 1; lim >> k; ++k)
            for (int i = 1 << (k - 1), j = 1 << k; j <= lim; ++i, ++j)
                st[k][j] = op(st[k - 1][i], st[k - 1][j]);
    }
    // O(1) optimize
    int query_in_block(int l, int r)
    {
        int dist_from_r = msb_index(masks[r] & ((1 << (r - l + 1)) - 1));
        return r - dist_from_r;
    }

    // query after static rmq is built
    int query(int l, int r)
    {
        int belong_l = (l >> b), belong_r = (r >> b) - 1;
        if (belong_l > belong_r) // l, r in the same block.
            return query_in_block(l, r);
        else if (belong_l == belong_r) // l, r in adjacent block
            return op(suf[l], pre[r]);
        else // normal, using sparse table for whole block, suf and pre for partial block
        {
            int k = _log_2[belong_r - belong_l];
            return op(op(suf[l], pre[r]), op(st[k][belong_l + (1 << k)], st[k][belong_r]));
        }
    }
};
int main()
{
    auto f = [](int a, int b) { return a > b; };
    // auto g = [](int a, int b) { return a > b; };
    int n = FastIO::rd();
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        a[i] = FastIO::rd();
    rmq<int, decltype(f)> max_query(f, n, a);
    int q = FastIO::rd();
    // rmq<int, decltype(g)> max_query(g, n, a);
    while (q--)
    {
        int l = FastIO::rd(), r = FastIO::rd();
        FastIO::wr(a[max_query.query(l, r)]);
    }
}