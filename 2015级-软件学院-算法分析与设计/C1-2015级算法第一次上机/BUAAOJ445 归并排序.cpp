#pragma G++ optimize(2)
#include<iostream>
#include<algorithm>
#define maxn 10010
#define print 0
using namespace std;
int all[maxn];
int oper[maxn];
int temp[maxn];
int res;
void merge(int lo, int hi, int *N) {
    if (hi > lo) {
        int mi = (hi + lo) >> 1;
        merge(lo, mi, N);
        merge(mi + 1, hi, N);
        //分而治之，一分为二
        /*
        在进行合并时候的策略即为：观察左右两个部分，对每一个左边序列的i，右边序列比他大的有多少，需要再加
        */
        //此处做下标，因为这里左边的数组要和右边的数组做比较
        int bmark = lo;
        int lomark = lo;
        int himark = mi + 1;
        while (lomark <= mi || himark <= hi) {
            //此处做累加与左右的比较，等到两边都到头了才算完事

            //然而在具体实现的时候，还是最好在归并的同时进行排序，并通过比较出来得出逆序，一点点累加上去

            /*
            举一个例子：6,202,100,301,38,8,1，在最后两组的比较当中，应该是6,100，202,301和1,8,38进行比较
            然后加上这个里面的左右的逆序数，如此累加得到结果

            往下分的时候亦是如此

            */
            //b数组作为缓存，就是用来储存合并排序的中间结果，并返还给原数组的
            if ((N[lomark] <= N[himark] || himark > hi) && lomark <= mi) {

                temp[bmark++] = N[lomark++];

            }
            else {
                temp[bmark++] = N[himark++];//此时需要统计逆序的问题，子问题合并排序完之后就方便多了

                res += mi - lomark + 1;//表示的是左边的数组有多少个比他大的
            }

        }
        for (int i = lo; i <= hi; i++) {
            N[i] = temp[i];
        }
    }
    return;
}
int n, m;
int l, r;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; ++i)cin >> all[i];
        cin >> m;
        while (m--) {
            cin >> l >> r;
            for (int i = l; i <= r; ++i) {
                oper[i - l] = all[i];
                if(print)cout << all[i - l] << " ";
            }
            if (print)cout << endl;
            res = 0;
            merge(0, r - l, oper);
            cout << res << endl;
        }
    }
}
