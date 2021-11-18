#include<cstdio>
#include<cstring>
typedef unsigned long long ull;
ull ans;
char s[55];
int main() {
    while (scanf("%s", s) != EOF) {
        ans = 0;
        for (int i = strlen(s) - 1; i >= 0; --i) {
            ans = (ans << 1) + s[i];
        }
        printf("%llu\n", ans);
    }
}
