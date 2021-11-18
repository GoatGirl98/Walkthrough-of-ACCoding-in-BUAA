//再被卡long long我就是狗
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define RADIX 10
#define maxn 400010
#define print 0
using namespace std;
typedef long long ll;
const double Pi = acos(-1.0);
int n, m, t;
int tmp;
ll res[maxn];
ll cnt[maxn];
ll dp[maxn];
struct complex {
	double x, y;
	complex(double xx = 0, double yy = 0) {
		x = xx, y = yy;
	}
}a[maxn];// , b[maxn];
complex operator + (complex a, complex b) {
	return complex(a.x + b.x, a.y + b.y);
}
complex operator - (complex a, complex b) {
	return complex(a.x - b.x, a.y - b.y);
}
complex operator * (complex a, complex b) {
	return complex(a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y);
}
int l, r[maxn];
int limit;
inline void init() {
	for (int i = 0; i < maxn; ++i) { a[i].x = a[i].y = 0.0; dp[i] = res[i] = cnt[i] = 0; }
}
inline void getLimitRev() {
	limit = 1;
	l = 0;
	while (limit <= 200000) { limit <<= 1, ++l; }//多项式专用，此处的小于还是小于等于要看n和m的意义
	//while (limit < N + M)limit <<= 1, ++l;//高精专用，N，M仅指位数
	for (int i = 0; i < limit; ++i) {
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	}
}
inline void FFT(complex* C, double type) {
	for (int i = 0; i < limit; ++i)
		if (i < r[i])swap(C[i], C[r[i]]);
	for (int mi = 1; mi < limit; mi <<= 1) {
		int len = mi << 1;
		complex Wn(cos(Pi / mi), type * sin(Pi / mi));
		for (int j = 0; j < limit; j += len) {
			complex w(1, 0);
			for (int k = 0; k < mi; ++k, w = w * Wn) {
				complex x = C[j + k], y = w * C[j + mi + k];
				C[j + k] = x + y;
				C[j + mi + k] = x - y;
			}
		}
	}
}
inline int read() {
	int k = 0;
	char c = getchar();
	while (!isdigit(c))c = getchar();
	while (isdigit(c)) { k = (k << 1) + (k << 3) + c - 48; c = getchar(); }
	return k;
}
inline void write(ll a) {
	if (a >= RADIX)write(a / RADIX);
	putchar(a % RADIX + 48);
}
int main() {
	t = read();
	getLimitRev();
	while (t--) {
		n = read(); m = read();
		init();
		for (int i = 1; i <= n; ++i) {
			tmp = read();
			cnt[tmp]++;
			a[tmp].x += 1.0;
		}
		FFT(a, 1);
		for (int i = 0; i <= limit; ++i)a[i] = a[i] * a[i];
		FFT(a, -1);
		for (int i = 0; i < maxn ; ++i) {
			res[i] = (ll)(a[i].x / limit + 0.5);
			if (i % 2 == 0)res[i] -= cnt[(i >> 1)];
			res[i] /= 2;
		}
		//多项式乘法需要考虑0的问题
		dp[0] = res[0];
		for (int i = 1; i < maxn; ++i) {
			dp[i] = dp[i - 1] + res[i];
		}
		for (int i = 0; i < m; ++i) {
			tmp = read();
			write(dp[tmp - 1]); 
			putchar('\n');
		}
	}
}
