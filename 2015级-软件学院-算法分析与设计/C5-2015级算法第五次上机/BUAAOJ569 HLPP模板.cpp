#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <limits>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
#define int long long
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
int rd()
{
    int k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}

const int MAXN = 1200 + 5;
const int MAXM = 1.2e5 + 5;
template <class T = int>
struct HLPP
{
    const T INF = numeric_limits<T>::max();
    struct edge
    {
        int to, rev;
        T f;
    };

    int maxn, s, t;

    edge edges[2 * MAXM];
    int first_edge[MAXN + 1];
    int _cur_edge[MAXN];
    int nxt[MAXN];
    int lst[MAXN];
    T excess[MAXN];
    int arc[MAXN];

    int gapNxt[2 * MAXN], gapPrv[2 * MAXN];

    int height[MAXN];
    int highest, highestGap, work;
    int q[2 * MAXM];
    vector<int> degs;

    void init(vector<int>& degrees, int s, int t) {
        this->s = s;
        this->t = t;
        degs.clear();
        maxn = degrees.size();
        assert(maxn <= MAXN);
        int cnt = 0;
        memset(nxt, 0, sizeof(int) * maxn);
        memset(lst, 0, sizeof(int) * maxn);
        memset(excess, 0, sizeof(T) * maxn);
        memset(gapNxt, 0, 2 * sizeof(int) * maxn);
        memset(gapPrv, 0, 2 * sizeof(int) * maxn);
        highest = highestGap = work = 0;
        for (int i = 0; i < maxn; ++i)
        {
            _cur_edge[i] = 0;
            first_edge[i] = cnt;
            cnt += degrees[i];
        }
        first_edge[maxn] = cnt;
        copy(first_edge, first_edge + maxn + 1, _cur_edge);
        degs.swap(degrees);
        highest = highestGap = work = 0;
    }
    /*
    HLPP(vector<int> degrees, int s, int t)
    {
        this->s = s;
        this->t = t;
        maxn = degrees.size();
        assert(maxn <= MAXN);
        int cnt = 0;
        for (int i = 0; i < maxn; ++i)
        {
            first_edge[i] = cnt;
            cnt += degrees[i];
        }
        first_edge[maxn] = cnt;
        copy(first_edge, first_edge + maxn + 1, _cur_edge);
        degs.swap(degrees);
    }
    */
    void addEdge(int from, int to, int f, bool isDirected = true)
    {
        edges[_cur_edge[from]++] = { to, _cur_edge[to], f };
        edges[_cur_edge[to]++] = { from, _cur_edge[from] - 1, isDirected ? 0 : f };
    }

    void pushLst(int h, int v)
    {
        nxt[v] = lst[h];
        lst[h] = v;
    }

    void updHeight(int v, int nh)
    {
        if (height[v] != maxn)
        {
            gapNxt[gapPrv[v]] = gapNxt[v];
            gapPrv[gapNxt[v]] = gapPrv[v];
        }

        height[v] = nh;
        if (nh == maxn)
            return;

        highestGap = max(highestGap, nh);
        if (excess[v] > 0)
        {
            highest = max(highest, nh);
            pushLst(nh, v);
        }

        nh += maxn;
        gapNxt[v] = gapNxt[nh];
        gapPrv[v] = nh;
        gapNxt[nh] = v;
        gapPrv[gapNxt[v]] = v;
    }

    void globalRelabel()
    {
        work = 0;
        fill(height, height + maxn, maxn);
        fill(lst, lst + maxn, -1);
        iota(gapNxt, gapNxt + maxn, 0);
        iota(gapPrv, gapPrv + maxn, 0);
        height[t] = 0;
        q[0] = t;
        int sz = 1;
        for (size_t i = 0; i < sz; ++i)
        {
            int v = q[i];
            for (int ie = first_edge[v]; ie < first_edge[v + 1]; ++ie)
            {
                auto& e = edges[ie];
                if (height[e.to] == maxn && edges[e.rev].f > 0)
                    q[sz++] = e.to, updHeight(e.to, height[v] + 1);
            }
            highest = highestGap = height[v];
        }
    }

    void push(int v, edge& e)
    {
        T df = min(excess[v], e.f);
        if (df > 0)
        {
            if (excess[e.to] == 0)
                pushLst(height[e.to], e.to);
            e.f -= df, edges[e.rev].f += df;
            excess[v] -= df, excess[e.to] += df;
        }
    }

    void discharge(int v)
    {
        int nh = maxn;

        for (int i = arc[v]; i < first_edge[v + 1]; i++)
        {
            auto& e = edges[i];
            if (e.f > 0)
            {
                if (height[v] == height[e.to] + 1)
                {
                    push(v, e);
                    if (excess[v] <= 0)
                    {
                        arc[v] = i;
                        return;
                    }
                }
                else
                    nh = min(nh, height[e.to] + 1);
            }
        }

        for (int i = first_edge[v]; i < arc[v]; i++)
        {
            auto& e = edges[i];
            if (e.f > 0)
            {
                if (height[v] == height[e.to] + 1)
                {
                    push(v, e);
                    if (excess[v] <= 0)
                    {
                        arc[v] = i;
                        return;
                    }
                }
                else
                    nh = min(nh, height[e.to] + 1);
            }
        }

        work++;

        if (gapNxt[gapNxt[height[v] + maxn]] != height[v] + maxn)
        {
            updHeight(v, nh);
        }
        else
        {
            int oldH = height[v];
            for (int h = oldH; h < highestGap + 1; h++)
            {
                for (int i = gapNxt[h + maxn]; i < maxn; i = gapNxt[i])
                {
                    height[i] = maxn;
                }
                gapNxt[h + maxn] = gapPrv[h + maxn] = h + maxn;
            }
            highestGap = oldH - 1;
        }
    }

    T calc()
    {
        for (int v = 0; v < maxn; ++v)
        {
            sort(edges + first_edge[v], edges + first_edge[v + 1],
                [](edge& l, edge& r)
                { return l.to < r.to; });
            for (int i = first_edge[v]; i < first_edge[v + 1]; i++)
            {
                auto& e = edges[i];
                edges[e.rev].rev = i;
            }
        }

        copy(first_edge, first_edge + maxn, arc);
        fill(excess, excess + maxn, 0);
        excess[s] = INF, excess[t] = -INF;
        globalRelabel();

        for (int ie = first_edge[s]; ie < first_edge[s + 1]; ie++)
            push(s, edges[ie]);

        for (; highest >= 0; highest--)
        {
            while (lst[highest] != -1)
            {
                int v = lst[highest];
                lst[highest] = nxt[v];
                if (height[v] == highest)
                {
                    discharge(v);
                    if (work > 4 * maxn)
                        globalRelabel();
                }
            }
        }
        return excess[t] + INF;
    }
};
struct _edges
{
    int u, v, w;
    _edges(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
};
vector<_edges> input;
_edges tmp;
vector<int> degs;
int n, m, s, t;
HLPP<> hlpp;
signed main(void)
{
    while (scanf("%lld%lld", &n, &m) != EOF)
    {
        int s = 0, t = n - 1;
        input.clear(), degs.resize(n);
        for (int i = 0; i < m; ++i)
        {
            tmp.u = rd() - 1, tmp.v = rd() - 1, tmp.w = rd();
            if (tmp.w)
                ++degs[tmp.u], ++degs[tmp.v], input.push_back(tmp);
        }
        hlpp.init(degs, s, t);
        for (int i = 0; i < input.size(); ++i)
            hlpp.addEdge(input[i].u, input[i].v, input[i].w, 1);
        int ans = hlpp.calc();
        if (ans)
            wr(ans), putchar('\n');
        else
            puts("404 Not Found");
    }
    return 0;
}
