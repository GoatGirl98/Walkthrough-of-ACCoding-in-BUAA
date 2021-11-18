#include<cstdio>
#include<algorithm>
#define maxn 1010
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
typedef long long ll;

struct node {
    int id, x, y;
}a[maxn];
struct Node {
    int id, num;
    bool operator < (const Node& o)const {
        return num < o.num;
    }
}b[maxn];
int ans[maxn];
int n;
ll sum1, sum2;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].x);
        a[i].id = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].y);
        b[i].num = Min(a[i].x, a[i].y);
        b[i].id = i;
    }
    sort(b + 1, b + n + 1);
    int l = 1, r = n;
    for (int i = 1; i <= n; ++i) {
        if (b[i].num == a[b[i].id].x) ans[l++] = b[i].id;
        else ans[r--] = b[i].id;
    }
    for (int i = 1; i <= n; ++i) {
        sum1 += a[ans[i]].x;
        sum2 = Max(sum1, sum2);
        sum2 += a[ans[i]].y;
    }
    printf("%lld\n", sum2);
    //for (int i = 1; i <= n; ++i)
        //printf("%d ", ans[i]);
}
