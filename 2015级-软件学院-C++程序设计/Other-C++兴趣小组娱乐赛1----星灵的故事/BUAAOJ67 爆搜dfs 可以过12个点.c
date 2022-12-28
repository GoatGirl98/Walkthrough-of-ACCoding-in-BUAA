#include <stdio.h>
/*
比较经典的爆搜题，主要是要知道搜什么
首先顺着行数去搜，搜满了输出，否则接着搜
数组下标当做行数，存储列数
不能同行同列同斜线放皇后，所以要判断其是否符合条件
深搜主要在于如何做标记
当递归到下一层，放上(i,j)的时候
首先需要标记，第j列不可以放东西了
然后标记两个对角线不能放了(横纵坐标和是i+j 或者i-j+n相同)
*/
#define maxn 35
int ans[maxn];
char occupied_lie[maxn];
char occupied_left_xie[maxn];
char occupied_right_xie[maxn];
int res;
int n;
void dfs(int i)
{
    if (i > n)
    {
        ++res;
        return;
    }
 
    for (int j = 1; j <= n; ++j)
    {
        if (!(occupied_lie[j] || occupied_left_xie[i + j] || occupied_right_xie[i - j + n]))
        {
            ans[i] = j;
            occupied_lie[j] = 1;
            occupied_left_xie[i + j] = 1;
            occupied_right_xie[i - j + n] = 1;
            dfs(i + 1);
            occupied_lie[j] = 0;
            occupied_left_xie[i + j] = 0;
            occupied_right_xie[i - j + n] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    printf("%d", res);
    return 0;
}