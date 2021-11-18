#include<cstdio>
#define maxn 100010
inline void swap(int& a, int& b) {
    a ^= b, b ^= a, a ^= b;
}
int a[maxn];
//选择排序模板
inline void selectionSort(int lo, int hi) {
    for (int i = lo; i < hi - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < hi; ++j) {
            if (a[minIndex] > a[j]) minIndex = j;
        }
        if (minIndex != i)swap(a[i], a[minIndex]);
    }
}
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        selectionSort(0, n);
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        puts("");
    }
}
