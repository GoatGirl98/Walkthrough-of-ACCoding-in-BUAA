#include<cstdio>
#define maxn 110
int a[maxn];
int n, m;
inline int cir(int n, int m)
{
    int p = 0;
    for (int i = 2; i <= n; i++)
    {
        p = (p + m) % i;
    }
    return p + 1;
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i)scanf("%d", a + i);
        printf("%d\n", a[cir(n, m)]);
    }
}
