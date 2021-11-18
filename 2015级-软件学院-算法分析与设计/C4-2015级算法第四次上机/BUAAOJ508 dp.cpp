#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int f, c;
struct info {
    int f, c;
    info(int _f = 0, int _c = 0) { f = _f, c = _c; }
    bool operator < (const info& o) const {
        return (1.0 * f / c) < (1.0 * o.f / o.c);
    }
};
int x[105];
info g[105][105];
int fs[10086];
int fsSize;
bool occur[105];
info ans, tmp, tmp2;
int main() {
    while (scanf("%d", &n) != EOF) {
        fsSize = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", x + i);
            for (int j = 0; j < x[i]; ++j) {
                scanf("%d%d", &g[i][j].f, &g[i][j].c);
                fs[fsSize++] = g[i][j].f;
            }
        }
        double ans = 0;
        for (int ti = 0; ti < fsSize; ++ti) {
            int c = 0;
            memset(occur, false, sizeof(occur));
            for (int i = 0; i < n; ++i) {
                int minc = 2147483647;
                for (int j = 0; j < x[i]; ++j) {
                    if (g[i][j].f >= fs[ti] && g[i][j].c < minc) {
                        minc = g[i][j].c;
                        occur[i] = true;
                    }
                }
                c += minc;
            }
            bool ansflag = true;
            for (int i = 0; i < n; ++i)ansflag &= occur[i];
            if (ansflag) {
                ans = max(1.0 * fs[ti] / c, ans);
            }
        }
        printf("%.2lf\n", ans);
    }
}
