#include<cstdio>
#include<cstring>
const int maxn = 55;
typedef long long ll;
inline void swap(int& a, int& b) {
    a ^= b, b ^= a, a ^= b;
}
inline void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
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
int t;
int n, k;
ll ans;//有过滤器的情况下的答案
int u[maxn], v[maxn];//过滤器
int a[maxn * maxn][maxn], cnt;//所有即将排好的序列

inline void build_permutation(int n) {//排好n-初始序列
    for (int i = 0; i < n; ++i)a[0][i] = i + 1;
    cnt = 1;//最开始有一个已经排好序的
    for (int i = 0; i < n; ++i) {
        int tmp = a[0][i];//把这个数拎出来插到别的地方
        for (int j = 0; j < n; ++j) {
            if (j == i || j == i - 1) continue;//去重 以及上一轮建好的
            a[cnt][j] = tmp;//其实这里序列操作最快还是平衡树,但是这里的数据量显然不必要
            for (int k = 0, m = 0; k < n && m < n; ++k, ++m) {
                if (m == j)++m; if (k == i)++k;//跳过这两个
                a[cnt][m] = a[0][k];
            }
            ++cnt;
        }
    }
}
//分别表示枚举的排列,经过过滤器的深度
void dfs(int permu_num, int dep) {
    if (dep < 0) { ++ans; return; }//找到了一个这样的排列
    //剪枝:经过此过滤器,u和v所在位置不可能逆序
    if (a[permu_num][u[dep]] > a[permu_num][v[dep]]) return;
    dfs(permu_num, dep - 1);
    swap(a[permu_num][u[dep]], a[permu_num][v[dep]]);//两种回溯方式
    dfs(permu_num, dep - 1);
    swap(a[permu_num][u[dep]], a[permu_num][v[dep]]);
}
int main() {
    t = read();
    while (t--) {
        memset(a, 0, sizeof(a));
        ans = 0;
        n = read(), k = read();
        build_permutation(n);
        if (k == 0) { write(cnt), putchar_unlocked('\n'); continue; }
        for (int i = 0; i < k; ++i)
            u[i] = read() - 1, v[i] = read() - 1;
        for (int i = 0; i < cnt; ++i)
            dfs(i, k - 1);
        write(ans), putchar_unlocked('\n');
    }
}
