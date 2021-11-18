#include<cstdio>
#include<cstring>
#define Max(a,b) (((a)>(b))?(a):(b))
#define maxn 210
int f[maxn];
int V;
int n;
int t[maxn], w[maxn];
inline void buildDP_01Pack(int cost, int value) {
    for (int v = V; v >= cost; --v) {
        f[v] = Max(f[v], f[v - cost] + value);
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(f, 0, sizeof(f));
        V = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", t + i, w + i), V += t[i];
        for (int i = 1; i <= n; ++i)
            buildDP_01Pack(t[i] + w[i], t[i]);
        printf("%d\n", V - f[V]);
    }
}
