#include<cstdio>
typedef long long ll;
ll m, n;
inline ll a() {
    ll ret = m << (2 + n);
    if (ret >= 2000ll) {
        if (n <= 5)return 2000;
        else if (n <= 7)return 3000;
        else if (n <= 10)return 4000;
        else if (n <= 12)return 6000;
        else return 8000;
    }
    else return ret;
}
inline ll child() {
    ll ret = a();
    ll ret2 = (ret / 100) * 100;
    if (ret != ret2)return ret2 + 100;
    else return ret;
}
inline ll parent() {
    ll ret = a() << 1;
    ll ret2 = (ret / 100) * 100;
    if (ret != ret2)return ret2 + 100;
    else return ret;
}
int main() {
    while (scanf("%lld%lld", &m, &n) != EOF)
        printf("%lld.%lld\n", child(), parent());
}
