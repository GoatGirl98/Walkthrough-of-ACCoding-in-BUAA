#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#define maxn 200010
#define INF 1145141919810114514LL
using namespace std;
typedef long long ll;
struct Point {
    ll x,y;
    Point(ll xx = 0, ll yy = 0) {x = xx, y = yy;}
    Point operator - (const Point& o) const {
        return Point(x - o.x, y - o.y);
    }
    ll operator ^(const Point& o) const {
        return x * o.y - y * o.x;
    }
    ll dis2(Point o) {
        return (x-o.x)*(x-o.x)+(y-o.y)*(y-o.y);
    }
    double dis(Point o) {
        return hypot(x - o.x, y - o.y);
    }
}p[maxn], s[maxn];
inline ll read() {
    ll k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
int n,cnt;
inline bool cmp(Point a, Point b) {
    ll flag = (a - p[1]) ^ (b - p[1]);
    if(flag > 0)return true;
    else if (flag == 0 && a.dis(p[1]) < b.dis(p[1])) return true;
    else return false;
    
}
inline void init() {
    cnt = 0;
    memset(p, 0, sizeof(p));
    memset(s, 0, sizeof(s));
}
inline void get_convex() {
    for(int i = 1; i <= n; ++i) {
        p[i].x = read(), p[i].y = read();
        if(i!=1&&(p[i].y<p[1].y||(p[i].y==p[1].y&&p[i].x<p[1].x)))
            p[i].x ^= p[1].x, p[1].x ^= p[i].x, p[i].x ^= p[1].x,p[i].y ^= p[1].y, p[1].y ^= p[i].y, p[i].y ^= p[1].y;
    }
    sort(p+2,p+n+1,cmp);
    s[++cnt] = p[1], s[++cnt] = p[2];
    for(int i = 3; i <= n; ++i) {
        while(cnt>1&&(Point(s[cnt]-s[cnt-1])^Point(p[i]-s[cnt])) <= 0)
            cnt--;
        s[++cnt]=p[i];
    }
    s[0]=s[cnt];//为了后面的循环，所以把尾部加到前面
}
inline ll get_convex_diameter() {
    if(n==1)return 0ll;
    if(cnt==2)return s[0].dis2(s[1]);
    int j = 2;
    ll ret = 0;
    //此处采用三角形面积的叉乘公式进行对比
    for(int i = 0; i < cnt; ++i) {
        while(((s[i+1]-s[i])^(s[j]-s[i]))<((s[i+1]-s[i])^(s[j+1]-s[i])))
            j=(j+1)%cnt;
        ll tmp = s[i].dis2(s[j]);
        if(tmp>ret)ret=tmp;
        tmp = s[i+1].dis2(s[j]);
        if(tmp>ret)ret=tmp;
    }
    return ret;
}
int main() {
    int t = 2;
    while(scanf("%d",&n)!=EOF) {
        init();
        get_convex();
        printf("%lld\n",get_convex_diameter());
    }
}
