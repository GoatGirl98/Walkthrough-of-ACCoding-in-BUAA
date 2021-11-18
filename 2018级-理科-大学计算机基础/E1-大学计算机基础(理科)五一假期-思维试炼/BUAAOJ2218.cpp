#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cmath>
#define maxn 100010
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int res;
int n, m, k,kk;
int op[maxn], num[maxn], color[maxn];
int lala[maxn];
int hangMark[maxn],lieMark[maxn];

void write(int x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
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
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    n = read(), m = read(), k = read();
    kk = k;
    while (k--) {
        op[k] = read(), num[k] = read(), color[k] = read();
    }
    for (int i = 0; i < kk; ++i) {
        if (op[i] == 1 && !hangMark[num[i]]) {
            hangMark[num[i]] = 1;
            int a = (num[i] - 1) * m;
            for (int j = 1; j <= m; ++j) {
                if (!lieMark[j])lala[a + j] = color[i];
            }
        }
        else if (op[i] == 2 && !lieMark[num[i]]) {
            lieMark[num[i]] = 1;
            for (int j = 1; j <= n; ++j) {
                if (!hangMark[j])lala[(j - 1) * m + num[i]] = color[i];
            }
        }
    }
    int counter = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            write(lala[counter++]); putchar(' ');
        }
        putchar('\n');
    }
}
