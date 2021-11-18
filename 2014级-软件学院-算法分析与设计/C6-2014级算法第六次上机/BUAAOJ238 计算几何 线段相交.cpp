#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 100010
using namespace std;
const double eps = 10e-8;
inline int sgn(double x) {
	if (fabs(x) < eps)return 0;
	if (x < 0)return -1;
	else return 1;
}
struct Point {
	double x, y;
	Point(double xx = 0.0, double yy = 0.0) { x = xx, y = yy; }
	bool operator == (Point b)const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	bool operator < (Point b)const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
	}
	Point operator -(const Point & b)const {\
		return Point(x-b.x, y-b.y);
	}
	double operator ^(const Point & b)const {//叉积
		return x * b.y - y * b.x;
	}
	double operator *(const Point & b)const {//点积
		return x * b.x + y * b.y;
	}
};
struct Line {
	Point s, e;
	Line(){}
	inline void adjust() { if (e < s)swap(s, e); }
	Line(Point _s, Point _e) { s = _s, e = _e; adjust(); }
	bool operator == (Line v) { return s == v.s || e == v.e; }
	bool parallel(Line v) { return sgn((e - s) ^ (v.e - v.s)) == 0; }
	int segcrossseg(Line v) {
		//本题重合视为相交,在这里统一视为非规范相交
		//重合是否算相交视情况而定
		//2:规范 1:非规范 0:不相交
		int d1 = sgn((e - s) ^ (v.s - s));
		int d2 = sgn((e - s) ^ (v.e - s));
		int d3 = sgn((v.e - v.s) ^ (s - v.s));
		int d4 = sgn((v.e - v.s) ^ (e - v.s));
		//位运算技巧:两者异号就是相跨,规范相交
		if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)return 2;
		bool b1 = (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0);
		bool b2 = (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0);
		bool b3 = (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0);
		bool b4 = (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
		return (int)(b1 || b2 || b3 || b4);
	}
};
Line line[maxn];
bool isOverlapped[maxn];
int n;
double X1, Y1, X2, Y2;
int main() {
	while (scanf("%d", &n) != EOF) {
		memset(isOverlapped, 0, sizeof(isOverlapped));
		for (int i = 1; i <= n; ++i) {
			scanf("%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2);
			line[i] = Line(Point(X1, Y1), Point(X2, Y2));
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (line[i].segcrossseg(line[j])) {
					isOverlapped[i] = true; break;
				}
			}
		}
		for (int i = 1; i <= n; ++i)
			if (!isOverlapped[i])printf("%d ", i);
		puts("");
	}
}
