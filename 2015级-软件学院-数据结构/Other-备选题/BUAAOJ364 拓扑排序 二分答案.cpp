#pragma GCC optimize(2)
#include<cstdio>
#include<queue>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<climits>
#define print 0
#define maxn 10010
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int, int>PII;
//不保证图连通也可，因为不连通的点也算作没有前驱的点
struct Node {
    int inDegree;//实际入度
    vector<PII>edge;
} node[maxn];
queue<int> que;//拓扑队列
int inDegreeBackup[maxn];//入度表
int n, m;
int u, v, w;
int Min, Max, Mid;//二分答案用
int t;
inline bool topoSort(int skip) {
    while (!que.empty())que.pop();
    for (int i = 1; i <= n; ++i) node[i].inDegree = inDegreeBackup[i];
    for (int i = 1; i <= n; ++i) {
        //node[i].inDegree += inDegreeBackup[i];
        for (int j = 0; j < node[i].edge.size(); ++j) {
            if (node[i].edge[j].y <= skip) {
                node[node[i].edge[j].x].inDegree--;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (node[i].inDegree == 0)que.push(i);
    }
    int cnt = 0;
    while (!que.empty()) {
        int newP = que.front();
        que.pop();
        ++cnt;
        for (int i = 0; i < node[newP].edge.size(); ++i) {
            if (node[newP].edge[i].y > skip) {
                node[node[newP].edge[i].x].inDegree--;
                if (node[node[newP].edge[i].x].inDegree == 0) {
                    que.push(node[newP].edge[i].x);
                }
            }
        }
    }
    return cnt == n;
    
}
inline void write(int x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}
int main() {
    t = read();
    while (t--) {
        Min = INT_MAX; Max = 0; Mid = 0;
        n = read(), m = read();
        for (int i = 1; i <= n; ++i) {
            inDegreeBackup[i] = 0;
            node[i].inDegree = 0;
            node[i].edge.clear();
        }
        while (m--) {
            u = read(), v = read(), w = read();
            if (w > Max)Max = w; if (Min > w)Min = w;
            ++inDegreeBackup[v];
            node[u].edge.push_back(mp(v, w));
        }
        if (print) { write(Max); putchar(' '); write(Min); putchar('\n'); }
        //二分答案这里有点问题再想想
        if (topoSort(Min - 1)) {
            write(0); putchar('\n'); continue;
            //如果不需要去掉任何边，则智商为0即可
        }
        if (topoSort(Min)) {
            write(Min); putchar('\n'); continue;
            //上面不行，最小值可去掉的话，则答案就是最小值
        }
        
        while (Max > Min) {
            Mid = (Max + Min) >> 1;
            if (print) { write(Mid); putchar('\n'); }
            if (topoSort(Mid)) Max = Mid;
            else Min = Mid + 1;
        }
        write(Min); putchar('\n');
    }

    
}
