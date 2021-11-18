#include<cstdio>
#include<cstring>
typedef unsigned long long ull;
char s[15];
int main() {
    ull ans;
    ull lala;
    while (scanf("%s", s) != EOF) {
        ans = 0, lala = 1;
        for (int i = strlen(s) - 1; i >= 0; --i) {
            ans += 1ll * (s[i] - 'A' + 1) * lala;
            lala *= 26;
        }
        printf("%llu\n", ans);
    }
}
