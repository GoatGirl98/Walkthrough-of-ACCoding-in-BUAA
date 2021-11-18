#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define print 0
#define MOD 1000000007
using namespace std;
typedef long long ll;
/*************************************
����ת��:
�ҵ�����Կ�׵ķ��䷽��
ʹ��x�����У�����k-1�����޷���ȫ����
����k���˿���

��k-1����֮��ʣ��x-k-1��
������ǰ��k-1���˶�û�е�Կ��
������һ�ѹ���Կ��
����Կ��Ӧ��Ҳ����������ͬ��
Ҳ����˵������Կ�ף������ĸ���
�����(x,x-k+1)ÿ�ֹ���Կ��x-k+1
*************************************/

inline ll mul(ll a, ll b, ll c)
{
    ll C = (a * b) - (ll)((long double)a * b / c + 0.5) * c;
    return C < 0 ? C + c : C;
}
inline ll ksm(ll a, ll b, ll c)
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
ll AmulBmodP(ll a, ll b, ll c) {
    ll ans = 0, exp = a % c;
    for (; b; b >>= 1) {
        if (b & 1)ans = (ans + exp) % c;
        exp = exp * 2 % c;
    }
    if (print)printf("return %lld\n", ans);
    return ans;
}
ll combination(int m, int n) {
    if ((n << 1) > m)return combination(m, m - n);
    ll a = 1, b = 1;
    for (int i = 1, j = m; i <= n; ++i, --j) {
        a = (a * i) % MOD;
        b = (b * j) % MOD;
    }
    ll c = ksm(a, MOD - 2, MOD);
    ll d = (b * c) % MOD;
    return d;
}
int t;
int x, k;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &x, &k);
        k--;
        ll c = combination(x, k);
        ll d = AmulBmodP(c,x-k,MOD);
        printf("%lld %lld\n", c, d);
    }
}


