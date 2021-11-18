#include<cstdio>
#define maxn 200010
#define RADIX 10
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
    return k * f;
}
void write(int x) {
    if(x < 0)putchar('-'),x=-x;
    if (x >= RADIX)write(x / RADIX);
    putchar(x % RADIX + 48);
}
struct array_with_Index {
    int number;
    int index;
}a[maxn];
int N, M;
int LO, HI;
array_with_Index dpmax[maxn][21];
//array_with_Index dpmin[maxn][21];
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
void RMQ_Preorder(int n) {
    for (int i = 1; i <= n; ++i) {
        dpmax[i][0].number = a[i].number;
        dpmax[i][0].index = a[i].index;
    }

    for (int j = 1; j <= 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (i + (1 << j) - 1 <= n) {
                getMax(i, j);
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
//find index
int RMQ_find_Max(int lo, int hi) {
    int k = 0;
    while (((1 << (k + 1)) + lo) <= hi + 1)k++;
    int result = locate_Max(lo, hi, k);
    return result;
}
int main() {
    N = read();
    for (int i = 1; i <= N; ++i) {
        a[i].number = read();
        a[i].index = i;
    }
    RMQ_Preorder(N);

    M = read();
    for (int i = 1; i <= M; ++i) {
        LO = read(), HI = read();
        write(a[RMQ_find_Max(LO, HI)].number);
        putchar('\n');
    }

}
