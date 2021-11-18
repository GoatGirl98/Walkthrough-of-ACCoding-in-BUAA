#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-9;
double rd_db() {
    double k = 0.0, f = 1.0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1.0;
        c = getchar();
    }
    while (isdigit(c)) {
        k = k * 10.0 + ((double)c - 48.0);
        c = getchar();
    }
    if (c == '.') {
        double fraction = 1;
        c = getchar();
        while (isdigit(c)) {
            fraction /= 10;
            k += ((double)c - 48.0) * fraction;
            c = getchar();
        }
    }
    return k * f;
}

int sgn(double x) {
    if (fabs(x) < eps)return 0;
    return x > 0 ? 1 : -1;
}
//point also as Vector
struct point {
    double x, y;
    point(double xx = 0.0, double yy = 0.0) { x = xx, y = yy; }
    void input() { x = rd_db(), y = rd_db(); }
    bool operator == (const point& b)const {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator < (const point& b)const {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    point operator +(const point& b)const {
        return point(x + b.x, y + b.y);
    }
    point operator -(const point& b)const {
        return point(x - b.x, y - b.y);
    }
    point operator *(const double& k)const {
        return point(x * k, y * k);
    }
    point operator /(const double& k)const {
        return point(x / k, y / k);
    }
    double operator ^(const point& b)const {
        return x * b.y - y * b.x;
    }
    double operator *(const point& b)const {
        return x * b.x + y * b.y;
    }
    double dis(const point& o) {
        return sqrt(((x - o.x) * (x - o.x)) + ((y - o.y) * (y - o.y)));
    }
    //vector only
    double len2() {
        return x * x + y * y;
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    //angle APB [0, pi/2]
    double rad(point a, point b) {
        point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }
    //transfer to vector(len = r)
    point trim(double r) {
        double l = len();
        if (!sgn(l)) return *this;//corner case
        r /= l;
        return point(x * r, y * r);
    }
    point rotate90L() {
        return point(-y, x);
    }
    point rotate90R() {
        return point(y, -x);
    }
    //angle is radian [-pi/2, pi/2]
    point rotate(point pivot, double angle) {
        point v = (*this - pivot);
        double c = cos(angle), s = sin(angle);
        return point(pivot.x + v.x * c - v.y * s, pivot.y + v.x * s + v.y * c);
    }
};
//line also as segment and ray
struct line {
    point s, e;
    line() {}
    line(point _s, point _e) :s(_s), e(_e) {}

    //confirm a line by point & angle
    line(point p, double angle) {
        s = p;
        if (sgn(angle - PI / 2) == 0) e = s + point(0, 1);
        else e = s + point(1, tan(angle));
    }
    //ax + by + c = 0
    line(double a, double b, double c) {
        if (sgn(a) == 0) s = point(0, -c / b), e = point(1, -c / b);
        else if (sgn(b) == 0)s = point(-c / a, 0), e = point(-c / a, 1);
        else s = point(0, -c / b), e = point(1, -(a + c) / b);
    }
    void input() { s.input(), e.input(); }
    void trim() { if (e < s) swap(s, e); }
    bool operator ==(const line& o) {
        return (s == o.s) && (e == o.e);
    }
    //segment only
    double len() {
        return s.dis(e);
    }
    //atan2
    //I : (0, pi/2) II : (pi/2, pi) III: (-pi, -pi/2) IV : (-pi/2, 0)
    //(x, 0) : x > 0 ? 0 : pi  (0, y) : y > 0 ? pi/2 : -pi/2
    double angle() {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += PI;
        if (sgn(k - PI) >= 0)k -= PI;
        return k;
    }
    /*
    *  point relationship with line
    *  1. left
    *  2. right
    *  3. on seg
    */
    int relation(const point& p) {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0) return 1;
        else if (c > 0)return 2;
        else return 3;
    }
    bool point_on_seg(const point& p) {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }
    bool parallel(const line& v) {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    /*
    *  seg_cross_seg
    *  2. regular
    *  1. irregular (cross at Endpoint)
    *  0. no
    */
    int seg_cross_seg(const line& v) {
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
    /*
    *  line_cross_seg
    *  *this is line v is seg
    *  2. regular
    *  1. irregular (cross at Endpoint)
    *  0. no
    */
    int line_cross_seg(const line& v) {
        double d1 = (e - s) ^ (v.s - s);
        double d2 = (e - s) ^ (v.e - s);
        int flag = sgn(d1) * sgn(d2);
        return flag < 0 ? 2 : flag == 0 ? 1 : 0;
    }
    /*
    *  line_cross_line
    *  *this is line v is seg
    *  0. parallel
    *  1. overlap
    *  2. intersect
    */
    int line_cross_line(line v) {
        if (parallel(v)) return v.relation(s) == 3;
        else return 2;
    }
    //guaranteed intersected
    point cross_point(line v) {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    double dis_point_to_line(point p) {
        return fabs((p - s) ^ (e - s)) / len();
    }
    double dis_point_to_seg(point p) {
        if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
            return min(p.dis(s), p.dis(e));
        else return dis_point_to_line(p);
    }
    double dis_seg_to_seg(line v) {
        return min(min(dis_point_to_seg(v.s), dis_point_to_seg(v.e)), min(v.dis_point_to_seg(s), v.dis_point_to_seg(e)));
    }
    //p's projection on line
    point line_prog(point p) {
        return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
    }
    point symmetry_point(point p) {
        point q = line_prog(p);
        return point(2 * q.x - p.x, 2 * q.y - p.y);
    }
    /*
    *  pos_seg_and_seg
    *  *this is seg v is seg
    *  0. Parallel
    *  1. Collinear
    *  2. Perpendicular
    *  3. Vanilla
    */
    int pos_seg_and_seg(const line& b) {
        int flag = line_cross_line(b);
        if (flag == 0 || flag == 1) return flag;
        else if (sgn((e - s) * (b.e - b.s)) == 0) return 2;
        else return 3;
    }
    /*
    *  inter_seg_and_seg
    *  *this is seg v is seg
    *  0. None
    *  1. Unique_X
    *  2. Unique_T
    *  3. Unique_V
    *  4. Infinite
    */
    int inter_seg_and_seg(line b) {
        int flag1 = seg_cross_seg(b), flag2 = line_cross_line(b);
        if (flag1 == 0 || flag2 == 0) return 0;
        else if (flag1 == 2) return 1;
        //flag = (p == a.s || p == a.e) + (p == b.s || p == b.e);
        int flag3 = point_on_seg(b.e) + point_on_seg(b.s) + b.point_on_seg(s) + b.point_on_seg(e);
        int flag4 = (b.e == s) || (b.e == e) || (b.s == s) || (b.s == e);
        if (flag3 == 0) return 1;
        else if (flag3 == 1) return 2;
        else if (flag3 == 2 && flag4)return 3;
        else return 4;
    }
};

struct circle {
    point p;//the centre of the circle
    double r;//radius
    circle(point _p = point(), double _r = 0) {
        p = _p;
        r = _r;
    }
    circle(double x, double y, double _r) {
        p = point(x, y);
        r = _r;
    }
    /*
    * circumscribed circle/inscribed circle of triangle
    * flag 0 : cc
    * flag 1 : ic
    */
    circle(point a, point b, point c, bool flag) {
        if (!flag) {
            line u = line((a + b) / 2, ((a + b) / 2) + ((b - a).rotate90L()));
            line v = line((b + c) / 2, ((b + c) / 2) + ((c - b).rotate90L()));
            p = u.cross_point(v);
            r = p.dis(a);
        }
        else {
            line u = line(), v = line();
            double m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
            u.s = a;
            u.e = u.s + point(cos((n + m) / 2), sin((n + m) / 2));
            v.s = b;
            m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
            v.e = v.s + point(cos((n + m) / 2), sin((n + m) / 2));
            p = u.cross_point(v);
            r = line(a, b).dis_point_to_seg(p);
        }
    }
    void input() {
        p.input(), r = rd_db();
    }
    void output(int flag = 0) {
        switch (flag) {
        case 1: printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", p.x > 0 ? '-' : '+', fabs(p.x), p.y > 0 ? '-' : '+', fabs(p.y), fabs(r)); break;
        case 2: printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n", (2 * p.x) > 0 ? '-' : '+', fabs(2 * p.x), (2 * p.y) > 0 ? '-' : '+', fabs(2 * p.y), (p.x * p.x + p.y * p.y - r * r) > 0 ? '+' : '-', fabs((p.x * p.x + p.y * p.y - r * r))); break;
        case 3: printf("%.5f %.5f %.5f\n", -2 * p.x + eps, -2 * p.y + eps, p.x * p.x + p.y * p.y - r * r + eps); break;
        default: printf("(%.6f,%.6f,%.6f)\n", p.x + eps, p.y + eps, r); break;
        }
    }
    bool operator == (circle v) {
        return (p == v.p) && sgn(r - v.r) == 0;
    }
    bool operator < (circle v)const {
        return ((p < v.p) || ((p == v.p) && sgn(r - v.r) < 0));
    }
    double area() {
        return PI * r * r;
    }
    double circumference() {
        return 2 * PI * r;
    }
    /*
    *  relation point
    *  0. out
    *  1. on
    *  2. in
    */
    int relation_pt(point b) {
        double dis = b.dis(p);
        int flag = sgn(dis - r);
        if (flag < 0) return 2;
        else if (flag == 0) return 1;
        else return 0;
    }
    /*
    *  relation seg
    *  0. disjoint
    *  1. tangent
    *  2. intersect
    */
    int relation_seg(line v) {
        double dis = v.dis_point_to_seg(p);
        int flag = sgn(dis - r);
        if (flag < 0)return 2;
        else if (flag == 0)return 1;
        return 0;
    }
    /*
    *  relation line
    *  0. disjoint
    *  1. tangent
    *  2. intersect
    */
    int relation_line(line v) {
        double dis = v.dis_point_to_line(p);
        int flag = sgn(dis - r);
        if (flag < 0)return 2;
        else if (flag == 0)return 1;
        return 0;
    }
    /*
    *  relation circle
    *  5. disjoint
    *  4. tangent external
    *  3. intersect
    *  2. tangent internal
    *  1. inclusion
    */
    int relation_circle(circle v) {
        double d = p.dis(v.p), l = fabs(r - v.r);
        int flag1 = sgn(d - r - v.r), flag2 = sgn(d - l);
        if (flag1 > 0)return 5;
        if (flag1 == 0)return 4;
        if (flag1 < 0 && flag2 > 0)return 3;
        if (flag2 == 0)return 2;
        if (flag2 < 0)return 1;
    }
    /*
    *  circle cross circle
    *  return at counts of point
    *  2/1/0
    */
    int point_cross_circle(circle v, point& p1, point& p2) {
        p1 = point(), p2 = point();
        int rel = relation_circle(v);
        if (rel == 1 || rel == 5)return 0;
        double d = p.dis(v.p);
        double l = (d * d + r * r - v.r * v.r) / (2 * d);
        double h = sqrt(r * r - l * l);
        point tmp = p + (v.p - p).trim(l);
        p1 = tmp + ((v.p - p).rotate90L().trim(h));
        p2 = tmp + ((v.p - p).rotate90R().trim(h));
        if (rel == 2 || rel == 4) return 1;
        else return 2;
    }
    /*
    *  circle cross line
    *  return at counts of point
    *  2/1/0
    */
    int point_cross_line(line v, point& p1, point& p2) {
        if (!relation_line(v))return 0;
        point a = v.line_prog(p);
        double d = v.dis_point_to_line(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0) {
            p1 = a;
            p2 = a;
            return 1;

        }
        else {
            p1 = a + (v.e - v.s).trim(d);
            p2 = a - (v.e - v.s).trim(d);
            return 2;
        }
    }
    /*
    *  generate 0/1/2 tangent line with *this
    *  passing through q
    */
    int tangent_line(point q, line& u, line& v) {
        int x = relation_pt(q);
        if (x == 2)return 0;
        if (x == 1) {
            u = line(q, q + (q - p).rotate90L());
            v = u;
            return 1;
        }
        else {
            double d = p.dis(q);
            double l = r * r / d;
            double h = sqrt(r * r - l * l);
            u = line(q, p + ((q - p).trim(l) + (q - p).rotate90L().trim(h)));
            v = line(q, p + ((q - p).trim(l) + (q - p).rotate90R().trim(h)));
            return 2;
        }
    }
    /*
    *  generate 0/1/2 circle
    *  radius is r1
    *  passing through 2 points respectively
    */
    int get_circle(point a, point b, double r1, circle& c1, circle& c2) {
        circle x(a, r1), y(b, r1);
        int t = x.point_cross_circle(y, c1.p, c2.p);
        if (!t)return 0;
        c1.r = c2.r = r;
        return t;
    }
    /*
    *  generate 0/1/2 circle
    *  radius is r1
    *  tangent with line u
    *  passing through point q
    */
    int get_circle(line u, point q, double r1, circle& c1, circle& c2) {
        double dis = u.dis_point_to_line(q);
        if (sgn(dis - r1 * 2) > 0)return 0;
        if (sgn(dis) == 0) {
            c1.p = q + ((u.e - u.s).rotate90L().trim(r1));
            c2.p = q + ((u.e - u.s).rotate90R().trim(r1));
            c1.r = c2.r = r1;
            return 2;
        }
        line u1 = line((u.s + (u.e - u.s).rotate90L().trim(r1)), (u.e + (u.e - u.s).rotate90L().trim(r1)));
        line u2 = line((u.s + (u.e - u.s).rotate90R().trim(r1)), (u.e + (u.e - u.s).rotate90R().trim(r1)));
        circle cc = circle(q, r1);
        point p1, p2;
        if (!cc.point_cross_line(u1, p1, p2))cc.point_cross_line(u2, p1, p2);
        c1 = circle(p1, r1);
        if (p1 == p2) {
            c2 = c1;
            return 1;
        }
        else {
            c2 = circle(p2, r1);
            return 2;
        }
    }
    /*
    *  generate 0/4 circle
    *  radius is r1
    *  tangent with line u, v
    */
    int get_circle(line u, line v, double r1, circle& c1, circle& c2, circle& c3, circle& c4) {
        if (u.parallel(v))return 0;//u and v is parallel so answer is 0 or infinity(u.dis(v) == 2*r1)
        line u1 = line(u.s + (u.e - u.s).rotate90L().trim(r1), u.e + (u.e - u.s).rotate90L().trim(r1));
        line u2 = line(u.s + (u.e - u.s).rotate90R().trim(r1), u.e + (u.e - u.s).rotate90R().trim(r1));
        line v1 = line(v.s + (v.e - v.s).rotate90L().trim(r1), v.e + (v.e - v.s).rotate90L().trim(r1));
        line v2 = line(v.s + (v.e - v.s).rotate90R().trim(r1), v.e + (v.e - v.s).rotate90R().trim(r1));
        c1.r = c2.r = c3.r = c4.r = r1;
        c1.p = u1.cross_point(v1);
        c2.p = u1.cross_point(v2);
        c3.p = u2.cross_point(v1);
        c4.p = u2.cross_point(v2);
        return 4;
    }
   /*
   *  generate 0/1/2 circle
   *  radius is r1
   *  tangent externally with circle cx cy
   */
    int get_circle(circle cx, circle cy, double r1, circle& c1, circle& c2) {
        circle x(cx.p, r1 + cx.r), y(cy.p, r1 + cy.r);
        int t = x.point_cross_circle(y, c1.p, c2.p);
        if (!t)return 0;
        c1.r = c2.r = r1;
        return t;
    }
    /*
    *  intersection area with circle
    */
    double area_intersection_circle(circle v) {
        int rel = relation_circle(v);
        if (rel >= 4)return 0.0;
        if (rel <= 2)return min(area(), v.area());
        double d = p.dis(v.p);
        double hf = (r + v.r + d) / 2.0;
        double ss = 2 * sqrt(hf * (hf - r) * (hf - v.r) * (hf - d));
        double a1 = acos((r * r + d * d - v.r * v.r) / (2.0 * r * d));
        a1 = a1 * r * r;
        double a2 = acos((v.r * v.r + d * d - r * r) / (2.0 * v.r * d));
        a2 = a2 * v.r * v.r;
        return a1 + a2 - ss;
    }
    /*
    *  intersection area with triangle PAB (P is the centre of the circle)
    */
    double area_intersection_triangle(point a, point b) {
        if (sgn((p-a) ^ (p-b)) == 0)return 0.0;
        point q[5];
        int len = 0;
        q[len++] = a;
        line l(a, b);
        point p1, p2;
        if (point_cross_line(l, q[1], q[2]) == 2) {
            if (sgn((a-q[1]) * (b-q[1])) < 0)q[len++] = q[1];
            if (sgn((a-q[2]) * (b-q[2])) < 0)q[len++] = q[2];
        }
        q[len++] = b;
        if (len == 4 && sgn((q[0]-q[1]) * (q[2]-q[1])) > 0)swap(q[1], q[2]);
        double res = 0;
        for (int i = 0; i < len-1; i++) {
            if (relation_pt(q[i]) == 0 || relation_pt(q[i + 1]) == 0)
                res += r * r * p.rad(q[i], q[i + 1]) / 2.0;
            else
                res += fabs((q[i] - p) ^ (q[i + 1] - p)) / 2.0;
        }
        return res;
    }
};

point A, B, C, D, E, F, G, H, I, J, K, L, M, N, O;
point tmp[2]; int tmp_cnt;
line seg[5];
circle cir[5], ans;

int main() {
    A.input(), B.input(), C.input(), D.input(), E.input();
    seg[0] = line(A, C), seg[1] = line(C, E), seg[2] = line(E, B), seg[3] = line(B, D), seg[4] = line(D, A);
    F = seg[0].cross_point(seg[2]), G = seg[0].cross_point(seg[3]), H = seg[1].cross_point(seg[3]), I = seg[1].cross_point(seg[4]), J = seg[2].cross_point(seg[4]);
    cir[0] = circle(A, J, F, 0), cir[1] = circle(B, F, G, 0), cir[2] = circle(C, G, H, 0), cir[3] = circle(D, H, I, 0), cir[4] = circle(E, I, J, 0);

    tmp_cnt = cir[0].point_cross_circle(cir[1], tmp[0], tmp[1]); L = (tmp[0] == F) ? tmp[1] : tmp[0];
    tmp_cnt = cir[1].point_cross_circle(cir[2], tmp[0], tmp[1]); M = (tmp[0] == G) ? tmp[1] : tmp[0];
    tmp_cnt = cir[2].point_cross_circle(cir[3], tmp[0], tmp[1]); N = (tmp[0] == H) ? tmp[1] : tmp[0];
    tmp_cnt = cir[3].point_cross_circle(cir[4], tmp[0], tmp[1]); O = (tmp[0] == I) ? tmp[1] : tmp[0];
    tmp_cnt = cir[4].point_cross_circle(cir[0], tmp[0], tmp[1]); K = (tmp[0] == J) ? tmp[1] : tmp[0];

    ans = circle(L, M, N, 0);
    ans.output(3);
}