#include<cstdio>
#include<cstring>
#include<unordered_map>
#define maxn 24300010
#define Max(a,b) (((a)>(b))?(a):(b))
using namespace std;
typedef long long ll;
ll sum[maxn];
int Size;
int n;
ll a[31], b[31], c[31], d[31], e[31];
double p;
int freq;
ll findMode() {
	ll ret = 0;
	int cnt = 0;
	for (int i = 0; i < Size; ++i) {
		if (cnt == 0)ret = sum[i], cnt = 1;
		else {
			if (ret == sum[i])cnt++;
			else cnt--;
		}
	}
	return ret;
}
int main() {
	while (scanf("%d", &n) != EOF) {
		Size = freq = 0;
		p = 0.0;
		for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
		for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
		for (int i = 1; i <= n; ++i) scanf("%lld", &d[i]);
		for (int i = 1; i <= n; ++i) scanf("%lld", &e[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					for (int l = 1; l <= n; ++l)
						for (int m = 1; m <= n; ++m)
							sum[Size++] = (a[i] + b[j] + c[k] + d[l] + e[m]) << 1;
		ll ret = findMode();
		for (int i = 0; i < Size; ++i)
			if (sum[i] == ret)freq++;
		if (freq > (Size >> 1))printf("%lld\n", ret);
		else puts("None");
	}
}