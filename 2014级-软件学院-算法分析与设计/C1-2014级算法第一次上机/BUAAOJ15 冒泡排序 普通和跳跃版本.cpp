#include<cstdio>
#define maxn 100010
inline void swap(int& a, int& b) {
    a ^= b, b ^= a, a ^= b;
}
//包含简单冒泡排序和提前终止冒泡排序
int a[maxn];
inline void bubbleSort(int lo, int hi) {
    bool sorted = false;//利用排序标志提前终止
    while (!sorted) {
        sorted = true;
        for (int i = lo + 1; i < hi; ++i) {
            if (a[i - 1] > a[i])
                swap(a[i - 1], a[i]), sorted = false;
        }
        hi--;
    }
}
inline void bubbleSort_jump(int lo, int hi) {
    for (int last = --hi; lo < hi; hi = last) {
        for (int i = last = lo; i < hi; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                last = i;//只可能从[lo,last)开始无序
            }
        }
    }
}
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        bubbleSort(0, n);
        //bubbleSort_jump(0, n);
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        puts("");
    }
}
