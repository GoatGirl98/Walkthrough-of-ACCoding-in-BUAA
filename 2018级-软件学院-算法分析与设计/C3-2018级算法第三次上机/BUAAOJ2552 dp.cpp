#include<cstdio>
typedef long long ll;
const int maxn = 510;
const ll INF = 1145141919810114514;
inline ll read() {
    ll k = 0, f = 1;
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
ll n;
ll p[maxn], q[maxn];//内部节点和外部节点的频率
ll e[maxn][maxn];//ki..kj的搜索频率总和
ll w[maxn][maxn];
inline void buildDP() {
    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = w[i][i - 1] = q[i - 1];
    }
    for (int k = 1; k <= n; ++k) {
        //1到k有k个关键字参与构造树
        for (int i = 1; i <= n - k + 1; ++i) {
            int j = i + k - 1;
            e[i][j] = INF;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; ++r) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])e[i][j] = t;
            }
        }
    }
}
int main() {
    n = read();
    for (int i = 1; i <= n; ++i) p[i] = read();
    for (int i = 0; i <= n; ++i) q[i] = read();
    buildDP();
    printf("%lld\n", e[1][n]);
}
