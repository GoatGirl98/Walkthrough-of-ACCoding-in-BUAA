#include<cstdio>
int a[31];
int n;
int ans[31], Size;
int main() {
    a[0] = 1;
    for (int i = 1; i < 31; ++i)a[i] = a[i - 1] << 1;
    while (scanf("%d", &n) != EOF) {
        Size = 0;
        for (int i = 30; i >= 0; --i)
            if (n >= a[i])n -= a[i], ans[++Size] = a[i];
        for (int i = Size; i; --i)printf("%d ", ans[i]);
        putchar('\n');
    }
}
