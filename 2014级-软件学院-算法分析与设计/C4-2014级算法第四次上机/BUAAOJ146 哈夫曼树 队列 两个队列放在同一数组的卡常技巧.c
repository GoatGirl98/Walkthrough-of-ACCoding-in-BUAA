#include <stdio.h>
#include <string.h>
typedef long long ll;
#define maxn 1010
#define maxv 2010
const int INF = 1145141919;
int t;
int n, sz;
char s[maxv];
int cnt[maxn];
int bucket[maxv];
int a[maxn];
// int cnt[2], front[2], rear[2];
int solve(int a[], int n)
{
    int ret = 0, tmp = 0;
    for (int loop = 0, idx_1 = 0, idx_2 = 0; loop < n - 1; ++loop)
    {
        tmp = 0;
        for (int j = 1; j <= 2; ++j)
            tmp += (idx_1 == n || (idx_2 < loop && a[idx_2] < a[idx_1])) ? a[idx_2++] : a[idx_1++];
        a[loop] = tmp, ret += tmp;
    }
    return ret;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt)), sz = 0;
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; ++i)
            ++cnt[s[i]];
        for (int i = 0; i < 256; ++i)
            if (cnt[i])
                ++bucket[cnt[i]];
        for (int i = 1; i < maxv; ++i)
            while (bucket[i])
                a[sz++] = i, --bucket[i];
        printf("%d\n", solve(a, sz));
    }
}