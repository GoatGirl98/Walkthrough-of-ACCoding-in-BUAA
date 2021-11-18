#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define INF 1145141919810LL
#define maxv 100010
#define maxn 110
double dis[maxn][maxn];
double dp[maxn][maxn];
struct point {
    double x, y;
    bool operator < (const point& o)const {
        if (x != o.x)return x < o.x;
        else return y < o.y;
    }
};
double Dis(point& a, point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
point points[maxn];
double res;
int n;
inline void buildDP() {
    dp[0][0] = 0;
    dp[1][0] = dis[1][0];
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = INF;
            if (j < i - 1)dp[i][j] = dp[i - 1][j] + dis[i][i - 1];
            if (j == i - 1) {
                for (int k = 0; k < i - 1; ++k) {
                    dp[i][j] = min(dp[i][j], dp[j][k] + dis[i][k]);
                }
            }
            if (j == i) {
                for (int k = 0; k < i - 1; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + dis[i][k] + dis[i - 1][i]);
                }
            }
        }
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(points, 0, sizeof(points));
        memset(dis, 0, sizeof(dis));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &points[i].x, &points[i].y);
        }
        sort(points, points + n);
        //points[n].x = points[0].x, points[n].y = points[0].y;
        res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = Dis(points[i], points[j]);
            }
        }
        buildDP();
        printf("%.2lf\n", dp[n-1][n-1]);
    }

}
