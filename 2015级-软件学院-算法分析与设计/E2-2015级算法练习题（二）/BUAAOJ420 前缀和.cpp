#include<cstdio>
#include<unordered_map>
#define mp make_pair
using namespace std;
const int maxn = 5000000 + 10;
int n;
int tmp;
//int a[maxn];
unordered_map<int, int> map;
typedef unordered_map<int, int>::iterator IT;
inline void write(int x) {
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}
int main() {
	while (scanf("%d", &n) != EOF) {
		map.clear();
		if (n == 1) { tmp = read(); putchar('0'); putchar('\n'); continue; }
		else {
			int sum = 0, ans = 0;
			map[0] = -1;
			for (int i = 0; i < n; ++i) {
				tmp = read();
				if (tmp + 1)++sum;
				else --sum;
				IT it = map.find(sum);
				if (it != map.end()) {
					int d = i - it->second;
					if (d > ans)ans = d;
				}
				else map.insert(mp(sum, i));
			}
			write(ans), putchar('\n');
		}
	}
}