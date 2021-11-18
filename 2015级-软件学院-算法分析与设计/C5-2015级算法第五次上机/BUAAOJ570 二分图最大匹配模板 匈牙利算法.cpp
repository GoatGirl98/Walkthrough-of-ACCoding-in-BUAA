#pragma G++ optimize(2)
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<climits>
#define maxn 1010
using namespace std;
vector<int> g[maxn];//记录双方匹配的二分图
int match[maxn];//匹配点 (代替书上互相匹配的cx和cy数组)
bool occur[maxn];//访问
int n, m, res;
int a[maxn], b[maxn];
int u, v;
inline bool findpath(int u) {
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!occur[v]) {
            occur[v] = true;
            if (!match[v] || findpath(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

inline int MaxMatch() {
    res = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= 1000; ++i) {
        memset(occur, 0, sizeof(occur));
        if (findpath(i))++res;
    }
    return res;
}

int main() {

    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i < maxn; ++i)g[i].clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &u, &v);
            g[v].push_back(u);
        }

        printf("%d\n", MaxMatch());
    }
}
