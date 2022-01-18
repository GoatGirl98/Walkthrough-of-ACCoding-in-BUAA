#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
typedef long long ll;
const int maxn = 100005;
const ll INF = 1145141919810114514ll;
int rd()
{
    int k = 0, f = 1;
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
    return k * f;
}
void wr(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
int N, M;
struct point
{
    int x, y, label;
    void input(int no) { x = rd(), y = rd(), label = no; }
} tmp_P[maxn], P[maxn], query_point;
bool cmp(const point &a, const point &b) 
{ 
    if (a.x != b.x)
        return a.x < b.x; 
    else
        return a.y < b.y;
}
struct dis_info
{
    ll dis; int label;
    dis_info(ll d, int no): dis(d), label(no) {}
    bool operator < (const dis_info& o) const 
    {
        if(dis != o.dis)
            return dis < o.dis;
        else 
            return label < o.label;
    }
};
ll ans;
namespace static_KD_Tree
{
    int n;
    point p[maxn];
    bool div[maxn];
    bool cmpX(const point &a, const point &b) { return a.x < b.x; }
    bool cmpY(const point &a, const point &b) { return a.y < b.y; }
    ll dis(const point &a, const point &b) { return 1ll * (b.x - a.x) * (b.x - a.x) + 1ll * (b.y - a.y) * (b.y - a.y); }
    dis_info get_dis(const point& from, const point& to) {return dis_info(dis(from, to), to.label);}
    void build(int l, int r)
    {
        if (l > r)
            return;
        int mi = (l + r) >> 1;
        int minX, minY, maxX, maxY;
        minX = min_element(p + l, p + r + 1, cmpX)->x;
        minY = min_element(p + l, p + r + 1, cmpY)->y;
        maxX = max_element(p + l, p + r + 1, cmpX)->x;
        maxY = max_element(p + l, p + r + 1, cmpY)->y;
        div[mi] = (maxX - minX >= maxY - minY);
        nth_element(p + l, p + mi, p + r + 1, div[mi] ? cmpX : cmpY);
        build(l, mi - 1), build(mi + 1, r);
    }
    void construct()
    {
        n = N;
        for (int i = 1; i <= n; ++i)
            p[i] = P[i];
        memset(div, 0, (n + 1) * sizeof(bool));
        build(1, n);
    }
    void dfs(dis_info &cur_min_dis, int l, int r, const point &a)
    {
        if (l > r)
            return;
        int mi = (l + r) >> 1;
        dis_info tmp_dis = get_dis(a, p[mi]);
        //ll tmp_dis = dis(a, p[mi]);
        //if (tmp_dis > 0) // ignore a itself
        cur_min_dis = min(cur_min_dis, tmp_dis);
        ll d = div[mi] ? (a.x - p[mi].x) : (a.y - p[mi].y);
        int l1 = l, r1 = mi - 1, l2 = mi + 1, r2 = r;
        if (d > 0)
            swap(l1, l2), swap(r1, r2);
        dfs(cur_min_dis, l1, r1, a);
        if (d * d < cur_min_dis.dis) //
            dfs(cur_min_dis, l2, r2, a);
    }
    dis_info find_min_dis(const point &a)
    {
        dis_info ret = dis_info(ans, 0);
        dfs(ret, 1, n, a);
        return ret;
    }
}
int main()
{
    int T = rd();
    while (T--)
    {
        N = rd(), ans = INF;
        for (int i = 1; i <= N; ++i)
            P[i].input(i);
        static_KD_Tree::construct();
        
        while (N--)
        {
            query_point.input(0);
            ans = min(ans, static_KD_Tree::find_min_dis(query_point).dis);
            //wr(static_KD_Tree::find_min_dis(query_point).label - 1), putchar('\n');
        }
        printf("%.3lf\n", sqrt(ans));
    }
}