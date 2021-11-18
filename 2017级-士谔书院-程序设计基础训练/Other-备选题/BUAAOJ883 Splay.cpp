#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char lex_smallest[11] = "0000000000";
char lex_biggest[11] = "zzzzzzzzzz";
typedef long long ll;
const int INF = 2147483647;
const int maxn = 1010;
namespace FastIO
{
    int rd()
    {
        int k = 0, f = 1;
        char c = getchar();
        while (c < '0' || c > '9')
        {
            if (c == '-')
                f = -1;
            c = getchar();
        }
        while (c >= '0' && c <= '9')
        {
            k = (k << 1) + (k << 3) + (c ^ 48);
            c = getchar();
        }
        return f > 0 ? k : -k;
    }
    void wr(int x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            wr(x / 10);
        putchar(x % 10 + 48);
    }
    int rd_num(char *s)
    {
        int i = 0, len = strlen(s);
        int k = 0, f = 1;
        if (s[i] == '-')
            f = -1, ++i;
        while (i < len)
            k = (k << 1) + (k << 3) + (s[i++] ^ 48);
        return f > 0 ? k : -k;
    }
    int rd_op()
    {
        char c = getchar();
        while (c != '?' && c != '+')
            c = getchar();
        return c == '+';
    }
    void input_str(char *s)
    {
        int i = 0;
        char c = getchar();
        while (isspace(c))
            c = getchar();
        while (!isspace(c))
            s[i++] = c, c = getchar();
        s[i] = '\0';
    }
    void output_str(char *s)
    {
        int len = strlen(s), i = 0;
        while (i < len)
            putchar(s[i++]);
    }
}
using namespace FastIO;
namespace HashList
{
    const int mod = 294703, seed = 761153;
    struct hash
    {
        char s[12];
        int next;
    } list[maxn];
    int head[mod], cnt;
    int hashcode(char *s)
    {
        int len = strlen(s);
        ll ret = strlen(s);
        for (int i = 0; i < len; ++i)
            ret = (ret * seed + 1ll * s[i]) % mod;
        return ret;
    }
    inline int newnode(char *s)
    {
        int code = hashcode(s);
        strcpy(list[++cnt].s, s);
        list[cnt].next = head[code];
        head[code] = cnt;
        return cnt;
    }
    inline int find(char *s)
    {
        int code = hashcode(s);
        for (int i = head[code]; i; i = list[i].next)
            if (!strcmp(list[i].s, s))
                return i;
        return 0;
    }
}
char s[12];
int score;
int res[20], sre[20], res_sz; //print player
namespace Splay
{
    int l[maxn], r[maxn], f[maxn];
    int a[maxn], s[maxn];
    char* name[maxn];
    int root;

    void update(int x) { s[x] = s[l[x]] + s[r[x]] + 1; }

    void lr(int x)
    {
        int y = f[x];
        r[y] = l[x];
        if (l[x])
            f[l[x]] = y;
        f[x] = f[y];
        if (root == y)
            root = x;
        else if (l[f[y]] == y)
            l[f[y]] = x;
        else
            r[f[y]] = x;
        f[y] = x, l[x] = y;
        update(y), update(x);
    }

    void rr(int x)
    {
        int y = f[x];
        l[y] = r[x];
        if (r[x])
            f[r[x]] = y;
        f[x] = f[y];
        if (root == y)
            root = x;
        else if (l[f[y]] == y)
            l[f[y]] = x;
        else
            r[f[y]] = x;
        f[y] = x, r[x] = y;
        update(y), update(x);
    }

    void rotate(int x)
    {
        if (l[f[x]] == x)
            rr(x);
        else
            lr(x);
    }

    void splay(int x, int target = 0)
    {
        while (f[x] != target)
        {
            if (f[f[x]] == target)
                rotate(x);
            else if ((l[f[x]] == x) == (l[f[f[x]]] == f[x]))
                rotate(f[x]), rotate(x);
            else
                rotate(x), rotate(x);
        }
    }

    void insert(int pos, int val)
    {
        int x = root, y = 0;
        char* insert_name = HashList::list[pos - 2].s;
        while (x)
        {
            y = x;
            //x = (val <= a[x] ? l[x] : r[x]);//成绩相同, 先来后到
            //成绩相同, 字典序更小更靠前
            x = ((val < a[x] || (val == a[x] && strcmp(insert_name, name[x]) >= 0)) ? l[x] : r[x]);
        }
        if (val < a[y] || (val == a[y] && strcmp(insert_name, name[y]) >= 0))
            l[y] = pos;
        else
            r[y] = pos;
        f[pos] = y, l[pos] = r[pos] = 0;
        a[pos] = val, name[pos] = insert_name, s[pos] = 1;
        splay(pos);
    }

    void erase(int x)
    {
        splay(x);
        if (!r[root])
            f[l[root]] = 0, root = l[root];
        else
        {
            int y = r[x];
            while (l[y])
                y = l[y];
            splay(y, root);
            l[y] = l[root], f[l[root]] = y, f[y] = 0;
            root = r[root];
            update(root);
        }
    }

    int find(int k)
    {
        int x = root;
        while (s[r[x]] + 1 != k)
        {
            if (k < s[r[x]] + 1)
                x = r[x];
            else
                k -= s[r[x]] + 1, x = l[x];
        }
        return x;
    }

    int rank(int x)
    {
        splay(x);
        return s[r[x]];
    }

    void access(int x)
    {
        if (!x)
            return;
        access(r[x]);
        res[++res_sz] = x;
        sre[res_sz] = a[x];
        access(l[x]);
    }

    void init()
    {
        r[1] = 2, f[2] = 1;
        s[1] = 2, s[2] = 1;
        root = 1;
        name[1] = lex_smallest, name[2] = lex_biggest;
        a[1] = -INF, a[2] = INF;
    }
    //lim : 10 player from rk
    void query_with_rank(int rk)
    {
        int x = rk + 1, y = rk + 1;// y = min(rk + 10, s[root] - 1);
        x = find(x - 1), y = find(y + 1);
        swap(x, y);
        splay(x);
        splay(y, root);
        res_sz = 0;
        access(l[r[root]]);
        for (int j = 1; j <= res_sz; ++j)
            output_str(HashList::list[res[j] - 2].s), putchar(' '), wr(sre[j]), putchar('\n');
    }
    void query_with_name(int name)
    {
        wr(rank(name)), putchar('\n');
    }
}
int n;
int main()
{
    n = rd();
    Splay::init();
    while (n--)
    {
        int op = rd();
        if (op == 1)
        {
            input_str(s), score = rd();
            int cnt = HashList::find(s) + 2;
            if (cnt <= 2)
                cnt = HashList::newnode(s) + 2, Splay::insert(cnt, score);
            else
                Splay::erase(cnt), Splay::insert(cnt, score);
        }
        else
        {
            int rk = rd();
            Splay::query_with_rank(rk);           
        }
    }
}
