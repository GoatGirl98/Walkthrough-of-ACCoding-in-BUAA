#include<stdio.h>
#include<math.h>
#define min(a, b) (a < b ? a : b)
typedef long long ll;
ll A[1000010], B[1000010], n;
double inv[1000010];
void wr(ll x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + 48);
}
ll solve(ll n) {
    ll lim = sqrt(n) + 1;

    if (n <= 10)
        return (n >= 2) + (n >= 3) + (n >= 5) + (n >= 7);

    for (int i = 1; i <= lim; i++)
        inv[i] = 1.0 / i, A[i] = (n / i + 1) / 2, B[i] = (i + 1) / 2 - (i == 1);

    for (int i = 3; i <= lim; i++)
        if (B[i] != B[i - 1]) {
            int l = B[i - 1], j = 1;

            for (; i * j <= lim; j += 2)
                A[j] -= A[i * j] - l;

            double tmp = n / i;

            for (int s = min(n / i / i, lim); j <= s; j += 2)
                A[j] -= B[(int)(tmp * inv[j] + 1e-7)] - l;

            for (int j = lim / i; j >= i; j--)
                for (int k = 0; k < i; k++)
                    B[j * i + k] -= B[j] - l;
        }
    inv[1] = B[1] = 0;
    for (int i = 2; i <= lim; i++)
        inv[i] = A[i] = B[i] = 0;
    return A[1];
}

int main() {
    while (scanf("%lld", &n) != EOF)
        printf("%lld\n", solve(n));
    return 0;
}
