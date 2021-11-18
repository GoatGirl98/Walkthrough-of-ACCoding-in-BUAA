
#include<cstdio>
#define MOD 1000000007
#define print 0
using namespace std;
typedef long long ll;
ll AmulBmodP(ll a, ll b, ll c) {
    ll ans = 0;
    for (; b; b >>= 1) {
        if (b & 1)ans = (ans + a) % c;
        a = a * 2 % c;
    }
    return ans;
}
ll mul(ll a, ll b, ll c)
{
    ll C = (a * b) - (ll)((long double)a * b / c + 0.5) * c;
    return C < 0 ? C + c : C;
}
ll ksm(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while (b)
    {
        if (b & 1)ans = mul(ans, a, c);
        b >>= 1;
        a = mul(a, a, c);
    }
    return ans;
}
ll n, count2, count3;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        count2 = 0, count3 = 0;
        scanf("%lld", &n);
        if (n == 1)puts("1");
        else if (n == 2)puts("2");
        //else if (n == 3)puts("3");
        //else if (n == 4)puts("4");
        //else if (n == 5)puts("6");
        else {
            if (n % 3 == 1) {
                count3 = n / 3 - 1;
                count2 = 2;
            }
            else if(n % 3 == 2) {
                count3 = n / 3;
                count2 = 1;
            }
            else {
                count3 = n / 3;
                count2 = 0;
            }
            if (print)printf("count2 is %lld count3 is %lld\n", count2, count3);
            printf("%lld\n", AmulBmodP(ksm(2, count2, MOD), ksm(3, count3, MOD), MOD));
        }
    }
    return 0;
}
