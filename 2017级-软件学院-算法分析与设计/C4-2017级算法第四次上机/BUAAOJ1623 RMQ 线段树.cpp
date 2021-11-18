#include<cstdio>
#define maxn 200010
#define Lchild(x) ((x) << 1)
#define Rchild(x) (((x) << 1) | 1)
#define Max(a,b) (((a)>(b))?(a):(b))
int a[maxn];
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
    struct node {
        int value;
    }nodes[maxn << 2];
    inline void pushup(int root) {
        nodes[root].value = Max(nodes[Lchild(root)].value, nodes[Rchild(root)].value);
    }
    inline void build(int root, int l, int r) {
        if (l == r)nodes[root].value = a[l];
        else {
            int m = (l + r) >> 1;
            build(Lchild(root), l, m);
            build(Rchild(root), m + 1, r);
            pushup(root);
        }
    }
    inline int query(int root, int curl, int curr, int tarl, int tarr) {
        if (tarr < curl || curr < tarl) return -2147483647;
        if (tarl <= curl && curr <= tarr) {
            return nodes[root].value;
        }
        int m = (curl + curr) >> 1, ret = -2147483647;

        if (tarl <= m) ret = query(Lchild(root), curl, m, tarl, tarr);
        if (tarr > m) ret = Max(ret, query(Rchild(root), m + 1, curr, tarl, tarr));
        return ret;
        //return Max(query(Lchild(root), curl, m, tarl, tarr), query(Rchild(root), m + 1, curr, tarl, tarr));
    }
};
SegmentTree Tree;
int n, m;
int l, r;
int main() {
    n = read();
    for (int i = 1; i <= n; ++i)a[i] = read();
    Tree.build(1, 1, n);
    m = read();
    while (m--) {
        l = read(), r = read();
        write(Tree.query(1, 1, n, l, r));
        putchar('\n');
    }
}
