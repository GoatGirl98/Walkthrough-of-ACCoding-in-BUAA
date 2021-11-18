#include <stdio.h>
#include <string.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define full 233
#define single 1
#define maxn 1010
#define maxv 200010
#define maxq 200010

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

void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}

int n, V; // V : size of pack
int cost, value, cnt;
int dp[maxv];
int deq[maxq];  // deque of index
int deqv[maxq]; // deque of value

void buildDP_01Pack(int cost, int value)
{
    for (int v = V; v >= cost; --v)
        dp[v] = max(dp[v], dp[v - cost] + value);
}

void buildDP_FullPack(int cost, int value)
{
    for (int v = cost; v <= V; ++v)
        dp[v] = max(dp[v], dp[v - cost] + value);
}

void buildDP_MultiPack(int cost, int value, int count)
{
    for (int a = 0; a < cost; ++a)
    {
        int s = 0, t = 0; // init deque
        for (int j = 0; j * cost + a <= V; j++)
        {
            int val = dp[j * cost + a] - j * value;
            while (s < t && deqv[t - 1] <= val)
                t--;                     // pop_back
            deq[t] = j, deqv[t++] = val; // push_back
            dp[j * cost + a] = deqv[s] + j * value;
            if (deq[s] == j - count)
                ++s; // pop_front
        }
    }
}

void buildDP_CombinedPack(int cost, int value, int count)
{
    if (count == single)
        buildDP_01Pack(cost, value);
    else if (count == full)
        buildDP_FullPack(cost, value);
    else
        buildDP_MultiPack(cost, value, count);
}

int main()
{
    while (rd(&n) && rd(&V))
    {
        memset(dp, 0, (V + 1) * sizeof(dp[0]));
        while (n--)
        {
            rd(&cost), rd(&value), rd(&cnt);
            buildDP_CombinedPack(cost, value, cnt);
        }
        wr(dp[V]), putchar('\n');
    }
}
