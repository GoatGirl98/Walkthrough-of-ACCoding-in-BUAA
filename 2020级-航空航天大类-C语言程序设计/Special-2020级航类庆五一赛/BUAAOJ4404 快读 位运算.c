#include<stdio.h>
unsigned tmpint;
unsigned n;
unsigned ans;
unsigned rd() {
    unsigned k = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return k;
}
void wr(unsigned x) {
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    n = rd();
    n <<= 1, --n;
    while(n--) {
        tmpint = rd();
        ans ^= tmpint;
    }
    wr(ans);
}