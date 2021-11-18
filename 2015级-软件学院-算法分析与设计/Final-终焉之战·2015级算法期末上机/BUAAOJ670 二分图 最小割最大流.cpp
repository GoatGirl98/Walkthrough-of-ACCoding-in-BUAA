#pragma G++ optimize(2)
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const double INF = 114514191981.0;
struct Maxflow_ISAP {
    static const int maxn = 150;//点的大小
    static const int maxm = 1000;//边
    struct edge {
        int next, to;
        double w;
    }edges[maxm << 1];//双向边
    int head[maxn], cnt;
    inline void addedge(int u, int v, double w) {
        edges[cnt].next = head[u];
        edges[cnt].to = v;
        edges[cnt].w = w;
        head[u] = cnt++;
        edges[cnt].next = head[v];
        edges[cnt].to = u;
        edges[cnt].w = 0;
        head[v] = cnt++;
    }
    int n;
    int s, t;
    double maxflow;
    int dep[maxn], gap[maxn], cur[maxn];
    queue<int> q;
    inline void init(int n) {
        this->n = n;
        memset(head, -1, sizeof(head));
        while(q.size())q.pop();
        cnt = 0;
        memset(edges, 0, sizeof(edges));
        memset(dep, 0, sizeof(dep));
        memset(gap, 0, sizeof(gap));
        memset(cur, 0, sizeof(cur));
        maxflow = 0.0;
    }
    
    //gap[i]指深度为i的点的数量
    //cur为当前弧优化
    inline void bfs() {
        for (int i = 0; i < maxn; ++i) {
            dep[i] = -1; gap[i] = 0;
        }
        q.push(t);
        dep[t] = 0, gap[0] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = head[u]; i >= 0; i = edges[i].next) {
                int v = edges[i].to;
                if (dep[v] != -1)continue;
                q.push(v);
                dep[v] = dep[u] + 1, gap[dep[v]]++;
            }
        }
    }

    inline double dfs(int u, double flow) {
        if (u == t) {
            maxflow += flow;
            return flow;
        }
        double occured = 0;
        for (int& i = cur[u]; i >= 0; i = edges[i].next) {
            int v = edges[i].to;
            if (edges[i].w && dep[v] + 1 == dep[u]) {
                double d = dfs(v, min(flow - occured, edges[i].w));
                if (d > 0) {
                    edges[i].w -= d; edges[i ^ 1].w += d;
                    occured += d;
                }
                if (occured == flow)return occured;
            }
        }
        //前面和dinic一样
        //后面表示所有点都流过了而且还有剩余
        --gap[dep[u]];
        if (!gap[dep[u]])dep[s] = n + 1;
        dep[u]++;
        gap[dep[u]]++;
        return occured;
    }

    inline double ISAP(int S, int T) {
        this->s = S, this->t = T;
        bfs();
        while (dep[s] <= n) {
            memcpy(cur, head, sizeof(head));
            dfs(s, INF);
        }
        return maxflow;
    }
}solver;
int T;
int m,n,L;
int s,t;
double Input;
int x,y;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&m,&n,&L);
        solver.init(m + n + 2);
        s = m + n + 1, t = m + n + 2;
        for(int i = 1; i <= m; ++i) {
            scanf("%lf",&Input);
            solver.addedge(s, i, log(Input));
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%lf",&Input);
            solver.addedge(i + m, t, log(Input));
        }
        for(int i = 1; i <= L; ++i) {
            scanf("%d%d",&x,&y);
            solver.addedge(x, y + m, INF);
        }
        printf("%.4f\n",exp(solver.ISAP(s, t)));
        
    }
}
