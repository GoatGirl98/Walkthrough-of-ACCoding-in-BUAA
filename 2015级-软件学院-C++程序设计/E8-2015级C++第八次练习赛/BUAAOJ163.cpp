#include<cstdio>
int n, tmp, tmp2;
int main() {
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            scanf("%d", &tmp);
            int k = 0;
            tmp2 = tmp & 1;
            while (tmp2 != 1)k++, tmp2 = (tmp >> k) & 1;
            ++k;
            putchar(((tmp >> k) << k) - 1 + 'a');
        }
        putchar('\n');
    }
}
