#include<stdio.h>
#include<math.h>
#include<bitset>
#include<unordered_map>
using namespace std;
typedef long long ll;
namespace Meissel_Lehmer{
    const int N = 7000000, M = 7, K = 2 * 3 * 5 * 7 * 11 * 13 * 17;
    int prime[N], pi[N], phi[K + 7][M + 7], product[M + 7];
    bitset<N> p;
    unordered_map<ll, ll> mp;

    inline void init() {
        int cnt = 0;
        p.set(0), p.set(1);

        for (int i = 2; i < N; ++i) {
            if (!p.test(i)) prime[++cnt] = i;
            pi[i] = cnt;
            for (int j = 1; j <= cnt && i * prime[j] < N; ++j) {
                p.set(i * prime[j]);
                if (i % prime[j] == 0) break;
            }
        }
        product[0] = 1;
        for (int i = 0; i <= K; ++i) 
            phi[i][0] = i;
        
        for (int i = 1; i <= M; ++i) {
            product[i] = product[i - 1] * prime[i];

            for (int j = 1; j <= K; ++j) 
                phi[j][i] = phi[j][i - 1] - phi[j / prime[i]][i - 1];
            
        }
    }

    inline ll sqrt_ll(ll n) {
        ll ans = sqrt((double)n);

        while (ans * ans <= n)
            ans++;

        return ans - 1;
    }

    inline ll cbrt_ll(ll n) {
        ll ans = cbrt((double)n);

        while (ans * ans * ans <= n)
            ans++;

        return ans - 1;
    }

    ll get_euler(ll n, ll m) {
        if (m == 0)
            return n;

        if (m <= M)
            return phi[n % product[m]][m] + n / product[m] * phi[product[m]][m];

        if (n <= prime[m] * prime[m])
            return pi[n] - m + 1;

        if (n <= prime[m] * prime[m] * prime[m] && n < N) {
            ll t = pi[sqrt_ll(n)], ans = pi[n] - (m + t - 2) * (t - m + 1) / 2;

            for (ll i = m + 1; i <= t; i++) {
                ans += pi[n / prime[i]];
            }

            return ans;
        }

        return get_euler(n, m - 1) - get_euler(n / prime[m], m - 1);
    }

    ll query(ll n) {
        if (n < N)
            return pi[n];

        if (mp.count(n))
            return mp[n];

        ll a = query(cbrt_ll(n)), b, c, t = sqrt_ll(n), ans;
        b = query(sqrt_ll(t));
        c = query(t);
        ans = get_euler(n, b) + (b + c - 2) * (c - b + 1) / 2;

        for (ll i = b + 1; i <= c; i++) {
            ll x = n / prime[i];
            ans -= query(x);

            if (i <= a) {
                ll t = query(sqrt_ll(x));

                for (ll j = i; j <= t; j++) {
                    ans -= query(x / prime[j]) - (j - 1);
                }
            }
        }
        return mp[n] = ans;
    }
}
ll n;
int main() {
    Meissel_Lehmer::init();
    while (scanf("%lld", &n) != EOF)
        printf("%lld\n", Meissel_Lehmer::query(n));
}
