#include<cstdio>
typedef long long ll;
typedef unsigned long long ull;
ull lastZeroCount(ll n) {
    ll result = 0;
    while (n) {
        n /= 5;
        result += n;
    }
    return result;
}
ll n;
int main(){scanf("%lld",&n);printf("%lld",lastZeroCount(n));}
