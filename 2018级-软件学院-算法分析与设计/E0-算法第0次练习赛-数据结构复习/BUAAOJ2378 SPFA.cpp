#pragma G++ optimize(2)
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<climits>
#define maxn 1010
#define RADIX 10
using namespace std;
typedef long long ll;
int graph[maxn][maxn];
ll dis[maxn];
bool occur[maxn];
//SPFA 可处理负权，判断负环，略于堆优dij
inline int read() {
    int k = 0;
    char c = getchar();
    while (!isdigit(c))c = getchar();
    while (isdigit(c)) { k = (k << 1) + (k << 3) + c - 48; c = getchar(); }
    return k;
}
inline void write(int a) {
    if (a >= RADIX)write(a / RADIX);
    putchar(a % RADIX + 48);
}
int t;
int n, m, k;
int tmp;
int u, v, w;
queue<int>q;
inline void SPFA(int from, int size) {
    for (int i = 0; i <= n; ++i) dis[i] = INT_MAX;
    while (!q.empty())q.pop();
    memset(occur, 0, sizeof(occur));
    q.push(from);
    dis[from] = 0;
    occur[from] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        occur[tmp] = false;
        for (int i = 0; i <= n; ++i) {
            if (dis[i] > dis[tmp] + graph[tmp][i]) {
                dis[i] = dis[tmp] + graph[tmp][i];
                //cout << "debug : " << i << " " << tmp << " " << dis[i] << endl;
                if (!occur[i]) {
                    q.push(i); occur[i] = true;
                }
            }
        }
    }
}
int main() {
    t = read();
    while (t--) {
        n = read(), m = read(), k = read();
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                if (i == j)graph[i][j] = 0;
                else graph[i][j] = INT_MAX;
        for (int i = 1; i <= k; ++i) {
            tmp = read();
            graph[0][tmp] = graph[tmp][0] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            u = read(), v = read(), w = read();
            if (graph[u][v] > w)graph[u][v] = graph[v][u] = w;
        }
        SPFA(0, n);
        for (int i = 1; i <= n; ++i) { write(dis[i]); putchar(' '); }
        putchar('\n');
    }
}
