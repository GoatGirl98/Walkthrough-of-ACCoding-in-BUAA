#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long i64;
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
void wr(i64 x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
struct range_inversions_query_offline
{
    static const int bucket = 350; // n <= 100000
    int array_size;
    struct query
    {
        int l, r, idx;
        bool operator<(const query &t) const
        {
            if (l / bucket != t.l / bucket)
                return l / bucket < t.l / bucket;

            else
                return ((l / bucket) & 1) ? r < t.r : r > t.r;
        }

        query(int _l = 0, int _r = 0, int _idx = 0) { l = _l, r = _r, idx = _idx; }
    };
    struct range_query
    {
        int l, r, mult, idx;
        bool type;

        range_query(int _l = 0, int _r = 0, int _mult = 0, int _idx = 0, bool _type = 0)
        {
            l = _l, r = _r, mult = _mult, idx = _idx, type = _type;
        }
    };

    vector<query> queries;
    vector<vector<int>> val1, val2;
    vector<vector<range_query>> to_add;

    vector<int> lazy, val;
    inline int get(int idx) const { return lazy[(idx - 1) / bucket] + val[idx]; }
    inline int get_bigger(int idx) const { return get(idx + 1); }
    inline int get_smaller(int idx) const { return get(1) - get(idx); }

    void update(int idx)
    {
        int bucket_idx = (idx - 1) / bucket;
        for (int i = 0; i < bucket_idx; i++)
            lazy[i]++;

        for (int i = bucket_idx * bucket + 1; i <= idx; i++)
            val[i]++;
    }

    vector<int> a;

    range_inversions_query_offline() {}
    range_inversions_query_offline(const vector<int>& _a)
    {
        int n = _a.size();
        array_size = n;
        a.resize(n + 3);
        vector<int> tmp_a(n);
        for (int i = 0; i < n; ++i)
            tmp_a[i] = _a[i];
        sort(tmp_a.begin(), tmp_a.end());
        for (int i = 0; i < n; ++i)
            a[i + 1] = lower_bound(tmp_a.begin(), tmp_a.end(), _a[i]) - tmp_a.begin() + 1;

        lazy.resize(100010);
        val.resize(100010);

        val1.resize(n + 1), val2.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            val1[i].resize(2), val2[i].resize(2);
        to_add.resize(n + 1);
    }

    vector<i64> solve(const vector<pair<int, int>> &qu)
    {
        int q = qu.size();
        queries.resize(q + 1);
        for (int i = 0; i < q; ++i)
        {
            queries[i + 1].l = qu[i].first;
            queries[i + 1].r = qu[i].second;
            queries[i + 1].idx = i + 1;
        }
        sort(queries.begin() + 1, queries.end());

        vector<i64> ans(q);

        int l = 1, r = 1;
        for (int i = 1; i <= q; i++)
        {
            if (queries[i].r > r)
                to_add[l - 1].push_back(range_query(r + 1, queries[i].r, -1, queries[i].idx, true)), r = queries[i].r;

            if (queries[i].l < l)
                to_add[r].push_back(range_query(queries[i].l, l - 1, 1, queries[i].idx, false)), l = queries[i].l;

            if (queries[i].r < r)
                to_add[l - 1].push_back(range_query(queries[i].r + 1, r, 1, queries[i].idx, true)), r = queries[i].r;

            if (queries[i].l > l)
                to_add[r].push_back(range_query(l, queries[i].l - 1, -1, queries[i].idx, false)), l = queries[i].l;
        }

        for (int i = 1; i <= array_size; i++)
        {
            update(a[i]);
            val1[i][0] = get_bigger(a[i]);
            val1[i][1] = get_smaller(a[i]);
            val2[i][0] = get_bigger(a[i + 1]);
            val2[i][1] = get_bigger(a[i + 1]);

            for (const range_query &j : to_add[i])
            {
                int add = 0;
                for (int k = j.l; k <= j.r; k++)
                    add += (j.type ? get_bigger(a[k]) : get_smaller(a[k]));

                ans[j.idx - 1] += 1ll * j.mult * add;
            }
        }

        l = r = 1;
        for (int i = 1; i <= q; i++)
        {
            if (i != 1)
                ans[queries[i].idx - 1] += ans[queries[i - 1].idx - 1];

            while (r < queries[i].r)
                ans[queries[i].idx - 1] += val2[r][0], r++;

            while (l > queries[i].l)
                ans[queries[i].idx - 1] -= val1[l - 1][1], l--;

            while (r > queries[i].r)
                ans[queries[i].idx - 1] -= val2[r - 1][0], r--;

            while (l < queries[i].l)
                ans[queries[i].idx - 1] += val1[l][1], l++;
        }

        return ans;
    }
};

int n, q;
vector<int> a;
vector<pair<int, int>> qu;
int x, l, r;
int main()
{
    while (rd(&n))
    {
        a.resize(n);
        for (int i = 0; i < n; ++i)
            rd(&x), a[i] = x;
        range_inversions_query_offline riq(a);
        rd(&q);
        qu.resize(q);
        for (int i = 0; i < q; ++i)
            rd(&l), qu[i].first = l + 1, rd(&r), qu[i].second = r + 1;
        vector<i64> ans = riq.solve(qu);
        for (int i = 0; i < q; ++i)
            wr(ans[i]), putchar('\n');
    }
}