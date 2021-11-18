#include <stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
typedef __uint128_t ulll;
ulll rd()
{
    ulll k = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return k;
}
void wr(ulll x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
ulll t;
ulll a, b, p;
int main() {
    t = rd();
    while(t--) {
        a = rd(), b = rd(), p = rd();
        wr((a * b) % p), putchar('\n');
    }
}
