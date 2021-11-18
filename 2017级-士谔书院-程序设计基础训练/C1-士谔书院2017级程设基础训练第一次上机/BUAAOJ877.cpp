#include<cstdio>
int a[9];
int main() {
    for (int i = 0; i < 8; ++i) {
        a[i] = getchar() - 48;
    }
    a[8] = (a[0] * 9 + a[1] * 8 + a[2] * 7 + a[3] * 6 + a[4] * 5 + a[5] * 4 + a[6] * 3 + a[7] * 2) % 10;
    printf("%d%d%d%d%d%d%d%d%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
}
