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
ll p[maxn], q[maxn]; //内部节点和外部节点的频率
ll e[maxn][maxn];    // ki..kj的搜索频率总和
ll w[maxn][maxn];
// int rt[maxn][maxn] // rt[i][j] ： 内部节点 i 到 j 这部分的树根是谁
void buildDP()
{
    for (int i = 1; i <= n + 1; ++i)
        e[i][i - 1] = w[i][i - 1] = q[i - 1];
    for (int k = 1; k <= n; ++k)
    {
        // 1到k有k个关键字参与构造树
        for (int i = 1; i <= n - k + 1; ++i)
        {
            int j = i + k - 1;
            e[i][j] = INF;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; ++r)
            {
                ll t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])
                    e[i][j] = t; // rt[i][j] = r;
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