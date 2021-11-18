#include<cstdio>
#include<cstring>
const int maxn = 510;
const double full = 100.0;
int T;
int n, m, t, k;
double p;
inline int read() {
    int k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
double single_magic[maxn];//单次法术第i次操作的概率
double spin[maxn][maxn], magic[maxn][maxn];
double dp[maxn][maxn];//dp[i][j]表示还剩下i轮,还有j个箱子没开的时候的期望
//spin/magic[k][i] 表示采用转盘/法术 从k个当中开出i个箱子的概率
inline double max(double a, double b, double c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}
inline void init() {
    memset(single_magic, 0, sizeof(single_magic));
    memset(spin, 0, sizeof(spin));
    memset(magic, 0, sizeof(magic));
    memset(dp, 0, sizeof(dp));
}
inline void build_probability_spin() {
    spin[1][0] = 1.0 - p, spin[1][1] = p;
    for(int i = 2; i <= k; ++i) {
        spin[i][0] = spin[i - 1][0] * (1.0 - p);
        for(int j = 1; j <= i; ++j)
            spin[i][j] = spin[i - 1][j] * (1.0 - p) + spin[i - 1][j - 1] * p;
    }
}
inline void build_probability_magic() {
    single_magic[1] = p;
    for(int i = 2; i <= t; ++i)
        single_magic[i] = single_magic[i - 1] + (single_magic[i - 1] >= 1.0 ? 0.0 : 0.01);
    magic[1][0] = 1.0 - single_magic[1], magic[1][1] = single_magic[1];
    for(int i = 2; i <= t; ++i) {
        magic[i][0] = magic[i - 1][0] * (1.0 - single_magic[i]);
        for(int j = 1; j <= i; ++j)
            magic[i][j] = magic[i - 1][j] * (1.0 - single_magic[i]) + magic[i - 1][j - 1] * single_magic[i];
    }
}
inline void buildDP() {
    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j <= n; ++j) {
            double tmp_forfeit = dp[i - 1][j];//本轮空过
            double tmp_spin = 0.0, tmp_magic = 0.0;//采取这两种方法
            for(int x = 0; x <= k; ++x) {
                if(j >= k) tmp_spin += (dp[i - 1][j - x] + x) * spin[k][x];
                else tmp_spin += (dp[i - 1][x] + j - x) * spin[k][k - x];
            }
            for(int x = 0; x <= t; ++x) {
                if(j >= t) tmp_magic += (dp[i - 1][j - x] + x) * magic[t][x];
                else tmp_magic += (dp[i - 1][x] + j - x) * magic[t][t - x];
            }
            dp[i][j] = max(tmp_forfeit, tmp_spin, tmp_magic);
        }
    }
}

int main() {
    T = read();
    while(T--) {
        init();
        n = read(), m = read(), t = read(), k = read(), p = (double)read() / full;
        //printf("%d %d %d %d %.3f\n", n, m, t, k, p);
        build_probability_spin(), build_probability_magic();
        buildDP();
        printf("%.5f\n", dp[m][n]);
    }
}

