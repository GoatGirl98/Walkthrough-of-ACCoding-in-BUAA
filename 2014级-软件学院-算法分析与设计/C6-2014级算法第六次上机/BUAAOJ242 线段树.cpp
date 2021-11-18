#include<cstdio>
#include<cstring>
#define Lchild(x) ((x) << 1)
#define Rchild(x) (((x) << 1) + 1)
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define maxn 10010
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
struct SegmentTree {
	struct Node {
		int value_sum, value_max;
		int tag_add;
	}nodes[maxn << 2];
	void init() { memset(nodes, 0, sizeof(nodes)); }
	void pushup(int root) {
		nodes[root].value_sum = nodes[Lchild(root)].value_sum + nodes[Rchild(root)].value_sum;
		nodes[root].value_max = Max(nodes[Lchild(root)].value_max, nodes[Rchild(root)].value_max);
	}
	void build(int root, int l, int r) {
		nodes[root].tag_add = 0;
		if (l == r)nodes[root].value_sum = nodes[root].value_max = 0;
		else {
			int m = (l + r) >> 1;
			build(Lchild(root), l, m);
			build(Rchild(root), m + 1, r);
			pushup(root);
		}
	}
	void pushdown(int root, int l, int r) {
		int m = (l + r) >> 1;
		if (nodes[root].tag_add) {
			nodes[Lchild(root)].tag_add += nodes[root].tag_add;
			nodes[Rchild(root)].tag_add += nodes[root].tag_add;
			nodes[Lchild(root)].value_sum += (m - l + 1) * nodes[root].tag_add;
			nodes[Rchild(root)].value_sum += (r - m) * nodes[root].tag_add;
			nodes[Lchild(root)].value_max += nodes[root].tag_add;
			nodes[Rchild(root)].value_max += nodes[root].tag_add;
			nodes[root].tag_add = 0;
		}
	}
	void updateAdd(int root, int l, int r, int L, int R, int k) {
		if (R < l || r < L)return;
		if (L <= l && r <= R) {
			nodes[root].tag_add += k;
			nodes[root].value_sum += k * (r - l + 1);
			nodes[root].value_max += k;
			return;
		}
		pushdown(root, l, r);
		int m = (l + r) >> 1;
		if (L <= m)updateAdd(Lchild(root), l, m, L, R, k);
		if (R > m)updateAdd(Rchild(root), m + 1, r, L, R, k);
		pushup(root);
	}
	int queryMax(int root, int l, int r, int L, int R) {
		if (L <= l && r <= R)return nodes[root].value_max;
		pushdown(root, l, r);
		int m = (l + r) >> 1, ret = -2147483647;
		if (L <= m)ret = queryMax(Lchild(root), l, m, L, R);
		if (R > m)ret = Max(ret, queryMax(Rchild(root), m + 1, r, L, R));
		return ret;
	}
};
SegmentTree Tree;
int n;
int l, r;
int main() {
	while (scanf("%d", &n) != EOF) {
		Tree.init();
		while (n--) {
			l = read(), r = read();
			if (l > r) l ^= r, r ^= l, l ^= r;
			Tree.updateAdd(1, 1, 10000, l, r, 1);
		}
		write(Tree.queryMax(1, 1, 10000, 1, 10000));
		putchar('\n');
	}
}