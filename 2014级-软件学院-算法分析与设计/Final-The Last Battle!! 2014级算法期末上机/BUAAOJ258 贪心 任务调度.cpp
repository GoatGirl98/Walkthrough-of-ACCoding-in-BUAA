#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;
typedef long long ll;
struct Task {
	int x, y;
	Task(int xx = 0, int yy = 0) { x = xx, y = yy; }
	bool operator < (const Task& o) const {
		if (x != o.x)return x > o.x;
		else return y > o.y;
	}
};
int n, m;
Task a[maxn], b[maxn];
int mark[110];
ll ans;
int cnt;
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
		memset(mark, 0, sizeof(mark));
		ans = 0, cnt = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%d%d", &a[i].x, &a[i].y);
		for (int i = 1; i <= m; ++i)
			scanf("%d%d", &b[i].x, &b[i].y);
		sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
		int cur = 1;
		for (int i = 1; i <= m; ++i) {
			while (cur <= n) {
				if (a[cur].x >= b[i].x)mark[a[cur].y]++;
				else break;
				++cur;
			}
			for (int k = b[i].y; k <= 100; ++k) {
				//贪心:优先找xi yi最小的
				if (mark[k]) {
					mark[k]--;
					ans += 1000ll * b[i].x + 10ll * b[i].y;
					cnt++;
					break;
				}
			}
		}
		printf("%d %lld\n", cnt, ans);
	}
}
