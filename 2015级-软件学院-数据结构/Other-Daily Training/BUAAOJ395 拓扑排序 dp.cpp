#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 10010
#define maxm 50010
#define MOD 10000
using namespace std;
int n, m, start, finish, cost;
int x, y, t;
struct Edges {
    int u, v, w, next;
}edges[maxm];
int que[maxn], tail = 0;
int inDegree[maxn];
int inCount[maxn], inTime[maxn];
int link[maxn];//每个顶点的第一条边的序号
int cnt;
inline void addEdge(int u, int v, int w) {
    edges[++cnt].next = link[u];
    edges[cnt].u = u, edges[cnt].v = v, edges[cnt].w = w;
    link[u] = cnt, inDegree[v]++;
}
inline void topoSort() {
    for (int i = 1; i <= n; ++i)
        if (inDegree[i] == 0)que[++tail] = i;
    for (int i = 1; i <= tail; ++i) {
        for (int k = link[que[tail]]; k > 0; k = edges[k].next) {
            inDegree[edges[k].v]--;
            if (inDegree[edges[k].v] == 0)que[++tail] = edges[k].v;
        }
        if (tail == n)break;
    }
}
inline void buildDP() {
    inCount[start] = 1; inTime[finish] = 0;
    for (int j = 1; j <= n; ++j) {
        int k = que[j];
        if (link[k] > 0) {
            for (int i = link[k]; i > 0; i = edges[i].next) {
                inCount[edges[i].v] = (inCount[edges[i].v] + inCount[k]) % MOD;
                inTime[edges[i].v] = (inTime[edges[i].v] + inTime[k] + edges[i].w * inCount[k]) % MOD;
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d%d", &n, &m, &start, &finish, &cost);
    memset(edges, 0, sizeof(edges));
    memset(link, -1, sizeof(link));
    memset(inDegree, 0, sizeof(inDegree));
    memset(inCount, 0, sizeof(inCount));
    memset(inTime, 0, sizeof(inTime));
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &t);
        addEdge(x, y, t);
    }
    topoSort(); buildDP();
    printf("%d\n", (inTime[finish] + (inCount[finish] - 1) * cost) % MOD);
}
