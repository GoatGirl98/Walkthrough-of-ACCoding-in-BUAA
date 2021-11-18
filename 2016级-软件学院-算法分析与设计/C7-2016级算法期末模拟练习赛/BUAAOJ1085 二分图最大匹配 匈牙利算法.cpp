#pragma G++ optimize(2)
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<climits>
#define maxn 1010
using namespace std;
/*****************************************
本题为二分图的最小覆盖问题
两个集合中b[j]被a[i]整除时两者去其中之一
求其中最少去掉的点

转换为最大匹配
则是匹配两集合内任意b[j]都不整除a[i]的点
一共有多少对

然后就是板子了
*****************************************/

vector<int> g[maxn];//记录双方匹配的二分图
int match[maxn];//匹配点 (代替书上互相匹配的cx和cy数组)
bool occur[maxn];//访问
int n, m, res;
int a[maxn], b[maxn];

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
    for (int i = 1; i <= m; ++i) {
        memset(occur, 0, sizeof(occur));
        if (findpath(i))++res;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m) {
        for (int i = 1; i < maxn; ++i)g[i].clear();
        for (int i = 1; i <= n; ++i)cin >> a[i];
        for (int i = 1; i <= m; ++i) {
            cin >> b[i];
            for (int j = 1; j <= n; ++j) {
                if (!(b[i] % a[j]))g[i].push_back(j);
            }
        }
        cout << MaxMatch() << endl;
    }
}
