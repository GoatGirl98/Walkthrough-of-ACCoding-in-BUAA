#include<cstdio>
#include<list>
#include<algorithm>
#define maxn 100010
using namespace std;
typedef list<int>::iterator IT;
int a[maxn];
int cnt;
int MaxNum, MinNum;
int maxa, maxb;
//基数排序的底层采用桶排实现,包括不同位的数字大小和正负的关键值
list<int> NumBucket[10];
list<int> isPosBucket[2];//0是负 1是正
int radixSortRound;
inline int SelectNum(int target, int pos) {
    //选择某个数的第pos位进行排序 个位是0
    if (target < 0)target = -target;
    int divNum = 1;
    for (int i = 0; i < pos; ++i)divNum = (divNum << 1) + (divNum << 3);
    return (target % ((divNum << 1) + (divNum << 3))) / divNum;
}
inline int SelectisPos(int target) {
    return target >= 0;
}
inline void radixSort(int lo, int hi) {
    MaxNum = -(1 << 30), MinNum = 1 << 30;
    for (int i = lo; i < hi; ++i) {
        if (a[i] > MaxNum) MaxNum = a[i];
        if (a[i] < MinNum) MinNum = a[i];
    }
    maxa = maxb = 0;
    while (MaxNum)MaxNum /= 10, maxa++;
    while (MinNum)MinNum /= 10, maxb++;
    radixSortRound = max(maxa, maxb);
    for (int i = 0; i < radixSortRound; ++i) {
        for (int j = lo; j < hi; ++j)
            NumBucket[SelectNum(a[j], i)].push_back(a[j]);
        cnt = lo;
        for (int j = 0; j < 10; ++j)
            while (!NumBucket[j].empty())
                a[cnt++] = NumBucket[j].front(), NumBucket[j].pop_front();
    }
    cnt = lo;
    for (int i = lo; i < hi; ++i)
        isPosBucket[SelectisPos(a[i])].push_back(a[i]);
    while (!isPosBucket[0].empty())
        a[cnt++] = isPosBucket[0].back(), isPosBucket[0].pop_back();
    while (!isPosBucket[1].empty())
        a[cnt++] = isPosBucket[1].front(), isPosBucket[1].pop_front();
}
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        radixSort(0, n);
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        puts("");
    }
}
