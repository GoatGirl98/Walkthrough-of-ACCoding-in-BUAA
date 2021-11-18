#include<cstdio>
#define MOD 3
int a[1000010],n;
inline void buildDP() {
    a[0] = 1, a[1] = 2, a[2] = 0;
    for (int i = 3; i < 1000010; ++i)a[i] = (a[i - 1] + a[i - 2]) % MOD;
}
int main() {
    buildDP();
    while (scanf("%d", &n) != EOF)printf("%s\n", a[n] ? "no" : "yes");
}
