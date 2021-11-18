#include<cstdio>
typedef long long ll;
double a;
inline void print(ll a) {
    int loop = 8;
    while (loop--) {
        int x = a % 256;
        printf("%02X ", x);
        a /= 256;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf", &a);
        ll* b = (ll*)&a;
        print(*b); putchar('\n');
    }
}
