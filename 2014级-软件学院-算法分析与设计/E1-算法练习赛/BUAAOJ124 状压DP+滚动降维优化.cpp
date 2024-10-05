#include <stdio.h>
#include <algorithm>
#include <vector>
typedef long long i64;
const int M = 110;
const int N = 10, S = (1 << N);
int m, n, slim;

inline bool judge_sta(int sta) { return ((sta & (sta >> 1)) == 0) && ((sta & (sta >> 2)) == 0); }
inline bool judge_trans(int st, int ed) { return (st & ed) == 0; } // trans 1 row

std::vector<int> ok_sta;
std::vector<int> pre_sta[S + 10];

int popcnt[S + 10];
int dp[2][S + 10][S + 10]; // lst/now, cursta, presta
int lst, now;

inline void init_popcnt() { for (int i = 0; i < S; ++i) popcnt[i] = __builtin_popcount(i); }

void clr() 
{ 
    for (int& cur : ok_sta) for (int& pre : pre_sta[cur]) dp[0][cur][pre] = dp[1][cur][pre] = 0;
    ok_sta.clear(); for (int i = 0; i < slim; ++i) pre_sta[i].clear();
}

void solve()
{
    slim = (1 << n);
    for (int s = 0; s < slim; ++s) if (judge_sta(s)) ok_sta.push_back(s);
    for (int& cur : ok_sta) for (int& pre : ok_sta) if (judge_trans(pre, cur)) pre_sta[cur].push_back(pre);
    lst = 0, now = 1;
    for (int i = 1; i <= m; ++i, lst = 1 - lst, now = 1 - now)
    {
        for (int& cur : ok_sta)
            for (int& pre : pre_sta[cur])
            {
                if (i == 1 && pre) continue;
                dp[now][cur][pre] = 0;
                for (int& prepre : pre_sta[pre])
                    if (judge_trans(prepre, cur))
                        dp[now][cur][pre] = std::max(dp[now][cur][pre], dp[lst][pre][prepre] + popcnt[cur]);
            }
    }
    int mx = 0, cnt = 0;
    for (int& cur : ok_sta) for (int& pre : pre_sta[cur]) (dp[lst][cur][pre] > mx) ? (mx = dp[lst][cur][pre], cnt = 1) : (dp[lst][cur][pre] == mx) ? (++cnt) : (0);
    printf("%d %d\n", mx, cnt);
}

int main()
{
    init_popcnt();
    while (scanf("%d%d", &m, &n) != EOF) solve(), clr();
}
