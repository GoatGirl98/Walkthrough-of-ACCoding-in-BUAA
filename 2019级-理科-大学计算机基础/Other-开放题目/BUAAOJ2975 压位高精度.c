#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef long long ll;
const ll radix = 100000000;
typedef struct BigInteger {
	ll num[150];
	int size;
}BigInteger;

BigInteger Minus(BigInteger a, BigInteger b) {
	BigInteger c = a;
	int i = 0;
	for (i = 1; i <= c.size; ++i) {
		c.num[i] -= b.num[i];
		if (c.num[i] < 0) {
			c.num[i + 1] -= 1;
			c.num[i] += radix;
		}
	}
	while (!c.num[c.size] && c.size) --c.size;
	return c;
}

BigInteger right_one(BigInteger a) {
	BigInteger c = a;
	int i = 0;
	for (i = c.size; i > 0; --i) {
		c.num[i - 1] += (c.num[i] & 1ll) * radix;
		c.num[i] >>= 1;
	}
	c.num[0] = 0;
	while (!c.num[c.size] && c.size)--c.size;
	return c;
}

BigInteger right(BigInteger a, int b) {
	BigInteger c = a;
	int k = 0;
	for (k = 0; k < b; ++k) {
		int i = 0;
		for (i = c.size; i > 0; --i) {
			c.num[i - 1] += (c.num[i] & 1ll) * radix;
			c.num[i] >>= 1;
		}
		c.num[0] = 0;
	}
	while (!c.num[c.size] && c.size)--c.size;
	return c;
}

BigInteger left(BigInteger a, int b) {
	BigInteger c = a;
	int k = 0;
	for (k = 0; k < b; ++k) {
		int i = 0;
		for (i = 1; i <= c.size; ++i) c.num[i] <<= 1;
		for (i = 1; i <= c.size; ++i) {
			if (c.num[i] >= radix) {
				c.num[i] -= radix;
				c.num[i + 1]++;
			}
		}
		if (c.num[c.size + 1]) c.size++;
	}
	return c;
}

bool Bigger(BigInteger a, BigInteger b) {
	if (a.size != b.size)return a.size > b.size;
	int i = 0;
	for (i = a.size; i; --i)
		if (a.num[i] != b.num[i])
			return a.num[i] > b.num[i];
	return 0;
}

BigInteger gcd(BigInteger a, BigInteger b) {
	int r = 0;
	while (!(a.num[1] & 1 || b.num[1] & 1)) {
		a = right(a, 1);
		b = right(b, 1);
		++r;
	}
	while (1) {
		while (!(a.num[1] & 1)) a = right(a, 1);
		while (!(b.num[1] & 1)) b = right(b, 1);
		if (Bigger(a, b)) a = Minus(a, b);
		else b = Minus(b, a);
		if (a.size == 0) return left(b, r);
		if (b.size == 0) return left(a, r);
	}
}

char s[10010];

void read(struct BigInteger* a) {
	scanf("%s", s);
	int len = strlen(s);
	a->size = 0;
	long long wid = 1, cur = 0;
	int i;
	for (i = len - 1; i + 1; --i) {
		cur += (s[i] ^ '0') * wid;
		wid = wid * 10;
		if (wid == radix) {
			wid = 1;
			a->num[++a->size] = cur;
			cur = 0;
		}
	}
	if (cur) a->num[++a->size] = cur;
}

void print(BigInteger* a) {
	printf("%lld", a->num[a->size]);
	int i = 0;
	for (i = a->size - 1; i > 0; --i)//0处不放东西,就算答案是0也没问题
		printf("%08lld", a->num[i]);
	putchar('\n');
}

struct BigInteger a, b, res;

int main() {
	read(&a);
	read(&b);
	res = gcd(a, b);
	print(&res);
}