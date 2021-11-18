#pragma G++ optimize(2)
#include<cstdio>
#include<algorithm>
#define print 0
#define maxn 1000010
using namespace std;
int n;
int a[maxn];
inline int partitionSort(int lo, int hi) {
    if (lo > hi)return lo;
    int mi = a[(lo + hi + 1) >> 1];
    while (lo <= hi) {
        while (a[lo] < mi)++lo;
        while (a[hi] > mi)--hi;
        if (lo <= hi) {
            swap(a[lo], a[hi]);
            ++lo, --hi;
        }
    }
    return lo;
}
inline int read() {
    int k = 0; int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}

int main() {
    n = read();
    for (int i = 0; i < n; ++i) a[i] = read();
    int i = partitionSort(0, n - 1);
    int j = partitionSort(0, i - 1);
    int k = partitionSort(i, n - 1);
    for (int q = j; q <= i - 1; ++q)printf("%d ", a[q]);
}
