#include<cstdio>
#include<cstring>
#include<cctype>
#define maxn 100010
#define maxm 30000010
typedef long long ll;
struct FastIO {
	char wbuf[maxm], * p_now;
	FastIO() :p_now(wbuf) {}
	inline bool ischar(const char c) {
		return c >= 33 && c <= 123;
	}
	inline int read() {
		int len = fread(wbuf, 1, maxm, stdin);
		return len;
	}
	inline int readInt() {
		int ret = 0;
		int k = 1;
		while (!isdigit(*p_now)) {
			if (*p_now == '-')k = -1;
			++p_now;
		}
		do { ret = ret * 10 + *p_now++ - '0'; } while (isdigit(*p_now));

		return ret * k;
	}
	inline char* readline() {
		while (!ischar(*p_now))
			++p_now;
		char* begin = p_now;
		while (ischar(*p_now))
			++p_now;
		*p_now = '\0';
		return begin;
	}
};
char* str[maxn];
char* tmp[maxn];
ll res;
void merge(int lo, int hi) {
	if (hi > lo) {
		int mi = (hi + lo) >> 1;
		merge(lo, mi);
		merge(mi + 1, hi);
		int bmark = lo;
		int lomark = lo;
		int himark = mi + 1;
		while (lomark <= mi || himark <= hi) {
			if ((himark > hi || strcmp(str[lomark], str[himark]) <= 0) && lomark <= mi)
				tmp[bmark++] = str[lomark++];
			else {
				tmp[bmark++] = str[himark++];//此时需要统计逆序的问题，子问题合并排序完之后就方便多了
				res += 1ll * mi - 1ll * lomark + 1ll;//表示的是左边的数组有多少个比他大的
			}
		}
		for (int i = lo; i <= hi; i++) {
			str[i] = tmp[i];
		}
	}
	return;
}
FastIO in;
int n, t;
int main() {
	in.read();
	t = in.readInt();
	while (t--) {
		res = 0;
		n = in.readInt();
		for (int i = 0; i < n; ++i)
			str[i] = in.readline();
		merge(0, n - 1);
		printf("%lld\n", res);
	}
}