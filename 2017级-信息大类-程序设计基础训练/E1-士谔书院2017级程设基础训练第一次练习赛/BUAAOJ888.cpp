#include<cstdio>
#include<cmath>
int m, n;
int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        if (n < 2 * m || 4 * m < n) { printf("Wrong number\n"); continue; }
        if((4*m-n)%2) { printf("Wrong number\n"); continue; }
        printf("%d %d\n", (4 * m - n) / 2, (n - 2 * m) / 2);
    }
}
