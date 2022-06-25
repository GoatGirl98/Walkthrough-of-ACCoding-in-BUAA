#include <stdio.h>
#define maxn 510
typedef long long ll;
const double INF = 114514191981.0;
int n;
double p[maxn], q[maxn]; //内部节点和外部节点的频率
double e[maxn][maxn];    // ki..kj的搜索频率总和
double w[maxn][maxn];
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
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])
                    e[i][j] = t; // rt[i][j] = r;
            }
        }
    }
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%lf", &p[i]);
        for (int i = 0; i <= n; ++i)
            scanf("%lf", &q[i]);
        buildDP();
        printf("%.3f\n", e[1][n]);
    }
}