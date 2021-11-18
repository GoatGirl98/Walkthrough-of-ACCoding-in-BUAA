#include<cstdio>
#include<cmath>
#include<climits>
typedef long long ll;
int main() {
    ll a, b;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        if (a > INT_MAX || a<INT_MIN || b>INT_MAX || b < INT_MIN || b == 0)puts("error");
        else if (a * b > 0)printf("%lld\n", a / b);
        else {
            if (a < 0)a = -a; else b = -b;
            printf("%lld\n", -((a + b - 1) / b));
        }
    }
}
