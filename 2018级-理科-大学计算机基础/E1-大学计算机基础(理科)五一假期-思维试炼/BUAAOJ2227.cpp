#pragma GCC optimize(2)
#include<cstdio>
#define maxn 100010
#define Min(a,b) (((a)<(b))?(a):(b))
int res;
int n;

int main() {

    scanf("%d", &n);
    printf("%d\n", n * 3 / 2);
    if (!(n & 1)) {
        for (int i = 1; i <= n - 1; i += 2)printf("%d ", n - i);
        for (int i = 2; i <= n; i += 2)printf("%d ", i);
        for (int i = 1; i <= n - 1; i += 2)printf("%d ", n - i);
    }
    else {
        for (int i = 2; i <= n - 1; i += 2)printf("%d ", i);
        for (int i = 1; i <= n; i += 2)printf("%d ", i);
        for (int i = 2; i <= n - 1; i += 2)printf("%d ", i);
    }

}
