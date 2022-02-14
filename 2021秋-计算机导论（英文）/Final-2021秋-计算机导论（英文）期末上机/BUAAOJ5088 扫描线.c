#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200010
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) | 1)
typedef long long ll;
double read_double()
{
    double k = 0.0, f = 1.0;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1.0;
        c = getchar();
    }
    while (isdigit(c))
    {
        k = k * 10.0 + (c ^ 48);
        c = getchar();
    }
    if (c == '.')
    {
        double fraction = 1;
        c = getchar();
        while (isdigit(c))
        {
            fraction /= 10;
            k += (c ^ 48) * fraction;
            c = getchar();
        }
    }
    return k * f;
}
//input : left-down and right-up point
typedef struct oper
{
    double xl, xr, y;
    int tag;
} oper;
oper op[N];
int cmp_oper(const void *p1, const void *p2)
{
    oper *a = (oper *)p1, *b = (oper *)p2;
    if (a->y < b->y)
        return -1;
    else if (a->y > b->y)
        return 1;
    else
        return 0;
}
int n;
double all_x[N]; 
int x_cnt;
double ans;
int cmp_db(const void *p1, const void *p2)
{
    double a = *(double *)p1, b = *(double *)p2;
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}
void unique(double *arr, int *sz)
{
    int i = 0, j = 0;
    while (++j < *sz)
    {
        if (arr[i] != arr[j])
            arr[++i] = arr[j];
        //if(curDuplicate)curDuplicate++;
        //maxDuplicate = (maxDuplicate > curDuplicate) ? maxDuplicate : curDuplicate;
        //curDuplicate = 0;
        //else curDuplicate++;
    }
    //if (curDuplicate)curDuplicate++;
    //maxDuplicate = (maxDuplicate > curDuplicate) ? maxDuplicate : curDuplicate;
    //curDuplicate = 0;
    *sz = ++i;
    return;
}
//Segment Tree
double sum[N << 2], tag[N << 2];
void init(int n) { memset(sum, 0, sizeof(sum[0]) * (n << 2)), memset(tag, 0, sizeof(tag[0]) * (n << 2)); }
void update_add(int p, int l, int r, double ql, double qr, double v)
{
    if (ql <= all_x[l] && all_x[r] <= qr)
    {
        if (tag[p] += v)
            sum[p] = all_x[r] - all_x[l];
        else if (l + 1 != r)
            sum[p] = sum[lc(p)] + sum[rc(p)];
        else
            sum[p] = 0;
        return;
    }
    int md = (l + r) >> 1;
    if (ql < all_x[md])
        update_add(lc(p), l, md, ql, qr, v);
    if (qr > all_x[md])
        update_add(rc(p), md, r, ql, qr, v);
    if (!tag[p])
        sum[p] = sum[lc(p)] + sum[rc(p)];
}
int main()
{
    int T = 1;
    while (T--)
    {
        n = 3, ans = x_cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            double X1 = read_double(), Y1 = read_double(), X2 = read_double(), Y2 = read_double();
            all_x[++x_cnt] = X1;
            op[x_cnt].xl = X1, op[x_cnt].xr = X2, op[x_cnt].y = Y1, op[x_cnt].tag = 1;
            all_x[++x_cnt] = X2;
            op[x_cnt].xl = X1, op[x_cnt].xr = X2, op[x_cnt].y = Y2, op[x_cnt].tag = -1;
        }
        n <<= 1;

        qsort(all_x + 1, n, sizeof(all_x[0]), cmp_db);
        unique(all_x + 1, &x_cnt);
        init(x_cnt);
        qsort(op + 1, n, sizeof(oper), cmp_oper);
        for (int i = 1; i < n; ++i)
        {
            update_add(1, 1, x_cnt, op[i].xl, op[i].xr, op[i].tag);
            ans += sum[1] * (op[i + 1].y - op[i].y);
        }
        printf("%.2f\n", ans);
    }
}