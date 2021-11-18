#include<cstdio>
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
        printf("%d\n", cir(n, m));
    }
}
