#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
typedef long long ll;
const int maxn = 10005;
using namespace std;
ll rd() {
	ll k = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}
void wr(ll x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}

ll now, ans[maxn];
int n, m;
ll a[maxn], disc[maxn], belong[maxn];
ll t[maxn];//BIT
struct query { 
	int l, r, id; 
	bool operator<(const query& o) const {
		if (belong[l] == belong[o.l])return r < o.r;
		return belong[l] < belong[o.l];
	}
}q[50005];

void add(int x, int val) {
	for (int i = x; i <= n; i += i & -i)
		t[i] += val;
}
ll query(int x) {
	ll sum = 0;
	for (int i = x; i; i -= i & -i)
		sum += t[i];
	return sum;
}
void solve() {
	sort(q + 1, q + m + 1);
	int l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l)
			add(a[l], -1), now -= query(a[l] - 1), l++;
		while (r > q[i].r)
			add(a[r], -1), now -= r - l - query(a[r]), r--;
		while (l > q[i].l)
			l--, add(a[l], 1), now += query(a[l] - 1);
		while (r < q[i].r)
			r++, add(a[r], 1), now += r - l + 1 - query(a[r]);
		ans[q[i].id] = now;
	}
}
void init() {
	memset(ans, 0, sizeof(ans));
	memset(a, 0, sizeof(a));
	memset(disc, 0, sizeof(disc));
	memset(belong, 0, sizeof(belong));
	memset(t, 0, sizeof(t));
	memset(q, 0, sizeof(q));
	now = 0;
}
int main() {
	while (scanf("%d", &n) != EOF) {
		init();
		ll t = sqrt(n);
		for (int i = 1; i <= n; i++)disc[i] = a[i] = rd();
		sort(disc + 1, disc + n + 1);
		int real_n = unique(disc + 1, disc + n + 1) - disc - 1;
		for (int i = 1; i <= n; i++)a[i] = lower_bound(disc + 1, disc + real_n + 1, a[i]) - disc;
		m = rd();
		for (int i = 1; i <= m; i++)
			q[i].l = rd() + 1, q[i].r = rd() + 1, q[i].id = i;
		for (int i = 1; i <= n; i++)
			belong[i] = (i - 1) / t + 1;
		solve();
		for (int i = 1; i <= m; i++)
			wr(ans[i]), putchar('\n');
	}
	return 0;
}
