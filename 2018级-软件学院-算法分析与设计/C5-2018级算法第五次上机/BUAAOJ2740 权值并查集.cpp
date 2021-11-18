#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 40010
using namespace std;
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
int n, m;
int x, y, val;
int f[maxn];
inline void initFather() {
    for (int i = 1; i <= 2 * n; ++i)f[i] = i;
}
inline int getFather(int x) {
    return f[x] == x ? x : f[x] = getFather(f[x]);
}
inline bool check(int x, int y) {
    int a = getFather(x);
    int b = getFather(y);
    if (a != b) return false;
    else return true;
}
inline void merge(int x, int y) {
    int a = getFather(x);
    int b = getFather(y);
    if (a != b) f[a] = b;
}
struct node {
    int x, y, val;
    node(int xx = 0, int yy = 0, int Val = 0){x=xx,y=yy,val=Val;}
};
struct cmp {
    bool operator()(const node& a, const node& b) const {
        return a.val < b.val;
    }
};
priority_queue<node, vector<node>, cmp> pq;
int main() {
    n = read(), m = read();
    initFather();
    while (m--) {
        x = read(), y = read(), val = read();
        pq.push(node(x,y,val));
    }
    while(!pq.empty()) {
        node tmp = pq.top();
        x = tmp.x, y = tmp.y, val = tmp.val;
        if(check(x, y)) {write(val); return 0;}
        merge(x,y+n),merge(x+n,y);
        pq.pop();
    }
    write(0);
}
