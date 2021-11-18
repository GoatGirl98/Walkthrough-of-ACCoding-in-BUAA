#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10010
typedef long long ll;
int n;
ll a[maxn];
ll tails[maxn];
int res;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)scanf("%lld", a + i);
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		int lo = 0, hi = res;
		while (lo < hi) {
			int mi = (lo + hi) >> 1;
			if (tails[mi] < a[i])lo = mi + 1;
			else hi = mi;
		}
		tails[lo] = a[i];
		if (hi == res) res++;
	}
	printf("%d\n", res);
}