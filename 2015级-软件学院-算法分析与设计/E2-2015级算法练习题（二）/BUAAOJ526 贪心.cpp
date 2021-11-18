#include<cstdio>
#include<cstring>
#include<cmath>
typedef long long ll;
const int maxn = 100010;
int n;
ll a[maxn], b[maxn];
ll suma, sumb;
ll lucky, tmp_lucky;
int ans;
int main() {
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		suma = sumb = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%lld%lld", a + i, b + i), suma += a[i], sumb += b[i];
		lucky = abs(suma - sumb);
		for (int i = 1; i <= n; ++i) {
			suma -= (a[i] - b[i]), sumb -= (b[i] - a[i]);
			tmp_lucky = abs(suma - sumb);
			if (lucky < tmp_lucky)lucky = tmp_lucky, ans = i;
			suma += (a[i] - b[i]), sumb += (b[i] - a[i]);
		}
		printf("%d\n", ans);
	}
}
