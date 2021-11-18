#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1000010
int n;
int a[maxn];
//堆排序 按照大根堆进行调整
inline void perlocate_down(int lo, int hi) {
    //下滤操作,堆区间为[lo,hi] lo为堆的根
    int dad = lo;
    int son = (dad << 1) + 1;
    while (son <= hi) {
        if (son + 1 <= hi && a[son] < a[son + 1])
            son++;//如果存在双分支,选择其中较大者进行下滤
        if (a[dad] > a[son])break;//此时如果堆序性正确,则整个堆都正确,直接停机
        else {
            swap(a[dad], a[son]);
            dad = son, son = (dad << 1) + 1;
            //调整,并且根据下滤的节点继续往下看
        }
    }
}
inline void heap_sort(int lo, int hi) {
    //数组的[lo,hi)当做堆进行排序
    //step1: floyd建堆 自下而上地子堆下滤 复杂度O(n)
    for (int i = ((hi - lo) >> 1) - 1; i >= lo; --i)
        perlocate_down(i, hi - lo - 1);
    //step2: 建堆之后,每次将a[0](即整个堆的最大值)挪到最后 剩余元素做堆下滤调整
    //最快最慢平均复杂度均为O(nlogn) 是就地排序 不稳定排序
    for (int i = (hi - lo - 1); i > 0; --i) {
        swap(a[0], a[i]);
        perlocate_down(lo, i - 1);
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        heap_sort(0, n);
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        puts("");
    }
}
