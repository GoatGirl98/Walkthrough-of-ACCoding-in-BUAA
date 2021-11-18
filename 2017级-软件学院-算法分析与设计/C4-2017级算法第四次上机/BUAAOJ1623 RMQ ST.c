#include <stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define maxn (200000 + 10)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
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
    if (f > 0)
        return k;
    else
        return -k;
}
void wr(int x)
{
    if (x < 0)
        x = -x, putchar('-');
    if (x >= 10)
        wr(x / 10);
    putchar((x % 10) + '0');
}
int st_max[maxn][22];//, st_min[maxn][22];
int log2[maxn];
int n, q;
int ST(int l, int r)
{
    int s = log2[r - l + 1], x;//, y;
    //log2(r-l+1)是以2为底的对数，写成等式就是，2的log2(r-l+1)次方等于(r-l+1);
    x = max(st_max[l][s], st_max[r - (1 << s) + 1][s]); //区间最大
    //y = min(st_min[l][s], st_min[r - (1 << s) + 1][s]); //区间最小
    return x;
}
int main()
{
    n = rd();
    for (int i = 1; i <= n; ++i)
        log2[i] = log2[i - 1] + ((1 << (log2[i - 1] + 1)) == i);
    for (int i = 1; i <= n; i++)
        st_max[i][0] = rd();
        //st_min[i][0] = st_max[i][0] = rd();
    q = rd();
    for (int i = 1; i <= 21; i++)
        for (int k = 1; k + (1 << i) <= n + 1; k++)
            st_max[k][i] = max(st_max[k][i - 1], st_max[k + (1 << (i - 1))][i - 1]);
            //st_min[k][i] = min(st_min[k][i - 1], st_min[k + (1 << (i - 1))][i - 1]);
    while (q--)
    {
        int l = rd(), r = rd();
        wr(ST(l, r)), putchar('\n');
    }
    return 0;
}
