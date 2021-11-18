#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
#define maxn 100010
using namespace std;
typedef long long ll;
vector<int> g[maxn];
int d[maxn], n, m;
bool occur[maxn];
int a, b;
double ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    queue<int> que;

    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            //叶子节点情况
            que.push(i);
            occur[i] = true;
            d[i] = 0;
        }

    }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        for (int i : g[u]) {
            if (!occur[i]) {
                d[i] = d[u] + 1;
                que.push(i);
                occur[i] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++i)ans += d[i];
    printf("%.4lf", ans / n);
    return 0;
}
