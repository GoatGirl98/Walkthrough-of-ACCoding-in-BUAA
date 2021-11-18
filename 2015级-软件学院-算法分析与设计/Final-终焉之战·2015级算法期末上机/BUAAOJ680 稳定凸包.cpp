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
    int x, y;
    Point(int xx = 0.0, int yy = 0.0) {x = xx, y = yy;}
    double dis(Point o) {
        return hypot(x - o.x, y - o.y);
    }
    Point operator -(const Point& o) const {
        return Point(x - o.x, y - o.y);
    }
    int operator ^(const Point& o) const {
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
bool flag;
int n, t;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        flag = true;
        memset(points, 0, sizeof(points));
        memset(stack, 0, sizeof(stack));
        cnt = 1;
        ans = 0.0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d",&points[i].x,&points[i].y);
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
            while(cnt > 1 && (Point(stack[cnt] - stack[cnt - 1]) ^ Point(points[i] - stack[cnt])) < 0)//共线也加进来
                cnt--;
            stack[++cnt] = points[i];
        }
        stack[cnt+1]=points[1];
        stack[0]=stack[cnt];//最后绕一圈回来
        //if(cnt <= 2)cnt--;
        for(int i = 1; i<cnt&&flag; ++i) {
            bool flag1 =((stack[i]-stack[i-1])^(stack[i+1]-stack[i]))==0;
            bool flag2 =((stack[i+1]-stack[i])^(stack[i+2]-stack[i+1]))==0;
            if(!flag1&&!flag2)flag=false;
        }
        puts(flag?"Yes":"No");
    }
}
