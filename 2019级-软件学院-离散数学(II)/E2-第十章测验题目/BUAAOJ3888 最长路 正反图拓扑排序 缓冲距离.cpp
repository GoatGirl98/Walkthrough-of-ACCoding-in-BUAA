#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 105
void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
int read() {
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
struct node {
    int v, w;
    node(int _v = 0, int _w = 0) { v = _v; w = _w; }
    bool operator < (const node& o)const {
        return o.w < w;
    }
};
int n, m, s, t;
int u, v, w;
vector<node> g[maxn];//正向图
vector<node> e[maxn];//反向图
int TE[maxn], TL[maxn];//关键路径
int in[maxn], out[maxn];//入度和出度
vector<vector<int> > ans;//所有关键通路
int tmp[maxn];//临时存储关键通路
vector<int> temp;
queue<int> gq, eq;
bool compare(const vector<int>& a, const vector<int>& b) {
    if(a.size() != b.size()) return a.size() < b.size();
    for(int i = 0; i < a.size(); ++i) if(a[i] != b[i]) return a[i] < b[i];
    return true;
}
void init() {
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(tmp, 0, sizeof(tmp));
    tmp[0] = s;
    memset(TE, 0, sizeof(TE));
    memset(TL, 0x3f, sizeof(TL));
    TL[0] = 0;
}
void dfs(int u, int step) {
    if(u == t) {
        temp.clear();
        for(int i = 0; i < step; ++i) temp.push_back(tmp[i]);
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i].v, w = g[u][i].w;
        if(TE[v] == TL[v] && TE[v] == TE[u] + w) {
            tmp[step] = v;
            dfs(v, step + 1);
        }
    }
}
void bfs_g() {
    for(int i = 1; i <= n; ++i) if(in[i] == 0) gq.push(i);
    while(!gq.empty()) {
        int u = gq.front(); gq.pop();
        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].v, w = g[u][i].w;
            if(TE[v] < TE[u] + w) TE[v]= TE[u] + w;
            --in[v];
            if(in[v] == 0)gq.push(v);
        }
    }
}
void bfs_e() {
    for(int i = 1; i <= n; ++i) if(out[i] == 0) gq.push(i);
    eq.push(t);
    TL[t] = TE[t];
    while(!eq.empty()) {
        int u = eq.front(); eq.pop();
        for(int i = 0; i < e[u].size(); ++i) {
            int v = e[u][i].v, w = e[u][i].w;
            if(TL[v] > TL[u] - w) TL[v]= TL[u] - w;
            --out[v];
            if(out[v] == 0)eq.push(v);
        }
    }
}
void print_route() {
    sort(ans.begin(), ans.end(), compare);
    putchar('[');
    for(int i = 0; i < ans.size(); ++i) {
        putchar('[');
        for(int j = 0; j < ans[i].size(); ++j) {
            write(ans[i][j]);
            if(j != ans[i].size() - 1) putchar(','), putchar(' ');
        }
        putchar(']');
        if(i != ans.size() - 1)putchar(','), putchar(' ');
    }
    putchar(']');
}
void print_ans() {
    printf("Dis=%d\n", TE[t]);
    for(int i = 1; i <= n; ++i) {
        printf("Node %d: TE= %3d  TL= %3d  TL-TE= %d\n", i, TE[i], TL[i], TL[i] - TE[i]);
    }
    print_route();
}
int main() {
    n = read(), m = read(), s = read(), t = read();
    init();
    while(m--) {
        u = read(), v = read(), w = read();
        g[u].push_back(node(v, w));
        e[v].push_back(node(u, w));
        ++out[u], ++in[v];
    }
    bfs_g(), bfs_e();
    dfs(s, 1);
    print_ans();
}
