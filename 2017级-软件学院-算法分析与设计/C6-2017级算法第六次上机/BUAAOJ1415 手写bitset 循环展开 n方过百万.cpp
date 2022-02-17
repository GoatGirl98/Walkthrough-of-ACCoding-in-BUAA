#include <stdio.h>
#include <algorithm>
using namespace std;
struct fastIO
{
    static const int BUFF_SZ = 1 << 18;
    char inbuf[BUFF_SZ], outbuf[BUFF_SZ];
    fastIO()
    {
        setvbuf(stdin, inbuf, _IOFBF, BUFF_SZ);
        setvbuf(stdout, outbuf, _IOFBF, BUFF_SZ);
    }
} IO;
// block-bitset
long long f1[64][14063], f2[64][14063];

inline void set(long long f[][14063], int idx)
{
    if (idx < 64)
        for (int register i = 0; i <= idx; ++i)
            *f[i] |= 1ll << (idx - i);
    else
        for (int register i = 0; i < 64; ++i)
        {
            register int j = idx - i;
            f[i][j >> 6] |= 1ll << (j & 63);
        }
}

int n, m;
char s1[100010], s2[100010];

inline void init()
{
    for (int register i = 0; i < n; ++i)
        switch (s1[i])
        {
        case 'R':
            set(f1, i * 3);
            break;

        case 'S':
            set(f1, i * 3 + 1);
            break;

        case 'P':
            set(f1, i * 3 + 2);
            break;
        }
    for (int register i = 0; i < m; ++i)
        switch (s2[i]) {
        case 'R':
            set(f2, i * 3 + 1);
            break;

        case 'S':
            set(f2, i * 3 + 2);
            break;

        case 'P':
            set(f2, i * 3);
            break;
        }
}

inline unsigned solve(unsigned st_A, unsigned st_B, unsigned len)
{
    st_A *= 3, st_B *= 3, len *= 3;
    register int l = len >> 6, tim = l >> 3;
    register long long *p1 = f1[st_A & 63] + (st_A >> 6), *p2 = f2[st_B & 63] + (st_B >> 6);
    register unsigned ans0 = 0, ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0, ans7 = 0;

    while (tim--)
    {
        ans0 += __builtin_popcountll(p1[0] & p2[0]);
        ans1 += __builtin_popcountll(p1[1] & p2[1]);
        ans2 += __builtin_popcountll(p1[2] & p2[2]);
        ans3 += __builtin_popcountll(p1[3] & p2[3]);
        ans4 += __builtin_popcountll(p1[4] & p2[4]);
        ans5 += __builtin_popcountll(p1[5] & p2[5]);
        ans6 += __builtin_popcountll(p1[6] & p2[6]);
        ans7 += __builtin_popcountll(p1[7] & p2[7]);
        p1 = p1 + 8;
        p2 = p2 + 8;
    }

    switch (l & 7)
    {
    case 7:
        ans7 += __builtin_popcountll(p1[6] & p2[6]);

    case 6:
        ans6 += __builtin_popcountll(p1[5] & p2[5]);

    case 5:
        ans5 += __builtin_popcountll(p1[4] & p2[4]);

    case 4:
        ans4 += __builtin_popcountll(p1[3] & p2[3]);

    case 3:
        ans3 += __builtin_popcountll(p1[2] & p2[2]);

    case 2:
        ans2 += __builtin_popcountll(p1[1] & p2[1]);

    case 1:
        ans1 += __builtin_popcountll(p1[0] & p2[0]);
        p1 += l & 7, p2 += l & 7;
    }

    return ans0 + ans1 + ans2 + ans3 + ans4 + ans5 + ans6 + ans7 + __builtin_popcountll(*p1 & *p2 & (1ll << (len & 63)) - 1);
}
unsigned ans;
int main()
{
    scanf("%d%d%s%s", &n, &m, s1, s2);
    init();
    for (int i = 0; i < n - m + 1; ++i)
        ans = max(ans, solve(i, 0, m));
    for (int i = n - m + 1; i < n; ++i)
        ans = max(ans, solve(i, 0, n - i));
    printf("%u", ans);
}