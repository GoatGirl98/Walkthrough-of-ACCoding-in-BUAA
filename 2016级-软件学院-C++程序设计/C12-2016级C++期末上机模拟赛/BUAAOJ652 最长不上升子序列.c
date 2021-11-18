#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 114514
void wr(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + 48);
}
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
int a[maxn], tail[maxn];
int size;
int n;
int upper_bound(int a[], int lo, int hi, int val) {
    if (val >= a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] <= val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int main() {
    while (scanf("%d", &n) != EOF) {
        size = 1;
        memset(tail, 0, sizeof(tail));
        for (int i = 1; i <= n; ++i) a[i] = -rd();
        tail[1] = a[1];
        for (int i = 2; i <= n; ++i) {
            if (tail[size] <= a[i])tail[++size] = a[i];
            else tail[upper_bound(tail, 1, size, a[i])] = a[i];
        }
        wr(size), putchar('\n');
    }
}
