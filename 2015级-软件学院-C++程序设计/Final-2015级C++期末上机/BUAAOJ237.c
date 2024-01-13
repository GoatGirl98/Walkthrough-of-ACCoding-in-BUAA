#include <stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
char eof_flag;
char rd(int *s)
{
    if (eof_flag)
        return 0;
    int k = 0, f = 1;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
    {
        if (c == EOF)
        {
            eof_flag = 1;
            return 0;
        }
        c = getchar();
    }
    f = (c == '-') ? -1 : 1;
    k = (c == '-') ? 0 : (c ^ 48);
    c = getchar();
    while (c >= '0' && c <= '9')
        k = (k << 1) + (k << 3) + (c ^ 48), c = getchar();
    if (c == EOF)
        eof_flag = 1;
    (*s) = f > 0 ? k : -k;
    return 1;
}
int n, m, q;
int a[1010][1010];
char inside(int x, int y) { return 1 <= x && x <= n && y >= 1 && y <= m; }
// direction : -1 start 0 up 1 left 2 down 3 right
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

char flag;
void dfs(int x, int y, int st_x, int st_y, int ed_x, int ed_y, int turn, int dir)
{
    if (turn > 2)
        return;
    if (x == ed_x && y == ed_y)
        flag = 1;
    if (flag)
        return;
    if (turn == 2) // important prune : can't turn anymore and couldn't get to goal
    {
        if (x != ed_x && y != ed_y)
            return;
        if (x == ed_x)
            if (!((y > ed_y && dir == 1) || (y < ed_y && dir == 3)))
                return;
        if (y == ed_y)
            if (!((x > ed_x && dir == 0) || (x < ed_x && dir == 2)))
                return;
    }
    if ((x != st_x || y != st_y) && a[x][y])
        return;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        // prune : dir can't turn 180 degree
        if (!(dir >= 0 && (i - dir == 2 || dir - i == 2)) && inside(nx, ny))
            dfs(nx, ny, st_x, st_y, ed_x, ed_y, (dir < 0 || dir == i) ? turn : turn + 1, i);
    }
}
char check(int st_x, int st_y, int ed_x, int ed_y)
{
    flag = 0;
    if (!a[st_x][st_y] || !a[ed_x][ed_y]  || a[st_x][st_y] != a[ed_x][ed_y])
        return 0;
    dfs(st_x, st_y, st_x, st_y, ed_x, ed_y, 0, -1);
    return flag;
}
int main()
{
    while (rd(&n) && rd(&m))
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                rd(&a[i][j]);
        int st_x = 0, st_y = 0, ed_x = 0, ed_y = 0;
        rd(&q);
        while (q--)
            rd(&st_x), rd(&st_y), rd(&ed_x), rd(&ed_y), puts(check(st_x, st_y, ed_x, ed_y) ? "YES" : "NO");
    }
}