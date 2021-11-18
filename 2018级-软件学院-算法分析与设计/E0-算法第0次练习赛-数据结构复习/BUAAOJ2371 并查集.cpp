#include<cstdio>
#define maxn 200010

int a[maxn];

inline int getFather(int x) {
    return a[x] ? a[x] = getFather(a[x]) : x;//最顶层有的话，就返回最顶层，否则自己就是最顶层
}
int n, m;
int ans;
int l, r;
int main() {
    scanf("%d%d", &n, &m);
    ans = n;
    while (m--) {
        scanf("%d%d", &l, &r);
        l = getFather(l);
        while (l <= r) {
            //左端点往右边挪，减少答案值
            a[l] = l + 1;//l被拯救了
            ans--;
            l = getFather(l);
        }
        printf("%d\n", ans);
    }
    return 0;
}
