// O(nlogn) solution by koosaga
// https://www.acmicpc.net/problem/18237
// http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/0211028.pdf
// http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/0213017.pdf
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <random>
#include <stack>
#include <queue>
#include <chrono>
using namespace std;
const int maxn = 200005;
typedef long long ll;
typedef __int128 lll;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub) { return uniform_int_distribution<int>(lb, ub)(rng); }

namespace hu_shing
{
    struct arc
    {
        int first, second;
        ll A, B;
        arc() : first(0), second(0), A(0), B(0) {}
        arc(int x, int y) : first(x), second(y), A(0), B(0) {}
        bool operator<(const arc &a) const { return (lll)A * a.B < (lll)B * a.A; }
        bool operator<=(const arc &a) const { return (lll)A * a.B <= (lll)B * a.A; }
    };
    struct node
    {
        node *son[2];
        arc val;
        node()
        {
            son[0] = son[1] = NULL;
        }
        node(arc a)
        {
            son[0] = son[1] = NULL;
            val = a;
        }
    };
    node *merge(node *x, node *y)
    {
        if (!x)
            return y;
        if (!y)
            return x;
        if (x->val < y->val)
            swap(x, y);
        int rd = randint(0, 1);
        x->son[rd] = merge(x->son[rd], y);
        return x;
    }

    ll solve(vector<ll> w)
    {
        int n = sz(w);
        if (n <= 2)
            return 0;
        // One sweep.
        vector<arc> arcs;
        {
            vector<int> stk;
            rotate(w.begin(), min_element(all(w)), w.end());
            for (int i = 0; i < n; i++)
            {
                while (sz(stk) >= 2 && w[stk.back()] > w[i])
                {
                    arcs.emplace_back(stk[sz(stk) - 2], i);
                    stk.pop_back();
                }
                stk.push_back(i);
            }
            for (int i = 2; i < sz(stk) - 1; i++)
            {
                arcs.emplace_back(0, stk[i]);
            }
            if (sz(arcs) > n - 3)
                arcs.resize(n - 3);
        }
        // Build the tree.
        vector<vector<int>> gph(n - 2);
        {
            w.push_back(w[0]);
            arcs.emplace_back(0, n);
            sort(all(arcs), [&](const arc &a, const arc &b)
                 { return pair<int, int>(a.first, -a.second) < pair<int, int>(b.first, -b.second); });
            auto in = [&](arc a, arc b)
            {
                return a.first <= b.first && b.second <= a.second;
            };
            vector<int> stk;
            for (int i = 0; i < sz(arcs); i++)
            {
                while (sz(stk) && !in(arcs[stk.back()], arcs[i]))
                {
                    stk.pop_back();
                }
                if (sz(stk))
                {
                    gph[stk.back()].push_back(i);
                }
                stk.push_back(i);
            }
        }
        // Calculate.
        ll ans = 0;
        {
            // Helpers.
            vector<ll> sum(n + 1);
            vector<vector<int>> left_idx(n + 1), right_idx(n + 1);
            vector<node *> pq(n - 2);
            for (int i = 1; i <= n; i++)
            {
                sum[i] = sum[i - 1] + w[i] * w[i - 1];
            }
            auto consec = [&](arc a)
            {
                int x = a.first, y = a.second;
                return sum[y] - sum[x] - w[x] * w[y];
            };
            auto push = [&](int idx, arc a)
            {
                left_idx[a.first].push_back(a.second);
                right_idx[a.second].push_back(a.first);
                pq[idx] = merge(pq[idx], new node(a));
            };
            auto pop = [&](int idx)
            {
                arc a = pq[idx]->val;
                pq[idx] = merge(pq[idx]->son[0], pq[idx]->son[1]);
                left_idx[a.first].pop_back();
                right_idx[a.second].pop_back();
            };
            for (int i = n - 3; i >= 0; i--)
            {
                if (sz(gph[i]) == 0)
                {
                    int pos = arcs[i].first;
                    arcs[i].A = w[pos] * w[pos + 1] * w[pos + 2];
                    arcs[i].B = consec(arcs[i]);
                    ans += arcs[i].A;
                    push(i, arcs[i]);
                    continue;
                }
                arcs[i].B = consec(arcs[i]);
                for (auto &j : gph[i])
                {
                    arcs[i].B -= consec(arcs[j]);
                    pq[i] = merge(pq[i], pq[j]);
                }
                int x = arcs[i].first, y = arcs[i].second;
                int low = w[x] <= w[y] ? x : y;
                int lowp = (low == 0 ? n : low);
                while (pq[i] && pq[i]->val.A >= w[low] * pq[i]->val.B)
                {
                    ans -= pq[i]->val.A;
                    arcs[i].B += pq[i]->val.B;
                    pop(i);
                }
                arcs[i].A = arcs[i].B + w[x] * w[y];
                if (x == low)
                    arcs[i].A -= w[x] * w[x + 1];
                if (y == lowp)
                    arcs[i].A -= w[y] * w[y - 1];
                {
                    int rmin = (sz(left_idx[low]) ? left_idx[low].back() : -1);
                    int lmax = (sz(right_idx[lowp]) ? right_idx[lowp].back() : -1);
                    if (~rmin && rmin <= y)
                    {
                        arcs[i].A += w[low] * w[low + 1] - w[low] * w[rmin];
                    }
                    if (~lmax && lmax >= x)
                    {
                        arcs[i].A += w[lowp] * w[lowp - 1] - w[low] * w[lmax];
                    }
                }
                arcs[i].A *= w[low];
                ans += arcs[i].A;
                while (pq[i] && arcs[i] <= pq[i]->val)
                {
                    arcs[i].A += pq[i]->val.A;
                    arcs[i].B += pq[i]->val.B;
                    ;
                    pop(i);
                }
                push(i, arcs[i]);
            }
        }
        return ans;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<ll> v(n + 1);
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &v[i], &v[i + 1]);
    printf("%lld\n", hu_shing::solve(v));
}