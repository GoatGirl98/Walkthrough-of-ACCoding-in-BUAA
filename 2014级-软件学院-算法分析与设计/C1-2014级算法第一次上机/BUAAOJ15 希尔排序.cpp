#include<cstdio>
#define maxn 100010
inline void swap(int& a, int& b) {
    a ^= b, b ^= a, a ^= b;
}
int n;
int a[maxn];
//希尔排序
inline void shellSort(int lo, int hi) {
    int len = hi - lo;
    int h = 1;//增量
    while (h < len / 3)h = 3 * h + 1;//增量之间保持尽可能的互质
    while (h >= 1) {
        for (int i = lo + h; i < hi; ++i) {
            //间隔增量h做插入排序 排序之后整个序列就是h-有序的
            //如果逆序对最大距离不超过k的话,单趟插入排序复杂度为O(kn)
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                swap(a[j], a[j - h]);
            }
        }
        h /= 3;
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        shellSort(0, n);
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        puts("");
    }
}
