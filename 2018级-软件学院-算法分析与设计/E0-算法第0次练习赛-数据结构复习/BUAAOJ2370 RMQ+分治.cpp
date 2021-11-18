#include<cstdio>
#define maxn 50010
#define printDivideMaxDebug 0
#define printMaxMin 0

int N;


/************************************
0.I/O优化(其实读入可以不加负数的)
************************************/

int read() {
    int k = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k*f;
}
void write(long long x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}

long long max_sum;
long long min_sum;

struct array_with_Index {
    int number;
    int index;
}a[maxn];

array_with_Index dpmax[maxn][21];
array_with_Index dpmin[maxn][21];
/************************************
1.RMQ打表
************************************/
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

void getMin(int i, int j) {
    if (dpmin[i][j - 1].number <= dpmin[i + (1 << (j - 1))][j - 1].number) {
        dpmin[i][j].number = dpmin[i][j - 1].number;
        dpmin[i][j].index = dpmin[i][j - 1].index;
    }
    else {
        dpmin[i][j].number = dpmin[i + (1 << (j - 1))][j - 1].number;
        dpmin[i][j].index = dpmin[i + (1 << (j - 1))][j - 1].index;
    }
}

void RMQ_Preorder(int n) {
    for (int i = 1; i <= n; ++i) {
        dpmax[i][0].number = dpmin[i][0].number = a[i].number;
        dpmax[i][0].index = dpmin[i][0].index = a[i].index;
    }

    for (int j = 1; j <= 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (i + (1 << j) - 1 <= n) {
                getMax(i, j); getMin(i, j);
            }
        }
    }

}

int locate_Max(int lo, int hi, int k) {
    if (dpmax[lo][k].number >= dpmax[hi - (1 << k) + 1][k].number) {
        return     dpmax[lo][k].index;
    }
    else {
        return     dpmax[hi - (1 << k) + 1][k].index;
    }
}

int locate_Min(int lo, int hi, int k) {
    if (dpmin[lo][k].number <= dpmin[hi - (1 << k) + 1][k].number) {
        return     dpmin[lo][k].index;
    }
    else {
        return     dpmin[hi - (1 << k) + 1][k].index;
    }
}

//find index
int RMQ_find_Max(int lo, int hi) {
    int k = 0;
    while (((1 << (k + 1)) + lo) <= hi + 1)k++;
    int result = locate_Max(lo, hi, k);
    return result;
}

int RMQ_find_Min(int lo, int hi) {
    int k = 0;
    while (((1 << (k + 1)) + lo) <= hi + 1)k++;
    int result = locate_Min(lo, hi, k);
    return result;
}

void RMQ_divide_Max(int lo, int hi) {
    if (printDivideMaxDebug)printf("divide max get here : %d %d\n", lo, hi);
    if (lo > hi) {
        if (printDivideMaxDebug)printf("divide max end lo > hi : %d %d\n", lo, hi);
        return;
    }
    if (lo == hi) {
        max_sum += a[lo].number;
        if (printDivideMaxDebug)printf("divide max end lo == hi : %d %d\n", lo, hi);
        return;
    }
    int max_index = RMQ_find_Max(lo, hi);
    int max = a[max_index].number;
    max_sum += (long long)max * (long long)((long long)max_index - (long long)lo + (long long)1) * (long long)((long long)hi - (long long)max_index + (long long)1);
    RMQ_divide_Max(lo, max_index - 1);
    RMQ_divide_Max(max_index + 1, hi);
    if (printDivideMaxDebug)printf("divide max end normal : %d %d\n", lo, hi);
}

void RMQ_divide_Min(int lo, int hi) {
    if (lo > hi)return;
    if (lo == hi) {
        min_sum += a[lo].number;
        return;
    }
    int min_index = RMQ_find_Min(lo, hi);
    int min = a[min_index].number;
    min_sum += (long long)min * (long long)((long long)min_index - (long long)lo + (long long)1) * (long long)((long long)hi - (long long)min_index + (long long)1);
    RMQ_divide_Min(lo, min_index - 1);
    RMQ_divide_Min(min_index + 1, hi);
}

int main() {
    N = read();
    for (int i = 1; i <= N; ++i) {
        a[i].number = read();
        a[i].index = i;
    }
    RMQ_Preorder(N);
    RMQ_divide_Max(1, N);
    RMQ_divide_Min(1, N);
    if (printMaxMin) { write(max_sum); putchar('\n'); }
    if (printMaxMin) { write(min_sum); putchar('\n'); }
    write(max_sum - min_sum);
    return 0;
}
