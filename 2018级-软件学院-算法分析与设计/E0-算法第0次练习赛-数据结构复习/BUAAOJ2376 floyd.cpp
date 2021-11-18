#include<algorithm>
#include<iostream>
#include<climits>
#define maxn 310
#define debug 0
using namespace std;
typedef long long ll;
ll floyd[maxn][maxn];
int n, m;
int x, y, z;
inline void init() {
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            if (i == j)floyd[i][j] = 0;
            else floyd[i][j] = INT_MAX;
        }
    }
}
inline void buildDP() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(floyd[i][k]<INT_MAX&& floyd[k][j]<INT_MAX)
                    floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
            }
        }
    }
}
inline void printMap() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (floyd[i][j] == INT_MAX) printf("--- ");
            else printf("%3lld ", floyd[i][j]);
        }
        printf("\n");
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        floyd[x][y] = z;
    }
    buildDP();
    if (debug)printMap();
    cin >> x >> y;
    floyd[x][y] = -floyd[y][x];
    cout << floyd[x][y] << endl;
    buildDP();
    if (debug)printMap();
    cin >> x >> y;
    floyd[x][y] = -floyd[y][x];
    cout << floyd[x][y] << endl;
    buildDP();
    if (debug)printMap();
    cin >> x >> y;
    floyd[x][y] = -floyd[y][x];
    cout << floyd[x][y] << endl;
}
