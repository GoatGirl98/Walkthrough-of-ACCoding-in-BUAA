#pragma G++ optimize(2)
#include<cstdio>
#include<algorithm>
#include<vector>
#define maxn 110
#define INF 0x3f3f3f3f
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
bool occured_edge[maxn][maxn];
int n, m;
int u, v;
int graph[maxn][maxn];//graph[i][j]指j是否为i的子孙
inline void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = Min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
}
struct Info {
    int num;
    int babaZhi;
    int age;
    vector<int> sons;
    vector<int> fathers;
} info[maxn];
bool ifAcalledBsonsFather(Info a, Info b) {
    int A = a.num, B = b.num;
    bool flag = false;
    
    for (int i = 0; i < a.fathers.size(); ++i) {
        if (graph[B][a.fathers[i]] < INF) flag = true;
        else if (a.fathers[i] == B) flag = true;
    }
    return flag;
}
bool cmp(Info a, Info b) {
    if (a.babaZhi != b.babaZhi) return a.babaZhi > b.babaZhi;
    bool a2b = ifAcalledBsonsFather(a, b), b2a = ifAcalledBsonsFather(b, a);
    if (a2b && !b2a) return false;
    if (!a2b && b2a) return true;
    else return a.age > b.age;
}
bool cmpInt(int a, int b) {
    if (info[a].babaZhi != info[b].babaZhi) return info[a].babaZhi > info[b].babaZhi;
    else return info[a].age > info[b].age;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        info[i].num = i;
        for (int j = 1; j <= n; ++j) {
            graph[i][j] = INF;
        }
    }
    while (m--) {
        scanf("%d%d", &u, &v);
        if (u != v) {
            if (!occured_edge[u][v]) {
                info[u].fathers.push_back(v);
                info[v].sons.push_back(u);
                graph[v][u] = 1;
                occured_edge[u][v] = 1;
            }
            --info[u].babaZhi, ++info[v].babaZhi;
        }
    }
    floyd();
    for (int i = 1; i <= n; ++i)scanf("%d", &info[i].age);
    for (int i = 1; i <= n; ++i) sort(info[i].sons.begin(), info[i].sons.end(), cmpInt);
    sort(info + 1, info + n + 1, cmp);
    printf("%d\n", info[1].num);
    for (int i : info[1].sons)printf("%d ", i);
}
