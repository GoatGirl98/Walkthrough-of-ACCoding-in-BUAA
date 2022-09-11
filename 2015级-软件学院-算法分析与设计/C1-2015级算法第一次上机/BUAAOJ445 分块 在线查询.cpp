#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <vector>
#include <numeric>
#include <algorithm>
typedef unsigned long long u64;
typedef std::size_t usize;
bool eof_flag;
bool rd(int *s)
{
    if (eof_flag)
        return 0;
    int k = 0, f = 1;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
    {
        if (c == EOF)
        {
            eof_flag = 1;
            return 0;
        }
        c = getchar();
    }
    f = (c == '-') ? -1 : 1;
    k = (c == '-') ? 0 : (c ^ 48);
    c = getchar();
    while (c >= '0' && c <= '9')
        k = (k << 1) + (k << 3) + (c ^ 48), c = getchar();
    if (c == EOF)
        eof_flag = 1;
    (*s) = f > 0 ? k : -k;
    return 1;
}
void wr(u64 x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
class range_inversions_query
{

    class bucket_type
    {
    public:
        std::vector<usize> rank;
        std::vector<usize> sorted_ind;
        std::vector<u64> prefix_inv;
        std::vector<u64> block_inv;
        std::vector<usize> freq;
    };

    usize bsize;
    std::vector<bucket_type> buckets;

public:
    range_inversions_query(const std::vector<usize> &rank)
    {
        const usize n = rank.size();
        bsize = std::sqrt(n) + 1;
        buckets = std::vector<bucket_type>(n / bsize + 1);

        std::vector<usize> freq(n, 0);
        for (usize r = 0; r != buckets.size(); ++r)
        {
            bucket_type &b = buckets[r];

            b.rank = std::vector<usize>(rank.begin() + r * bsize,
                                        rank.begin() + std::min(n, (r + 1) * bsize));
            const usize m = b.rank.size();

            {
                b.sorted_ind = std::vector<usize>(m);
                std::iota(b.sorted_ind.begin(), b.sorted_ind.end(),
                          static_cast<usize>(0));
                std::sort(b.sorted_ind.begin(), b.sorted_ind.end(),
                          [&b](const usize l, const usize r)
                          {
                              return b.rank[l] < b.rank[r];
                          });
            }

            {
                b.freq = std::vector<usize>(n + 1);
                b.freq[0] = 0;
                for (usize i = 0; i != n; ++i)
                    b.freq[i + 1] = b.freq[i] + freq[i];
                for (const usize e : b.rank)
                    ++freq[e];
            }

            {
                b.prefix_inv = std::vector<u64>(m);
                u64 inv = 0;
                for (usize i = 0; i != m; ++i)
                {
                    b.prefix_inv[i] = inv;
                    for (usize j = 0; j != i; ++j)
                        if (b.rank[j] > b.rank[i])
                            ++inv;
                }

                if (r + 1 == buckets.size())
                    b.prefix_inv.push_back(inv);
                else
                {
                    buckets[r + 1].block_inv = std::vector<u64>(r + 1);
                    buckets[r + 1].block_inv[r] = inv;
                    for (usize l = r; l != 0;)
                    {
                        --l;
                        const bucket_type &a = buckets[l];
                        usize ri = 0;
                        for (const usize i : a.sorted_ind)
                        {
                            while (ri != b.sorted_ind.size() && b.rank[b.sorted_ind[ri]] < a.rank[i])
                                ++ri;
                            inv += ri;
                        }
                        buckets[r + 1].block_inv[l] = b.block_inv[l] + inv;
                    }
                }
            }
        }
    }

    u64 inversions(const usize first, const usize last) const
    {
        const usize fq = first / bsize;
        const usize fr = first % bsize;
        const usize lq = last / bsize;
        const usize lr = last % bsize;
        const bucket_type &fb = buckets[fq];
        const bucket_type &lb = buckets[lq];

        if (fq == lq)
        {
            u64 ret = fb.prefix_inv[lr] - fb.prefix_inv[fr];
            usize sum = 0;
            for (const usize i : fb.sorted_ind)
            {
                if (i < fr)
                    ret -= sum;
                else if (i < lr)
                    ++sum;
            }
            return ret;
        }
        else
        {
            u64 ret = lb.block_inv[fq];
            for (usize i = 0; i != fr; ++i)
                ret -= lb.freq[fb.rank[i]] - fb.freq[fb.rank[i]];
            ret += static_cast<u64>(fr) * (fr - 1) / 2;
            ret -= fb.prefix_inv[fr];
            ret += lb.prefix_inv[lr];
            ret += static_cast<u64>(lq - fq) * bsize * lr;
            for (usize i = 0; i != lr; ++i)
                ret -= lb.freq[lb.rank[i]] - fb.freq[lb.rank[i]];
            {
                usize sum = 0;
                auto itr = lb.sorted_ind.begin();
                const auto end = lb.sorted_ind.end();
                for (const usize i : fb.sorted_ind)
                {
                    while (itr != end && lb.rank[*itr] < fb.rank[i])
                    {
                        if (*itr < lr)
                            ++sum;
                        ++itr;
                    }
                    if (i < fr)
                        ret -= sum;
                }
            }
            return ret;
        }
    }
};
int n, q;
std::vector<int> a;
int x, l, r;
int main()
{
    while (rd(&n))
    {
        a.resize(n);
        for (int i = 0; i < n; ++i)
            rd(&x), a[i] = x;
        const auto riq = [&]()
        {
            std::vector<std::size_t> b(n), c(n);
            std::iota(b.begin(), b.end(), 0);
            std::stable_sort(b.begin(), b.end(),
                             [&](auto l, auto r)
                             { return a[l] < a[r]; });
            for (int i = 0; i != n; ++i)
                c[b[i]] = i;
            return range_inversions_query(c);
        }();
        rd(&q);
        while (q--)
        {
            rd(&l), rd(&r);
            wr(riq.inversions(l, r + 1)), putchar('\n');
        }
    }
}