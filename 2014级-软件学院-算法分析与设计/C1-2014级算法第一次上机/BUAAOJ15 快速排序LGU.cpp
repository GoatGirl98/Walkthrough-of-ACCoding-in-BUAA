#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define maxn 100010
using namespace std;
//快速排序 LGU版
int a[maxn];
int n;
//从[lo,hi]当中随机选取对应的轴点mi,并且根据LGU策略调整
/**************************************
LGU策略十分像冒泡排序的那种
先让目标轴点处在lo不变
然后往后看,只要是小于目标轴点的
都swap到轴点右侧的L序列
否则保留在G序列不动
最终L序列的末尾一定就是轴点该在的位置
swap a[lo]与a[mi]即可
在时间复杂度上改变不大
很显然，无法解决LUG在雷同关键码上的问题
**************************************/
inline int partition_LGU(int lo, int hi) {
    //任意选取一个元素与a[lo]交换
    swap(a[lo], a[lo + rand() % (hi - lo + 1)]);
    //以首元素作为候选节点 等价于随机选取轴点+腾出空间
    int pivot = a[lo];
    int mi = lo;
    for (int k = lo + 1; k <= hi; ++k)
        if (a[k] < pivot)
            swap(a[++mi], a[k]);
    swap(a[lo], a[mi]);
    return mi;
}
inline void quickSort(int lo, int hi) {
    //退化情况:单元素的区间必然有序 直接返回
    if (hi - lo < 2)return;
    //外部接口是左闭右开的,但是划分需要传入的是闭区间
    //划分的元素保证排序前和排序后所处位置一直,解决2个子问题之后直接停机
    int mi = partition_LGU(lo, hi - 1);
    quickSort(lo, mi);
    quickSort(mi + 1, hi);
}
FILE* in;
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
