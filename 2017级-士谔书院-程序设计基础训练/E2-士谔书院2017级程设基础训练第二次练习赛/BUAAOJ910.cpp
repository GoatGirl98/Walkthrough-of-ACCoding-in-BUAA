#include <iostream>
#include <algorithm>
#define INF 1000010
using namespace std;

//分治策略的应用，多路归并

int a[INF], b[INF];

long long result;

void merge(int lo, int hi) {

    if (hi > lo) {

        int mi = (hi + lo) >> 1;

        merge(lo, mi);
        merge(mi + 1, hi);
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
            if ((a[lomark] <= a[himark] || himark > hi) && lomark <= mi) {

                b[bmark++] = a[lomark++];

            }
            else {
                b[bmark++] = a[himark++];//此时需要统计逆序的问题，子问题合并排序完之后就方便多了

                result += mi - lomark + 1;//表示的是左边的数组有多少个比他大的
            }

        }

        for (int i = lo; i <= hi; i++) {
            a[i] = b[i];
        }

    }



    return;
}


int main(void)
{
    ios::sync_with_stdio(false);

    int T;

    int n;

    cin >> T;

    while (T--) {

        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        result = 0;
        merge(0, n - 1);

        cout << result << endl;

    }

    return 0;
}
