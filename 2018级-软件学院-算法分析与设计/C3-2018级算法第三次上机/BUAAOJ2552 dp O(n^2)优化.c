#include <stdio.h>
#define maxn 510
typedef long long ll;
const ll INF = 1145141919810114514ll;
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
    putchar((x % 10) ^ 48);
}
ll n;
ll p[maxn], q[maxn]; // p(内部节点)和q(外部节点)的频率
ll e[maxn][maxn];    // 内部节点[i...j]所组成的子树的搜索频率总和 (包括外部节点)
ll w[maxn][maxn];    // 外部节点的搜索和
int rt[maxn][maxn];  // 内部节点[i...j]所组成的子树的树根编号
// 其中[i][i-1] 代表的是外部节点编号[i-1]对应的权值
void buildDP()
{
    for (int i = 1; i <= n + 1; ++i)
        e[i][i - 1] = w[i][i - 1] = q[i - 1];
    // get k = 1 corner case here
    for (int i = 1; i <= n; ++i)
    {
        w[i][i] = w[i][i - 1] + p[i] + q[i];
        e[i][i] = e[i][i - 1] + e[i + 1][i] + w[i][i];
        rt[i][i] = i;
    }
    for (int k = 2; k <= n; ++k)
    {
        for (int i = 1; i <= n - k + 1; ++i)
        {
            int j = i + k - 1;
            e[i][j] = INF;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            // optimize loop here with array rt
            for (int r = rt[i][j - 1]; r <= rt[i + 1][j]; ++r)
            {
                ll t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])
                    e[i][j] = t, rt[i][j] = r;
            }
        }
    }
}
int main()
{
    n = rd();
    for (int i = 1; i <= n; ++i)
        p[i] = rd();
    for (int i = 0; i <= n; ++i)
        q[i] = rd();
    buildDP();
    wr(e[1][n]), putchar('\n');
}