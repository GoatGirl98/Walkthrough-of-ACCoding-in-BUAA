#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
const int LEFT = 0, RIGHT = 1;
inline ll read() {
    ll k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
inline void write(ll x) {
    if (x < 0)
        putchar_unlocked('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
struct MCMF_SPFA {
    static const ll INF = 1145141919810LL;
    static const int maxn = 100010;
    static const int maxm = 1000010;

    struct Edge {
        int next, to;
        ll flow, cost;
    } edges[maxm << 1];
    int head[maxn], cnt;
    inline void addedge(int u, int v, ll flow, ll cost) {
        //printf("(u,v,flow,cost) is (%d,%d,%lld,%lld)\n",u,v,flow,cost);
        edges[cnt].next = head[u];
        edges[cnt].to = v;
        edges[cnt].flow = flow;
        edges[cnt].cost = cost;
        head[u] = cnt++;
        edges[cnt].next = head[v];
        edges[cnt].to = u;
        edges[cnt].flow = 0;      //有向图是0 无向图是flow
        edges[cnt].cost = -cost;  //费用流回退
        head[v] = cnt++;
    }
    bool vis[maxn];
    ll dis[maxn];
    int pre[maxn], last[maxn];
    ll flow[maxn];
    int n;
    int s, t;
    ll maxflow, mincost;
    queue<int> q;
    inline void init(int n) {
        this->n = n;
        cnt = 0;
        memset(vis,0,sizeof(vis));
        memset(head, 0xff, sizeof(head));
        //memset(edges, 0, sizeof(edges));
        memset(dis, 0, sizeof(dis));
        memset(pre, 0, sizeof(pre));
        memset(last, 0, sizeof(last));
        memset(flow, 0, sizeof(flow));
        maxflow = mincost = 0;
        while(q.size())q.pop();
    }

    inline bool SPFA(int s, int t) {
        while(q.size())q.pop();
        for (int i = 1; i <= n; ++i) {
            dis[i] = INF;
            flow[i] = INF;
            vis[i] = 0;
            
        }
        dis[s] = 0;
        q.push(s);
        vis[s] = 1;
        pre[t] = -1;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            vis[tmp] = false;
            for(int i = head[tmp]; ~i; i = edges[i].next) {
                if(edges[i].flow>0 && dis[edges[i].to]>dis[tmp]+edges[i].cost) {
                    dis[edges[i].to] = dis[tmp] + edges[i].cost;
                    pre[edges[i].to] = tmp;
                    last[edges[i].to] = i;
                    flow[edges[i].to]=min(flow[tmp], edges[i].flow);
                    if(!vis[edges[i].to]) {
                        vis[edges[i].to] = true;
                        q.push(edges[i].to);
                    }
                }
            }
        }
        return pre[t] != -1;
    }
    inline PLL MCMF(int S, int T) {
        this->s = S, this->t = T;
        while (SPFA(s, t)) {
            int cur = t;
            ll MF = flow[t];
            mincost += MF * dis[t];
            maxflow += MF;
            while(cur != s) {
                edges[last[cur]].flow -= MF;
                edges[last[cur]^1].flow += MF;
                cur = pre[cur];
            }
        }
        return make_pair(maxflow, mincost);
    }
} solver;
int n, m, s, t;
int K;
int u, v, flow, cost;
int x;
inline int id(int i, int j, int flag) {
    return flag * n * m + m * (i - 1) + j;
}
inline bool isLegal(int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
int main() {
    K = 2;//保证了一共只会取两趟
    while(scanf("%d%d", &n, &m) != EOF) {
        s = 2 * n * m + 1, t = s + 1;
        solver.init(t);
        solver.addedge(s, id(1, 1, LEFT), K, 0);
        solver.addedge(id(n, m, RIGHT), t, K, 0);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                x = -read(); //最大费用流 取负值做计算
                solver.addedge(id(i,j,LEFT), id(i,j,RIGHT), 1, x);
                solver.addedge(id(i,j,LEFT), id(i,j,RIGHT), solver.INF, 0);
                if(isLegal(i+1, j))
                    solver.addedge(id(i,j,RIGHT), id(i+1,j,LEFT), solver.INF, 0);
                if(isLegal(i, j+1))
                    solver.addedge(id(i,j,RIGHT), id(i,j+1,LEFT), solver.INF, 0);
            }
        }
        write(-solver.MCMF(s, t).second), putchar_unlocked('\n');
    }
    
}
