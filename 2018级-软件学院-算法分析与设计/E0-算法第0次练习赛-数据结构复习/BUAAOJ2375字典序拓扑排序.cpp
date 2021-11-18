#pragma GCC optimize(2)
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<cstring>
#define maxn 100010
#define print 0
using namespace std;
typedef vector<int>::iterator IT;
//不保证图连通也可，因为不连通的点也算作没有前驱的点
vector<int>edge[maxn];//邻接表
priority_queue<int> que;//拓扑队列
stack<int> topoList;
int inDegree[maxn];//入度表
int n, m;
int u, v;
inline bool topoSort() {
    while (!que.empty())que.pop();
    for (int i = 1; i <= n; ++i) {
        if (!inDegree[i])que.push(i);
    }
    int cnt = 0;//如果需要记录拓扑序列的话，换一个queue即可
    while (!que.empty()) {
        int newP = que.top();
        topoList.push(newP);
        if (print)cout << "debug : pop " << newP << " out queue" << endl;
        que.pop();
        ++cnt;
        for (int i = 0; i < edge[newP].size(); ++i) {
            inDegree[edge[newP][i]]--;
            if (inDegree[edge[newP][i]] == 0) {
                que.push(edge[newP][i]);
                if (print)cout << "debug : push " << edge[newP][i] << " into queue" << endl;
            }
        }
    }
    while (!topoList.empty()) cout << topoList.top() << " ", topoList.pop();
    cout << endl;
    return cnt == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m) {
        while (!topoList.empty())topoList.pop();
        for (int i = 1; i <= n; ++i) {
            inDegree[i] = 0;
            edge[i].clear();
        }
        while (m--) {
            cin >> u >> v;
            ++inDegree[u];
            edge[v].push_back(u);
        }
        topoSort();
    }
}
