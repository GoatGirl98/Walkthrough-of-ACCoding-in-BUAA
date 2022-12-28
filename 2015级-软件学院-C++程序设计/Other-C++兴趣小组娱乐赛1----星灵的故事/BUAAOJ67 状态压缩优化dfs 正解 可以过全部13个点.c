#include <stdio.h>
#include <stdbool.h>
#define N 14
bool g[N][N];
int n, ans;
/*
用三个整型变量来表示状态 c-列放置情况 d-对角线放置情况 rd-反对角线放置情况 其中1代表此处有皇后了
                从左到右为   低位->高位
例如          对于c状态  当前为 1 0 0
    若填了 j = 1 位 下一c状态为 1 1 0   即为 c|(1<<j)

              对于d状态  当前为 0 0 1
    若填了 j = 1 位  则首先变为 0 1 1
                    下一c状态为 0 0 1 1 即为 (d|(1<<j))<<1

              对于rd状态 当前为 1 0 1
    若填了 j = 1 位  则首先变为 1 1 1
                    下一c状态为 1 1 0   即为 (d|(1<<j))>>1
*/
void dfs(int k, int c, int d, int rd)
{ // 尝试放第k行的皇后 此时的状态为   c - 列   d - 对角   rd - 反对角
    if (k == n)
        ++ans;
    int ban = c | d | rd; // 不能填的位置
    for (int j = 0; j < n; j++)
    {
        if (ban & (1 << j))
            continue; // 此处不能放皇后
        g[k][j] = true;
        dfs(k + 1, c | (1 << j), (d | (1 << j)) << 1, (rd | (1 << j)) >> 1);
        g[k][j] = false;
    }
}
int main()
{
    scanf("%d", &n);
    dfs(0, 0, 0, 0), printf("%d", ans);
    return 0;
}