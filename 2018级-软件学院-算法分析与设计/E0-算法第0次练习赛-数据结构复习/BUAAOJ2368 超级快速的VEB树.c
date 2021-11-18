#include <stdio.h>
#include <stdbool.h>
#define Max(a, b) (((a) > (b)) ? (a) : (b))
typedef long long ll;
#define getchar getchar_unlocked
#define putchar putchar_unlocked
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

    putchar(x % 10 + '0');
}
#define A 65539
#define B 300005
bool b[B];
unsigned int lc[17], rc[17], lb[A], rb[A];
unsigned short v[6][B];
void init()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 1 << i; j++)
            rb[1 << i | j] = i;

        for (int j = 0; j < 1 << (15 - i); j++)
            lb[1 << i | j << i + 1] = i;

        lc[i] = 65535 >> 16 - i, rc[i] = 65535 & (65535 << i + 1);
    }
}
void insert(int x)
{
    if (b[x])
        return;

    b[x] = 1;

    for (int i = 1; i < 6; i++, x >>= 4)
        v[i][x >> 4] |= 1 << (x & 15);
}
void erase(int x)
{
    if (!b[x])
        return;

    b[x] = 0;

    for (int i = 1; i < 6; i++, x >>= 4)
        if (v[i++][x >> 4] ^= 1 << (x & 15))
            return;
}
int min()
{
    if (!v[5][0])
        return -1;

    int i = 4, p = lb[v[5][0]];

    while (i)
        p = p << 4 | lb[v[i--][p & 65535]];

    return p;
}
int max()
{
    if (!v[5][0])
        return -1;

    int i = 4, p = rb[v[5][0]];

    while (i)
        p = p << 4 | rb[v[i--][p & 65535]];

    return p;
}
int pre(int x)
{
    if (!v[5][0])
        return -1;

    int i = 2, s = v[1][x >> 4] & lc[x & 15];

    if (s)
        return x >> 4 << 4 | rb[s];

    for (; x >>= 4, i < 6; i++)
    {
        s = v[i][x >> 4] & lc[x & 15];

        if (s)
        {
            x = x >> 4 << 4 | rb[s];

            for (int j = i - 1; j; j--)
                x = (x << 4) | rb[v[j][x]];

            return x;
        }
    }

    return -1;
}
int suf(int x)
{
    if (!v[5][0])
        return -1;

    int i = 2, s = v[1][x >> 4] & rc[x & 15];

    if (s)
        return x >> 4 << 4 | lb[s];

    for (; x >>= 4, i < 6; i++)
    {
        s = v[i][x >> 4] & rc[x & 15];

        if (s)
        {
            x = x >> 4 << 4 | lb[s];

            for (int j = i - 1; j; j--)
                x = (x << 4) | lb[v[j][x]];

            return x;
        }
    }

    return -1;
}
void test()
{
    int n, m, op, x;
    init(), n = rd(), m = rd();

    while (m--)
    {
        op = rd();

        switch (op)
        {
        case 1:
            x = rd(), insert(x);
            break;

        case 2:
            x = rd(), erase(x);
            break;

        case 3:
            wr(min()), putchar('\n');
            break;

        case 4:
            wr(max()), putchar('\n');
            break;

        case 5:
            x = rd(), wr(pre(x)), putchar('\n');
            break;

        case 6:
            x = rd(), wr(suf(x)), putchar('\n');
            break;

        case 7:
            x = rd(), wr(b[x] ? 1 : -1), putchar('\n');
            break;

        default:
            break;
        }
    }
}
ll ans;
int depth[B];
int main()
{
    int n = rd();
    init();
    insert(0), insert(n + 1);
    depth[0] = depth[n + 1] = -1;
    while(n--)
    {
        int x = rd();
        depth[x] = 1 + Max(depth[pre(x)], depth[suf(x)]);
        ans += depth[x];
        wr(ans), putchar('\n');
        insert(x);
    }

    return 0;
}
