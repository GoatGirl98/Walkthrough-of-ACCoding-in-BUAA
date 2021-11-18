#include<stdio.h>
//#include<algorithm>
//#include<ctime>
//#include<cmath>
#define maxn 100010
FILE* in, * out;
//using namespace std;
int n, q;
int a[maxn];
int l, r;

long long result;

struct temp_with_Index {
    int number;
    int index;
}temp[maxn];

temp_with_Index dpmax[maxn][21];

void getMax(int i, int j) {
    if (dpmax[i][j - 1].number >= dpmax[i + (1 << (j - 1))][j - 1].number) {
        dpmax[i][j].number = dpmax[i][j - 1].number;
        dpmax[i][j].index = dpmax[i][j - 1].index;
    }
    else {
        dpmax[i][j].number = dpmax[i + (1 << (j - 1))][j - 1].number;
        dpmax[i][j].index = dpmax[i + (1 << (j - 1))][j - 1].index;
    }
}

int locate(int lo, int hi, int k) {
    if (dpmax[lo][k].number >= dpmax[hi - (1 << k) + 1][k].number) {
        //fprintf(stderr, "value is %d\n index is %d\n", dpmax[lo][k].number,dpmax[lo][k].index);
        return     dpmax[lo][k].index;
    }
    else {
        //fprintf(stderr, "value is %d\nindex is %d\n", dpmax[hi - (1 << k) + 1][k].number, dpmax[hi - (1 << k) + 1][k].index);
        return     dpmax[hi - (1 << k) + 1][k].index;
    }

}

void RMQ_Preorder(int n) {
    /*
    RMQ的著名算法，稀疏表模型，预处理o(nlogn)，每次查询O(1)
    可以大大缩短分治的查找时间，提升平均速率

    f[i][j]为从第i个数开始，连续2^j个数的最大值
    于是状态转移方程为:f[i][j]=max(f[i][j-1],f[i+2^(j-1)][j-1])
    首先f[i][0]就是自己，然后通过2个单元素的最值获得f[i][1]，再往后类推

    查询区间为[i][j]时，该区间长度为j-i+1，所以取k=log2(j-i+1)，然后最大值
    target=max(f[i][k],f[j-(2^k)+1][k])
    只需要查表即可，每次O(1)
    但是一旦完成建表，则不可改变。如果需要更新的话，则需要使用线段树模型
    */

    for (int i = 1; i <= n; ++i) {
        dpmax[i][0].number = temp[i].number;
        dpmax[i][0].index = temp[i].index;
        //printf("%d 0  %d %d\n", i,dpmax[i][0].number, dpmax[i][0].index);
    }

    for (int j = 1; j <= 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (i + (1 << j) - 1 <= n) {//只要j-1时还未越界就可以算j的时候
                //dpmax[i][j] = max(dpmax[i][j - 1], dpmax[i + (1 << (j - 1))][j - 1]);
                getMax(i, j);
                //printf("%d %d  %d %d\n", i, j, dpmax[i][j].number,dpmax[i][j].index);
            }
        }
    }

}

int RMQ_find(int lo, int hi) {
    int k = 0;
    while (((1 << (k + 1)) + lo) <= hi + 1)k++;
    //printf("lo,hi,k : %d %d %d\n", lo, hi, k);
    int result = locate(lo, hi, k);
    
    return result;
}




int fab(int a, int b) {
    if (a >= b)return (a - b);
    else return (b - a);
}

void divide_Triangle(int lo, int hi) {
    
    if (lo > hi) {
        //printf("get here! %d %d\n", lo, hi);
        return;
    }
    if (lo == hi) {
        //printf("get here! %d %d\n", lo, hi);
        result += temp[lo].number; return;
    }
    
    int max_index = RMQ_find(lo, hi);
    int max = temp[max_index].number;
    result += (long long)max * (long long)((long long)max_index - (long long)lo + (long long)1) * (long long)((long long)hi - (long long)max_index + (long long)1);
    //printf("get here! %d %d max index: %d\n", lo, hi,max_index);
    divide_Triangle(lo,max_index-1);
    divide_Triangle(max_index + 1, hi);
}



void write(long long x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c<'0'||c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}
int main() {
    /*
    in = freopen("testfile for BUAAOJ 281.txt", "r", stdin);
    out = freopen("output for BUAAOJ 281.txt", "w", stdout);
    clock_t startTime, endTime;
    startTime = clock();
    */
    n = read();
    q = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for (int i = 1; i < n; ++i) {
        temp[i].number = fab(a[i + 1] , a[i]);
        temp[i].index = i;
        //printf("%d ", temp[i].number);
    }
    //printf("\n");
    RMQ_Preorder(n - 1);
    while (q--) {
        l = read();
        r = read();
        result = 0;
        
        if (l > r)printf("Error Input!\n");
        else if (l == r) { putchar('0'); putchar('\n'); }
        else {
            divide_Triangle(l, r - 1);
            write(result); putchar('\n');
        }
        
    }
    /*
    endTime = clock();
    fprintf(stderr, "runTime is : %ld ms\n", (endTime - startTime));
    */

}
