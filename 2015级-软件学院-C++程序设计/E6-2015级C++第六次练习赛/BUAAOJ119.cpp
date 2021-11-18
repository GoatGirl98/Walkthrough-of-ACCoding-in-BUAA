#include<cstdio>
#define MOD 12211060
int a[100010],n;
inline void buildDP() {
    a[1] = 1, a[2] = 2, a[3] = 4;
    for (int i = 4; i < 100010; ++i)a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % MOD;
}
int main() {
    buildDP();
    while (scanf("%d", &n) != EOF)printf("%d\n", a[n]);
}
