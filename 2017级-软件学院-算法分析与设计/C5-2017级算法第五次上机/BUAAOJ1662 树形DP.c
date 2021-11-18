#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return k * f;
}
void wr(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + 48);
}
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
int n;
int happiness[6005];
struct edge
{
    int to, next;
} edges[6005];
int go, head[6005], indegree[6005];
int queue[6005], front, rear, dp[6005][2];
void add(int a, int b)
{
    ++go;
    edges[go].next = head[a];
    edges[go].to = b;
    head[a] = go;
}
int main()
{
    n = rd();
    for (int i = 1; i <= n; i++)
    {
        happiness[i] = rd();
        dp[i][1] += happiness[i];
    }
    int a, b, to;
    for (int i = 1; i < n; i++)
    {
        a = rd(), b = rd();
        add(a, b);
        indegree[b]++;
    }
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            queue[front++] = i;
    for (int i = 1; i < n; i++)
    {
        a = queue[rear++];
        for(b = head[a]; b; b = edges[b].next)
        {
            to = edges[b].to;
            dp[to][0] += max(dp[a][0], dp[a][1]);
            dp[to][1] += dp[a][0];
            indegree[to]--;
            if (!indegree[to])
                queue[front++] = to;
            b = edges[b].next;
        }
    }
    wr(max(dp[queue[rear]][0], dp[queue[rear]][1]));
}
