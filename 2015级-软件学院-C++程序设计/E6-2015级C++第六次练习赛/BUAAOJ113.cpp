#include<cstdio>
#include<vector>
using namespace std;
int n, a, b;
int x;
vector<int> g;
int main() {
    while (scanf("%d%d%d", &n, &a, &b) != EOF) {
        g.clear();
        while (n--) {
            scanf("%d", &x);
            g.push_back(x);
        }
        g.insert(g.begin() + a - 1, -1);
        g.insert(g.begin() + b - 1, -2);
        for (int i = 0; i < g.size() - 1; ++i) {
            printf("%d ", g[i]);
        }
        printf("%d\n", g[g.size() - 1]);
    }
}
