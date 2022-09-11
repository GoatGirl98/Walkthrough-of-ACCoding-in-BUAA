#include <cstdio>

int reverse(int n) {
    int k=0;
    int temp = n;
    while (temp != 0) {
        k = (k << 1) + (k << 3) + temp % 10;
        temp /= 10;
    }
    return k;
}
int a, b;
int main() {
    while (scanf("%d%d", &a, &b) != EOF) {
        a = reverse(a); b = reverse(b);
        printf("%d\n", a * b);
    }

}
