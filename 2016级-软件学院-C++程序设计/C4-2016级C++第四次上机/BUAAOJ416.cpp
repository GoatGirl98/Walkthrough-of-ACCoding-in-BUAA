#include<cstdio>
#include<cmath>
typedef long long ll;
ll n;
bool isPrime;
int main() {
    scanf("%lld", &n);
    isPrime = true;
    ll lim = (ll)(sqrt(n) + 10);
    for (ll i = 2; i <= lim + 20; ++i)
        if (n % i == 0) { isPrime = false, printf("%lld", n / i); break; }
    if (isPrime)printf("1");
}
