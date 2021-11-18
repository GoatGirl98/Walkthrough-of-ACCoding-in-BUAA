#include<cstdio>
#include<cstring>
typedef long long ll;
int d, n;
struct Info {
    int x, y;
    ll k;
}a[25];
ll ans, tmp;
int cnt;
int main() {
    scanf("%d%d", &d, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%lld", &a[i].x, &a[i].y, &a[i].k);
    for (int i = 0; i <= 128; ++i) {
        for (int j = 0; j <= 128; ++j) {
            tmp = 0;
            for (int m = 0; m < n; ++m)
                if (a[m].x >= i - d && a[m].x <= i + d && a[m].y >= j - d && a[m].y <= j + d)
                    tmp += a[m].k;
            if (tmp > ans)ans = tmp, cnt = 1;
            else if (tmp == ans)cnt++;
        }
    }
    printf("%d %lld", cnt, ans);

}
