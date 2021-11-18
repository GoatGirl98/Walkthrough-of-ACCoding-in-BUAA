#include<cstdio>
#define maxn 100010
inline void swap(int& a, int& b) {
    a ^= b, b ^= a, a ^= b;
}
int a[maxn];
//插入排序模板
inline void insertSort(int lo, int hi) {
    for (int i = lo + 1; i < hi; ++i) {
        int preIndex = i - 1;
        int cur = a[i];
        while (preIndex >= lo && a[preIndex] > cur) {
            a[preIndex + 1] = a[preIndex];
            preIndex--;
        }
        a[preIndex + 1] = cur;
    }
}
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        insertSort(0, n);
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        puts("");
    }
}
