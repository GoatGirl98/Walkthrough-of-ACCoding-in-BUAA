#include <cstdio>
bool get7(long long num) {
    while (num) {
        if (num % 10 == 7)return true;
        num /= 10;
    }
    return false;
}
int main() {
    int n, i; long long beg, j;
    scanf("%d%d%lld", &n, &i, &beg);
    for (j = i - 1;; j += n) {
        if (((beg + j) % 7 == 0 || get7(beg + j)))break;
    }
    printf("%lld", beg + j);
}