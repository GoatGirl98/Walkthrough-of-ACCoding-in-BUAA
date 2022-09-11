#include <cstdio>
#include <cstring>
#define maxn 250010
inline int firstEqual(int arr[], int lo, int hi, int target) {
    while (lo <= hi) {
        int mi = (hi+lo)>>1;
               if (arr[mi] == target)  return mi;
        if (arr[mi] < target)lo = mi + 1;
        else if (arr[mi] > target) hi = mi-1;//就算找到了，也要往下界接着找
                
    }
    return -1;
}
int a[maxn];
int n, m;
int find;
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        while (m--) {
            scanf("%d", &find);
            int flag = firstEqual(a, 1, n, find);
            if (flag >= 1)printf("%d\n", flag);
            else printf("tan90\n");
        }
    }
}
