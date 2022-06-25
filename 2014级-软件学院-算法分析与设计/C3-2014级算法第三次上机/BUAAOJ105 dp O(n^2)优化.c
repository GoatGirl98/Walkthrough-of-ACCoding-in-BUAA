#include <stdio.h>
#define maxn 510
const double INF = 114514191981.0;
int n;
double p[maxn], q[maxn]; // p(�ڲ��ڵ�)��q(�ⲿ�ڵ�)��Ƶ��
double e[maxn][maxn];    // �ڲ��ڵ�[i...j]����ɵ�����������Ƶ���ܺ� (�����ⲿ�ڵ�)
double w[maxn][maxn];    // �ⲿ�ڵ��������
int rt[maxn][maxn];  // �ڲ��ڵ�[i...j]����ɵ��������������
// ����[i][i-1] ��������ⲿ�ڵ���[i-1]��Ӧ��Ȩֵ
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
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])
                    e[i][j] = t, rt[i][j] = r;
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