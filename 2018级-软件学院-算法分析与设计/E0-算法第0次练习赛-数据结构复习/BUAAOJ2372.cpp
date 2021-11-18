#include<cstdio>
typedef long long ll;
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        if (n == 0)puts("0");
        else {
            ll a = 1;
            for (int i = 1; i <= n; ++i) {
                a *= (n + i), a /= i;
            }
            a /= (n + 1);
            printf("%lld\n", a);
        }
    }
}
