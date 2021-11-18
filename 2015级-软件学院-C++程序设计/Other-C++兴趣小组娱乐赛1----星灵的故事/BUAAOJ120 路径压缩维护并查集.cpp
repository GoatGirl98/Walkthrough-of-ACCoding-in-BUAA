#include<cstdio>
#include<cstring>
#define maxn 200010
inline int read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
inline void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
int t;
int n, m;
int op, x, y;
int f[maxn], dis[maxn];
int ans;
inline void initFather() {
    for (int i = 1; i <= n; ++i)f[i] = i, dis[i] = 0;
}
inline int getFather(int x) {
    if(x == f[x])return x;
    getFather(f[x]);
    dis[x] += dis[f[x]];
    f[x] = f[f[x]];
    return f[x];
}
inline bool check(int x, int y) {
    int a = getFather(x);
    int b = getFather(y);
    if (a != b) return false;
    else return true;
}
inline void merge(int x, int y) {
    int a = getFather(x);
    int b = getFather(y);
    if (a != b) f[a] = b, dis[a] = dis[x] + dis[y] + 1;
    else if(ans > dis[x] + dis[y]) ans = dis[x] + dis[y];
}
int main() {
    n = read();
    initFather();
    ans = 1919810;
    for(int i = 1; i <= n; ++i) {
        x = i, y = read();
        merge(x, y);
    }
    write(ans + 1);
}
