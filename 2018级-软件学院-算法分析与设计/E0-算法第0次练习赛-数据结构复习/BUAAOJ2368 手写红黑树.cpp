#include<cstdio>
#define maxn 300010
typedef long long ll;
#define max(a,b) (((a)>(b))?(a):(b))
//红黑树相关的宏定义函数,包括找兄弟,判断是左孩子右孩子,红黑节点
#define bro(x) (((x)->ftr->lc == (x)) ? ((x)->ftr->rc):((x)->ftr->lc))
#define islc(x) ((x)!=NULL && (x)->ftr->lc == (x))
#define isrc(x) ((x)!=NULL && (x)->ftr->rc == (x))
#define BLACK 0
#define RED 1
inline void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
template <typename T>
struct RedBlackTree {
    /**红黑树节点**/
    struct RBNode {
        T val;//节点值
        bool color;//true为红,false为黑
        RBNode* ftr;
        RBNode* lc, * rc;//父亲节点左孩子右孩子
        int _size;//排名专用:记录以此点为根的树的规模

        RBNode(T v = T(), bool RB = RED, RBNode* f = NULL,
            RBNode* l = NULL, RBNode* r = NULL, int s = 1)
            : val(v), color(RB), ftr(f), lc(l), rc(r), _size(s) {}

        //删除节点专用后继
        RBNode* single_succ() {
            RBNode* ret = rc;
            while (ret->lc) {
                --(ret->_size);
                ret = ret->lc;
            }
            return ret;
        }
        //直接前驱,从处注意可以是NULL
        RBNode* pred() {
            RBNode* ret = this;
            if (!lc) {
                while (ret->ftr && ret->ftr->lc == ret)
                    ret = ret->ftr;
                ret = ret->ftr;
            }
            else {
                ret = ret->lc;
                while (ret->rc)
                    ret = ret->rc;
            }
            return ret;
        }
        //直接后继
        RBNode* succ() {
            RBNode* ret = this;
            if (!rc) {
                while (ret->ftr && ret->ftr->rc == ret)
                    ret = ret->ftr;
                ret = ret->ftr;
            }
            else {
                ret = ret->rc;
                while (ret->lc)
                    ret = ret->lc;
            }
            return ret;
        }
        //维护域
        void maintain() {
            _size = 1;
            if (lc)_size += lc->_size;
            if (rc)_size += rc->_size;
        }
    };

    /**外部不可见部分**/

    RBNode* _root;//根节点
    RBNode* _hot;//查找专用命中_hot

    void init(T v) { _root = new RBNode(v, BLACK, NULL, NULL, NULL, 1); }

    //统一重平衡代码,考虑3个节点4个子树
    //分类讨论排序不在此处做,传入接口时是排好序的
    void connect34(RBNode* nroot, RBNode* nlc, RBNode* nrc,
        RBNode* ntree1, RBNode* ntree2, RBNode* ntree3, RBNode* ntree4) {
        nlc->lc = ntree1;
        if (ntree1)ntree1->ftr = nlc;
        nlc->rc = ntree2;
        if (ntree2)ntree2->ftr = nlc;
        nrc->lc = ntree3;
        if (ntree3)ntree3->ftr = nrc;
        nrc->rc = ntree4;
        if (ntree4)ntree4->ftr = nrc;
        nroot->lc = nlc, nlc->ftr = nroot;
        nroot->rc = nrc, nrc->ftr = nroot;
        nlc->maintain(), nrc->maintain();
        nroot->maintain();
    }

    //允许重复的查找,默认是找到同一个数的最后一个出现的位置
    RBNode* find(T v, const int op) {
        RBNode* ptn = _root;
        _hot = NULL;
        while (ptn) {
            _hot = ptn;
            ptn->_size += op;
            if (ptn->val > v)
                ptn = ptn->lc;
            else
                ptn = ptn->rc;
        }
        return ptn;
    }
    //不允许重复的查找,只要找到对应值就收手
    RBNode* rfind(T v, const int op) {
        RBNode* ptn = _root;
        _hot = NULL;
        while (ptn && ptn->val != v) {
            _hot = ptn;
            ptn->_size += op;
            if (ptn->val > v)
                ptn = ptn->lc;
            else
                ptn = ptn->rc;
        }
        return ptn;
    }

    //双红修正,采用迭代方式,迭代条件为RR-2上溢向上传2层
    //判断双红的时候,自己得先是红的,然后判断父亲节点
    void SolveDoubleRed(RBNode* nn) {
        while ((!(nn->ftr)) || nn->ftr->color == RED) {
            if (nn == _root) {
                //根节点强制重染色为黑色,并且增加黑高度
                _root->color = BLACK;
                return;
            }
            RBNode* p = nn->ftr;
            if (p->color == BLACK)return;//case 1:没有双红,直接返回
            RBNode* u = bro(p);
            RBNode* g = p->ftr;
            //case 2:RR-2
            if (u != NULL && u->color == RED) {
                g->color = RED;
                p->color = u->color = BLACK;
                nn = g;//下一次检查往上翻2层
            }
            //case 3:RR-1 直接返回
            //此时就是要先根据情况调整父子节点位置,排好3+4结构,重染色
            else {
                if (islc(p)) {
                    if (islc(nn)) {//zig
                        p->ftr = g->ftr;
                        if (g == _root) _root = p;
                        else if (g->ftr->lc == g) g->ftr->lc = p;
                        else g->ftr->rc = p;
                        connect34(p, nn, g, nn->lc, nn->rc, p->rc, u);
                        p->color = BLACK;
                        g->color = RED;
                    }
                    else {//zag-zig
                        nn->ftr = g->ftr;
                        if (g == _root) _root = nn;
                        else if (g->ftr->lc == g) g->ftr->lc = nn;
                        else g->ftr->rc = nn;
                        connect34(nn, p, g, p->lc, nn->lc, nn->rc, u);
                        nn->color = BLACK;
                        g->color = RED;
                    }
                }
                else {
                    if (islc(nn)) {//zig-zag
                        nn->ftr = g->ftr;
                        if (g == _root) _root = nn;
                        else if (g->ftr->lc == g) g->ftr->lc = nn;
                        else g->ftr->rc = nn;
                        connect34(nn, g, p, u, nn->lc, nn->rc, p->rc);
                        nn->color = BLACK;
                        g->color = RED;
                    }
                    else {//zag
                        p->ftr = g->ftr;
                        if (g == _root) _root = p;
                        else if (g->ftr->lc == g) g->ftr->lc = p;
                        else g->ftr->rc = p;
                        connect34(p, g, nn, u, p->lc, nn->lc, nn->rc);
                        p->color = BLACK;
                        g->color = RED;
                    }
                }
                return;
            }
        }
    }

    //双黑修正,采用迭代方式,迭代条件为BB-2B下溢向上传1层
    //如果是根节点了,就可以直接停机了
    void SolveDoubleBlack(RBNode* nn) {
        while (nn != _root) {
            RBNode* p = nn->ftr;
            RBNode* b = bro(nn);
            if (b->color == RED) { //Case 1:BB-3
                b->color = BLACK;
                p->color = RED;
                if (_root == p)_root = b;
                if (p->ftr) {
                    if (p->ftr->lc == p)p->ftr->lc = b;
                    else p->ftr->rc = b;
                }
                b->ftr = p->ftr;
                if (islc(nn))//zag
                    connect34(b, p, b->rc, nn, b->lc, b->rc->lc, b->rc->rc);
                else//zig
                    connect34(b, b->lc, p, b->lc->lc, b->lc->rc, b->rc, nn);
                b = bro(nn), p = nn->ftr;
                //转换问题并往后接着推,维护的核心节点nn不变
            }
            if (b->lc && b->lc->color == RED) { //Case 2-1:BB-1
                bool old_p_color = p->color;
                p->color = BLACK;
                if (p->lc == nn) {//zig-zag
                    if (p->ftr) {
                        if (p->ftr->lc == p)p->ftr->lc = b->lc;
                        else p->ftr->rc = b->lc;
                    }
                    b->lc->ftr = p->ftr;
                    if (_root == p)_root = b->lc;
                    connect34(b->lc, p, b, nn, b->lc->lc, b->lc->rc, b->rc);
                }
                else {//zig
                    b->lc->color = BLACK;
                    if (p->ftr) {
                        if (p->ftr->lc == p)p->ftr->lc = b;
                        else p->ftr->rc = b;
                    }
                    b->ftr = p->ftr;
                    if (_root == p)_root = b;
                    connect34(b, b->lc, p, b->lc->lc, b->lc->rc, b->rc, nn);
                }
                p->ftr->color = old_p_color;
                return;//BB-1直接返回
            }
            else if (b->rc && b->rc->color == RED) { //Case 2-2:BB-1
                bool old_p_color = p->color;
                p->color = BLACK;
                if (p->lc == nn) {//zag
                    b->rc->color = BLACK;
                    if (p->ftr) {
                        if (p->ftr->lc == p)p->ftr->lc = b;
                        else p->ftr->rc = b;
                    }
                    b->ftr = p->ftr;
                    if (_root == p)_root = b;
                    connect34(b, p, b->rc, nn, b->lc, b->rc->lc, b->rc->rc);
                }
                else {//zag-zig
                    if (p->ftr) {
                        if (p->ftr->lc == p)p->ftr->lc = b->rc;
                        else p->ftr->rc = b->rc;
                    }
                    b->rc->ftr = p->ftr;
                    if (_root == p)_root = b->rc;
                    connect34(b->rc, b, p, b->lc, b->rc->lc, b->rc->rc, nn);
                }
                p->ftr->color = old_p_color;
                return;//BB-1直接返回
            }
            if (p->color == RED) {//case 3:BB-2R
                p->color = BLACK;
                b->color = RED;
                return;//BB-2R直接返回
            }
            else {//case 4:BB-2B
                b->color = RED;
                nn = p;
                //BB-2B下溢上传,继续迭代
            }
        }
    }

    RBNode* findKth(int Rank, RBNode* ptn) {
        if (ptn->lc == NULL) {
            if (Rank == 1)return ptn;
            else return findKth(Rank - 1, ptn->rc);
        }
        else {
            if (ptn->lc->_size == Rank - 1)return ptn;
            else if (ptn->lc->_size >= Rank)return findKth(Rank, ptn->lc);
            else return findKth(Rank - (ptn->lc->_size) - 1, ptn->rc);
        }
    }

    int find_rank(T v, RBNode* ptn) {
        if (!ptn)return 1;
        else if (ptn->val >= v)return find_rank(v, ptn->lc);
        else return (1 + ((ptn->lc) ? (ptn->lc->_size) : 0) + find_rank(v, ptn->rc));
    }

    /**查看现象的debug接口**/

    void previs(RBNode* ptn) {
        printf("current node value is %d, color is %s, _size is %d\n", ptn->val, ptn->color ? "Red" : "Black", ptn->_size);
        printf("Lchild value is "); if (ptn->lc)printf("%d _size is %d\n", ptn->lc->val, ptn->lc->_size); else puts("NULL");
        printf("Rchild value is "); if (ptn->rc)printf("%d _size is %d\n", ptn->rc->val, ptn->lc->_size); else puts("NULL");
        if (ptn->lc)previs(ptn->lc);
        if (ptn->rc)previs(ptn->rc);
    }

    void invis(RBNode* ptn) {
        if (ptn->lc)invis(ptn->lc);
        printf("current node value is %d, color is %s, _size is %d\n", ptn->val, ptn->color ? "Red" : "Black", ptn->_size);
        printf("Lchild value is "); if (ptn->lc)printf("%d _size is %d\n", ptn->lc->val, ptn->lc->_size); else puts("NULL");
        printf("Rchild value is "); if (ptn->rc)printf("%d _size is %d\n", ptn->rc->val, ptn->lc->_size); else puts("NULL");
        if (ptn->rc)invis(ptn->rc);
    }

    void postvis(RBNode* ptn) {
        if (ptn->lc)postvis(ptn->lc);
        if (ptn->rc)postvis(ptn->rc);
        printf("current node value is %d, color is %s, _size is %d\n", ptn->val, ptn->color ? "Red" : "Black", ptn->_size);
        printf("Lchild value is "); if (ptn->lc)printf("%d _size is %d\n", ptn->lc->val, ptn->lc->_size); else puts("NULL");
        printf("Rchild value is "); if (ptn->rc)printf("%d _size is %d\n", ptn->rc->val, ptn->lc->_size); else puts("NULL");
    }

    void checkconnect(RBNode* ptn) {
        if (!ptn) return;
        if (ptn->lc && ptn->lc->ftr != ptn) {
            printf("Oops! %d has a lc %d, but it failed to point its ftr!\n", ptn->val, ptn->lc->val);
        }
        if (ptn->rc && ptn->rc->ftr != ptn) {
            printf("Oops! %d has a rc %d, but it failed to point its ftr!\n", ptn->val, ptn->rc->val);
        }
        int sss = ptn->_size;
        if (ptn->lc) sss -= ptn->lc->_size;
        if (ptn->rc) sss -= ptn->rc->_size;
        if (sss - 1) {
            printf("Fuck it! %d's size is %d, but the sum of its children's size is %d!\n", ptn->val, ptn->_size, ptn->_size - sss);
        }
        checkconnect(ptn->lc);
        checkconnect(ptn->rc);
    }

    void correctlyconnected() {
        checkconnect(_root);
    }

    /**节点对应的迭代器**/
    struct iterator {
        //这个数据实际上也要private
        RBNode* _real__node;

        iterator& operator++() {
            _real__node = _real__node->succ();
            return *this;
        }
        iterator& operator--() {
            _real__node = _real__node->pred();
            return *this;
        }
        T operator*() {
            return _real__node->val;
        }

        iterator(RBNode* node_nn = NULL) :_real__node(node_nn) {}
        iterator(T const& val_vv) :_real__node(rfind(val_vv, 0)) {}
        iterator(iterator const& iter) :_real__node(iter._real__node) {}

    };

    /**对外端口部分**/

    RedBlackTree() :_root(NULL), _hot(NULL) {}

    //插入 返回对应迭代器
    iterator insert(T v) {
        RBNode* ptn = find(v, 1);
        if (_hot == NULL) {//仅有1个节点
            init(v);
            return iterator(_root);
        }
        ptn = new RBNode(v, RED, _hot, NULL, NULL, 1);
        if (_hot->val <= v)_hot->rc = ptn;
        else _hot->lc = ptn;
        SolveDoubleRed(ptn);
        return iterator(ptn);
    }
    //删除 返回成功或失败 本题中只可能是true
    bool remove(T v) {
        RBNode* ptn = rfind(v, -1);
        if (!ptn)return false;
        RBNode* node_suc;
        //单双分支情况处理
        while (ptn->lc || ptn->rc) {
            if (ptn->lc == NULL)node_suc = ptn->rc;
            else if (ptn->rc == NULL)node_suc = ptn->lc;
            else node_suc = ptn->single_succ();
            --(ptn->_size);
            ptn->val = node_suc->val;
            ptn = node_suc;
        }
        //当对应删去的节点为黑色,则需要双黑修正
        if (ptn->color == BLACK) {
            --(ptn->_size);
            SolveDoubleBlack(ptn);
        }
        if (ptn == _root) {
            _root = NULL;
            delete ptn;
            return true;
        }
        if (ptn->ftr->lc == ptn)ptn->ftr->lc = NULL;
        else ptn->ftr->rc = NULL;
        delete ptn;
        return true;
    }
    //查排名
    int get_rank(T v) {
        return find_rank(v, _root);
    }
    int size() {
        return _root->_size;
    }
    bool empty() {
        return !_root;
    }
    iterator Kth(int Rank) {
        return iterator(findKth(Rank, _root));
    }
    iterator lower_bound(T v) {
        RBNode* ptn = _root;
        while (ptn) {
            _hot = ptn;
            if (ptn->val < v)ptn = ptn->rc;
            else ptn = ptn->lc;
        }
        if (_hot->val < v)ptn = _hot;
        else ptn = _hot->pred();
        return iterator(ptn);
    }
    iterator upper_bound(T v) {
        RBNode* ptn = _root;
        while (ptn) {
            _hot = ptn;
            if (ptn->val > v)ptn = ptn->lc;
            else ptn = ptn->rc;
        }
        if (_hot->val > v)ptn = _hot;
        else ptn = _hot->succ();
        return iterator(ptn);
    }

};
RedBlackTree<int> Tree;
ll depth[maxn];
ll ans;
int n;
int x;
int main() {
    n = read();
    x = read();
    Tree.insert(x);
    puts("0");
    n--;
    while (n--) {
        x = read();
        Tree.insert(x);
        if (Tree.get_rank(x) == 1)
            depth[x] = 1 + depth[*Tree.upper_bound(x)];
        else if (Tree.get_rank(x) == Tree.size())
            depth[x] = 1 + depth[*Tree.lower_bound(x)];
        else
            depth[x] = 1 + max(depth[*Tree.upper_bound(x)], depth[*Tree.lower_bound(x)]);
        ans += depth[x];
        write(ans), putchar_unlocked('\n');
    }

}
