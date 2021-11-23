#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 200005;
const double INF = 1e15;
const double eps = 1e-8;

int n;
double mind;
struct point
{
    double x, y;
    bool type;
    bool operator<(const point &t) const { return x < t.x; }
} points[N], tmp[N];

double get_dist(point a, point b)
{
    if (a.type == b.type)
        return mind; // optimize when all the points are overlapped
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double dfs(int l, int r)
{
    if (l == r)
        return INF;
    int mid = (l + r) >> 1;
    double mid_x = points[mid].x;
    double ans = min(dfs(l, mid), dfs(mid + 1, r));

    int i = l, j = mid + 1, cnt = 0;
    while (i <= mid && j <= r)
        if (points[i].y < points[j].y)
            tmp[cnt++] = points[i++];
        else
            tmp[cnt++] = points[j++];
    while (i <= mid)
        tmp[cnt++] = points[i++];
    while (j <= r)
        tmp[cnt++] = points[j++];
    for (i = l; i <= r; i++)
        points[i] = tmp[i - l];

    cnt = 0;
    for (i = l; i <= r; i++)
        if (points[i].x >= mid_x - ans && points[i].x <= mid_x + ans)
            tmp[cnt++] = points[i];
    for (i = 0; i < cnt; i++)
        for (j = i - 1; ~j && tmp[i].y - tmp[j].y + eps <= ans; j--)
            ans = min(ans, get_dist(tmp[i], tmp[j]));
    mind = min(mind, ans);
    return ans;
}

int main()
{
    int T;
    while (scanf("%d", &T) != EOF)
    {
        while (T--)
        {
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%lf %lf", &points[i].x, &points[i].y);
                points[i].type = false;
            }
            for (int i = n; i < n << 1; i++)
            {
                scanf("%lf %lf", &points[i].x, &points[i].y);
                points[i].type = true;
            }
            mind = get_dist(points[0], points[(n << 1) - 1]);
            sort(points, points + (n << 1));
            printf("%.3f\n", dfs(0, (n << 1) - 1));
        }
    }
    return 0;
}
