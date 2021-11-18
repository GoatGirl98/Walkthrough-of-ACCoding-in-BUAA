#include <cstdio>
#define Min(a, b)  (((a)<(b))?(a):(b))
typedef long long ll;
const ll MaxC = (ll)1e11, MaxN = 2047, INF = MaxC * MaxN;
ll n, ans, w[MaxN], v[MaxN], arr[MaxN * 2];
inline void buildDP() {
    for (ll i = 1; i <= n + MaxN; i++)
        arr[i] = INF;
    arr[0] = 0LL;
    for (ll i = 0; i < n; i++)
        for (ll j = n + 2000; j >= v[i]; j--)
            arr[j] = Min(arr[j], arr[j - v[i]] + w[i]); //01背包模型
}
int main() {
    
    while (scanf("%lld",&n)!=EOF) {
        //先用INF填充dp数组
        for (ll i = 0; i < n; i++)
            scanf("%lld%lld", &w[i], &v[i]), v[i]++;    //时间+1
        buildDP();
        ans = INF;
        for (ll i = n; i <= n + 2000; i++)
            ans = Min(ans, arr[i]);
        printf("%lld\n", ans);
    }
}
