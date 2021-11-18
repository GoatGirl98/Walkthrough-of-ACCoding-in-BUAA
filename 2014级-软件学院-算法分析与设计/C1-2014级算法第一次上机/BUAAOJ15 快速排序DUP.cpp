#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define maxn 100010
using namespace std;
//快速排序 DUP版
int a[maxn];
int n;
//从[lo,hi]当中随机选取对应的轴点mi,并且根据DUP策略调整
/**************************************
DUP针对LUG的优化主要是以下几点
优化处理多关键码雷同的退化情况
出现相等的时候,lo和hi交替移动
从LGU的勤于拓展懒于交换
变成懒于拓展勤于交换
会在交换上耗费时间,并加剧排序的不稳定性
**************************************/
inline int partition_DUP(int lo, int hi) {
    //任意选取一个元素与a[lo]交换
    swap(a[lo], a[lo + rand() % (hi - lo + 1)]);
    //以首元素作为候选节点 等价于随机选取轴点+腾出空间
    int pivot = a[lo];
    while (lo < hi) {
        while (lo < hi) {
            //大于的前提下拓展P区
            if (a[hi] > pivot)
                hi--;
            //否则将他划归到D区并停止循环
            else { a[lo++] = a[hi]; break; }
        }
        while (lo < hi) {
            //小于的前提下拓展D区
            if (a[lo] < pivot)
                lo++;
            //否则将他划归到P区并停止循环
            else { a[hi--] = a[lo]; break; }
        }
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
    int mi = partition_DUP(lo, hi - 1);
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
