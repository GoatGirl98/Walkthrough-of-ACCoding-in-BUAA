#include<cstdio>
#include<cstring>
#include<climits>
#include<cmath>
#define maxn 110
#define Min(a,b) (((a)<(b))?(a):(b))
const double INF = 1145141919810171717.0;
const double eps = 10e-8;
int n, k;
inline int sgn(double x) {
	if (fabs(x) < eps)return 0;
	if (x < 0)return -1;
	else return 1;
}
struct Point {
	double x, y;
	Point(double xx = 0.0, double yy = 0.0) { x = xx, y = yy; }
	bool operator == (Point b)const {
		return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
	}
	bool operator < (Point b)const {
		return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
	}
	Point operator -(const Point& b)const {
		return Point(x - b.x, y - b.y);
	}
	double operator ^(const Point& b)const {//²æ»ý
		return x * b.y - y * b.x;
	}
	double operator *(const Point& b)const {//µã»ý
		return x * b.x + y * b.y;
	}
	double dis(Point b) {
		return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
	}
};
Point p[maxn][maxn];
double dp[maxn][maxn];
double ans;
double x, y;
inline void buildDP() {
	for (int i = 1; i <= n; ++i)dp[1][i] = 0.0;
	for (int i = 2; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int K = 1; K <= n; ++K) {
				dp[i][j] = Min(dp[i][j], dp[i - 1][K] + p[i][j].dis(p[i - 1][K]));
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		ans = Min(dp[k][i], ans);
}
int main() {
	while (scanf("%d%d", &k, &n) != EOF) {
		ans = INF;
		for (int i = 0; i < maxn; ++i)
			for (int j = 0; j < maxn; ++j)
				dp[i][j] = INF;
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%lf%lf", &x, &y);
				p[i][j] = Point(x, y);
			}
		}
		buildDP();
		printf("%.3f\n", ans);
	}
}