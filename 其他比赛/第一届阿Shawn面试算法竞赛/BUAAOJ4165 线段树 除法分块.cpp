#include <cstdio>
#include <cmath>
#define maxn 200010
#define Lchild(x) ((x) << 1)
#define Rchild(x) (((x) << 1) | 1)
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define INF 114514191981017171LL
typedef long long ll;
ll a[maxn];
inline void write(ll x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + 48);
}
inline ll read() {
    ll k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
inline int readOP() {
    char c = getchar();
    while (c != 'M' && c != 'D' && c != 'Q')c = getchar();
    if(c == 'M') return 1;
    if(c == 'D') return 2;
    return 3;
}
ll n, q;
int op;
int l, r;
ll d;
struct SegmentTree {
    struct node {
        ll value_sum, value_max, value_min;
        ll tag_Add;
        //因为是尽可能将除法转成减法,所以实际上就是变种加法线段树了
    } nodes[maxn << 2];
    inline void pushup(int root) {
        nodes[root].value_sum = nodes[Lchild(root)].value_sum + nodes[Rchild(root)].value_sum;
        nodes[root].value_max = Max(nodes[Lchild(root)].value_max, nodes[Rchild(root)].value_max);
        nodes[root].value_min = Min(nodes[Lchild(root)].value_min, nodes[Rchild(root)].value_min);
    }
    inline void build(int root, int l, int r) {
        nodes[root].tag_Add = 0;
        
        if (l == r)
            nodes[root].value_max = nodes[root].value_min = nodes[root].value_sum = a[l];
        else {
            int m = (l + r) >> 1;
            build(Lchild(root), l, m);
            build(Rchild(root), m + 1, r);
            pushup(root);
        }
    }
    inline void pushdown(int root, int l, int r) {
        int m = (l + r) >> 1;
        
        if (nodes[root].tag_Add) {
            nodes[Lchild(root)].tag_Add += nodes[root].tag_Add;
            nodes[Rchild(root)].tag_Add += nodes[root].tag_Add;
            nodes[Lchild(root)].value_sum += (1ll * m - 1ll * l + 1ll) * nodes[root].tag_Add;
            nodes[Rchild(root)].value_sum += (1ll * r - 1ll * m) * nodes[root].tag_Add;
            nodes[Lchild(root)].value_max += nodes[root].tag_Add, nodes[Lchild(root)].value_min += nodes[root].tag_Add;
            nodes[Rchild(root)].value_max += nodes[root].tag_Add, nodes[Rchild(root)].value_min += nodes[root].tag_Add;
            nodes[root].tag_Add = 0;
        }
    }
    //除法的核心是使用分块除法 a - (a - a/d)
    inline void updateDiv(int root, int curl, int curr, int tarl, int tarr, ll k) {
        if (tarl <= curl && curr <= tarr) {
            ll c1 = nodes[root].value_max - (ll)floor((double)nodes[root].value_max / k);
            ll c2 = nodes[root].value_min - (ll)floor((double)nodes[root].value_min / k);
            
            if (c1 == c2) {
                nodes[root].tag_Add -= c1;
                nodes[root].value_sum -= (1ll * curr - 1ll * curl + 1ll) * c1;
                nodes[root].value_max -= c1, nodes[root].value_min -= c1;
                return;
            }
        }
        
        //如果不能同一减,那就再分块往下减
        pushdown(root, curl, curr);
        int m = (curl + curr) >> 1;
        
        if (tarl <= m)
            updateDiv(Lchild(root), curl, m, tarl, tarr, k);
        
        if (tarr > m)
            updateDiv(Rchild(root), m + 1, curr, tarl, tarr, k);
        
        pushup(root);
    }
    inline void updateAdd(int root, int curl, int curr, int tarl, int tarr, ll k) {
        if (tarl <= curl && curr <= tarr) {
            nodes[root].tag_Add += k;
            nodes[root].value_sum += k * (1ll * curr - 1ll * curl + 1ll);
            nodes[root].value_max += k;
            nodes[root].value_min += k;
            return;
        }
        
        pushdown(root, curl, curr);
        int m = (curl + curr) >> 1;
        
        if (tarl <= m)
            updateAdd(Lchild(root), curl, m, tarl, tarr, k);
        
        if (tarr > m)
            updateAdd(Rchild(root), m + 1, curr, tarl, tarr, k);
        
        pushup(root);
    }
    inline ll querySum(int root, int curl, int curr, int tarl, int tarr) {
        if (tarl <= curl && curr <= tarr) {
            return nodes[root].value_sum;
        }
        
        pushdown(root, curl, curr);
        int m = (curl + curr) >> 1;
        ll ret = 0;
        
        if (tarl <= m)
            ret += querySum(Lchild(root), curl, m, tarl, tarr);
        
        if (tarr > m)
            ret += querySum(Rchild(root), m + 1, curr, tarl, tarr);
        
        return ret;
    }
    inline ll queryMin(int root, int curl, int curr, int tarl, int tarr) {
        if (tarl <= curl && curr <= tarr) {
            return nodes[root].value_min;
        }
        
        pushdown(root, curl, curr);
        int m = (curl + curr) >> 1;
        ll ret = INF;
        
        if (tarl <= m)
            ret = Min(ret, queryMin(Lchild(root), curl, m, tarl, tarr));
        
        if (tarr > m)
            ret = Min(ret, queryMin(Rchild(root), m + 1, curr, tarl, tarr));
        
        return ret;
    }
};
SegmentTree Tree;
int main() {
    n = read();
    for (int i = 1; i <= n; ++i)
    a[i] = read();
    
    Tree.build(1, 1, n);
    
    q = read();
    
    while (q--) {
        op = readOP(), l = read();
        if (op == 1) {
            d = read();
            Tree.updateAdd(1, 1, n, l, l, -Tree.querySum(1, 1, n, l, l));
            Tree.updateAdd(1, 1, n, l, l, d);
        } else if (op == 2) {
            r = read(), d = read();
            Tree.updateDiv(1, 1, n, l, r, d);
        } else {
            r = read();
            write(Tree.querySum(1, 1, n, l, r));
            putchar('\n');
        }
    }
}