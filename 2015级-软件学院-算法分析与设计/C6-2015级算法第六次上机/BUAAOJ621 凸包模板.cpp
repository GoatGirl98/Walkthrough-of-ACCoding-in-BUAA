#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100010
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const double PI = acos(-1.0);
struct Point {
    double x, y;
    Point(double xx = 0.0, double yy = 0.0) {x = xx, y = yy;}
    double dis(Point o) {
        return hypot(x - o.x, y - o.y);
    }
    Point operator -(const Point& o) const {
        return Point(x - o.x, y - o.y);
    }
    double operator ^(const Point& o) const {
        return x * o.y - y * o.x;
    }
}points[maxn], stack[maxn];
int cnt;
double ans;
bool cmp(Point a, Point b) {
    double flag = (a - points[1]) ^ (b - points[1]);
    if(flag > 0.0)return true;
    else if (flag == 0.0 && a.dis(points[1]) < b.dis(points[1])) return true;
    else return false;
}
int n, r;
int main() {
    while(scanf("%d%d",&n, &r)!=EOF) {
        memset(points, 0, sizeof(points));
        memset(stack, 0, sizeof(stack));
        cnt = 1;
        ans = 0.0;
        for(int i = 1; i <= n; ++i) {
            scanf("%lf%lf",&points[i].x,&points[i].y);
            if(i != 1) {
                if(points[i].y < points[1].y)
                    swap(points[i], points[1]);
                else if (points[i].y == points[1].y && points[i].x < points[1].x)
                    swap(points[i], points[1]);
            }
        }
        sort(points + 2, points + n + 1, cmp);
        stack[1] = points[1];
        //右转叉乘是小于0的
        for(int i = 2; i <= n; ++i) {
            while(cnt > 1 && (Point(stack[cnt] - stack[cnt - 1]) ^ Point(points[i] - stack[cnt])) <= 0.0)
                cnt--;
            stack[++cnt] = points[i];
        }
        stack[cnt+1]=points[1];//最后绕一圈回来
        //if(cnt <= 2)cnt--;
        for(int i = 1; i <= cnt; ++i)
            ans += stack[i].dis(stack[i+1]);
        ans += 4.0 * acos(0.0) * (double)r;
        printf("%lld\n",(ll)(ans+0.5));
    }
}

