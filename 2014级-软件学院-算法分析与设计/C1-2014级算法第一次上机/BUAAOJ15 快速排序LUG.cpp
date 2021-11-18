#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define maxn 100010
using namespace std;
//快速排序 LUG版
int a[maxn];
int n;
//从[lo,hi]当中随机选取对应的轴点mi,并且根据LUG策略调整
inline int partition_LUG(int lo, int hi) {
    //任意选取一个元素与a[lo]交换
    swap(a[lo], a[lo + rand() % (hi - lo + 1)]);
    //以首元素作为候选节点 等价于随机选取轴点+腾出空间
    int pivot = a[lo];
    while (lo < hi) {
        //大于等于轴点的从U区划分至G区
        while ((lo < hi) && (a[hi] >= pivot))
            hi--;
        //发现小于的,划归至L区
        a[lo] = a[hi];
        //小于等于轴点的从U区划分至L区
        while ((lo < hi) && (a[lo] <= pivot))
            lo++;
        //发现大于的,划归至G区
        a[hi] = a[lo];
    }
    //出来的时候 lo==hi U区的唯一元素就是培养完成的节点该在的位置了
    a[lo] = pivot;
    return lo;
}
inline void quickSort(int lo, int hi) {
    //退化情况:单元素的区间必然有序 直接返回
    if (hi - lo < 2)return;
    //外部接口是左闭右开的,但是划分需要传入的是闭区间
    //划分的元素保证排序前和排序后所处位置一直,解决2个子问题之后直接停机
    int mi = partition_LUG(lo, hi - 1);
    quickSort(lo, mi);
    quickSort(mi + 1, hi);
}
int main() {
    srand((int)time(NULL));
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        quickSort(0, n);
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        puts("");
    }
}
